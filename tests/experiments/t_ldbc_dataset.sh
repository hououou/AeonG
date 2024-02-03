#!/bin/bash
update_num=$1 #320000
clockg_binary=$2 #/home/hjm/vldb/clockg/build/memgraph
memgraph_binary=$3 #/home/hjm/vldb/memgraph-master/build/memgraph

function print_help () {
    echo "Usage: $0 [OPTION]"
    echo "Optional arguments:"
    echo -e "  -h|--help -> Prints help."
    echo -e "  --scale-factor Positive_Integer -> Defines the dataset size."
}

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="${script_dir}/../.."
build_dir="${base_dir}/build"
scripts_dir="${base_dir}/test/scripts" # scripts directory for test
dataset_root="${script_dir}/tests/datasets/T-LDBC"
database_root="${script_dir}/tests/results/database/T-LDBC"
cd build_dir/tools/src
make

# download original ldbc dataset
cd $dataset_root/original_csv
wget --no-check-certificate https://repository.surfsara.nl/datasets/cwi/snb/files/social_network-csv_basic/social_network-csv_basic-sf${scale_factor}.tar.zst
zstd -d social_network-csv_basic-sf${scale_factor}.tar.zst
tar -xf social_network-csv_basic-sf${scale_factor}.tar

dataset_dir="${dataset_root}/original_csv/social_network-csv_basic-sf${scale_factor}"
csv_dataset="
--nodes ${dataset_dir}/dynamic/comment_0_0.csv \
--nodes ${dataset_dir}/dynamic/forum_0_0.csv \
--nodes ${dataset_dir}/static/organisation_0_0.csv \
--nodes ${dataset_dir}/dynamic/person_0_0.csv \
--nodes ${dataset_dir}/static/place_0_0.csv \
--nodes ${dataset_dir}/dynamic/post_0_0.csv \
--nodes ${dataset_dir}/static/tag_0_0.csv \
--nodes ${dataset_dir}/static/tagclass_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_hasCreator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_replyOf_comment_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_replyOf_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_containerOf_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasMember_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasModerator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/static/organisation_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_hasInterest_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_knows_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_likes_comment_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_likes_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_studyAt_organisation_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_workAt_organisation_0_0.csv \
--relationships ${dataset_dir}/static/place_isPartOf_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_hasCreator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/static/tag_hasType_tagclass_0_0.csv \
--relationships ${dataset_dir}/static/tagclass_isSubclassOf_tagclass_0_0.csv"

memgraph_snapshot_dir=${database_root}/aeong/sf${scale_factor}
mkdir -p ${memgraph_snapshot_dir}
cd ${memgraph_snapshot_dir}
echo "Converting CSV dataset to '${memgraph_snapshot_dir}'"
${build_dir}/tools/src/mg_import_csv --data-directory memgraph ${csv_dataset} --csv-delimiter "|" --array-delimiter ";"
echo "Finish building!"

# convert to ldbc-clockg dataset
clockg_dir=${database_root}/clockg
mkdir -p ${clockg_dir}
cp -r ${memgraph_snapshot_dir} ${clockg_dir}/

# convert to ldbc-tgql dataset
cd $script_dir
tgql_script="${script_dir}/get_ldbc_tgql_dataset.py"
csv_path="--ldbc-csv-path $dataset_dir"
TGQL_cypher_file_path="--TGQL-cypher-file-path $dataset_dir/tgql/"
output=$(python3 "$tgql_script" $csv_path $TGQL_cypher_file_path)

# TODO: build origin tgql database using create_temporal_database
tgql_dir=${database_root}/tgql
mkdir -p ${tgql_dir}

tgql_db_script="${scripts_dir}/create_temporal_database.py"
memg_binary="--aeong-binary $memgraph_binary"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 1"
db_dir="--data-directory $tgql_dir/sf${scale_factor}"
mkdir -p ${db_dir}
tgql_dataset_path="--original-dataset-cypher-path $dataset_dir/tgql/"
index_path="--index-cypher-path $dataset_root/TGQL_index.cypher"
benchmark_type="--benchmark-type ldbc"
binary_type="--binary-type tgql"
load_type="--load-cypher-flag 1"
output=$(python3 "$tgql_db_script" $memg_binary $client_binary $db_dir $tgql_dataset_path $number_workers $index_path $benchmark_type $binary_type $load_type)

#create graph operation
#echo "Create graph operation query statements"
prefix_path="$base_dir/tests/results/"
graph_op_path="$prefix_path/T-LDBC/graph_op/sf$scale_factor"
rm -rf "$graph_op_path"
mkdir -p "$graph_op_path"
update_num_arg="--num-op $update_num"
write_path="--write-path $prefix_path"
dataset_path="--dataset-path ${dataset_dir}/dynamic/"
python_script="$base_dir/tests/benchmarks/T-LDBC/create_graph_op_queries.py"
output=$(python3 "$python_script" $update_num_arg $dataset_path $write_path)

#Create AeonG temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 1"
database_directory="--data-directory ${database_root}/aeong/sf${scale_factor}"
index_path="--index-cypher-path $dataset_root/cypher_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
benchmark_type="--benchmark-type ldbc"
python_script="${scripts_dir}/create_temporal_database.py"
echo "=============AeonG create database, it cost time==========="
output=$(python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $graph_op_cypher_path $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============AeonG graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create ClockG temporal database, get graph operation latency, and get space"
aeong_binary="--aeong-binary $clockg_binary"
clockg_snapshot="--clockg-snapshot 80000"
database_directory="--data-directory $database_root/clockg/sf${scale_factor}"
binary_type="--binary-type clockg"
python_script="${scripts_dir}/create_temporal_database.py"
echo "=============Clock-G create database, it cost time==========="
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $clockg_snapshot $number_workers $database_directory $index_path $graph_op_cypher_path $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============Clock-G graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create TGQL temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary $memgraph_binary"
database_directory="--data-directory $database_root/tgql/sf${scale_factor}"
index_path="--index-cypher-path $dataset_root/TGQL_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
binary_type="--binary-type tgql"
python_script="${scripts_dir}/create_temporal_database.py"
echo "=============T-GQL create database, it cost time==========="
python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $index_path
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $database_directory $index_path $graph_op_cypher_path $binary_type $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============T-GQL graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

# Evaluation on T-LDBC
echo "=============Various temporal query performance==========="
prefix_path="$base_dir/tests/results/"
op_num="--num-op $update_num"
min_time="--min-time 90791306"
max_time="--max-time 92732774"
frequency_type="--frequency-type mix"
write_path="--write-path $prefix_path/T-LDBC"
temporal_query_path=“$prefix_path/T-LDBC/temporal_query”
rm -rf temporal_query_path
mkdir -p temporal_query_path
python_script="$base_dir/tests/benchmarks/T-LDBC/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)

aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 1"
database_directory="--data-directory ${database_root}/aeong/sf${scale_factor}"
index_path="--index-cypher-path $dataset_root/cypher_index.cypher"
python_script="${scripts_dir}/evaluate_temporal_q.py"
temporal_q1="--temporal-query-cypher-path $temporal_query_path/IS1_cypher.txt"
temporal_q2="--temporal-query-cypher-path $temporal_query_path/IS2_cypher.txt"
temporal_q3="--temporal-query-cypher-path $temporal_query_path/IS3_cypher.txt"
temporal_q4="--temporal-query-cypher-path $temporal_query_path/IS4_cypher.txt"
temporal_q5="--temporal-query-cypher-path $temporal_query_path/IS5_cypher.txt"
temporal_q6="--temporal-query-cypher-path $temporal_query_path/IS6_cypher.txt"
temporal_q7="--temporal-query-cypher-path $temporal_query_path/IS7_cypher.txt"

echo "AeonG q1 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "AeonG q2 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q2
echo "AeonG q3 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "AeonG q4 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "AeonG q5 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "AeonG q6 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q6
echo "AeonG q7 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7

#  echo "Evaluate Clock-G temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $clockg_binary"
binary_type="--binary-type clockg"
echo "Clock-G q1 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "Clock-G q2 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q2
echo "Clock-G q3 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "Clock-G q4 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "Clock-G q5 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "Clock-G q6 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q6
echo "Clock-G q7 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7

#  echo "Evaluate T-GQL temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $memgraph_binary"
min_time="--min-time $start_time"
max_time="--max-time $end_time"
python_script="$base_dir/tests/benchmarks/T-LDBC/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)
temporal_q1="--temporal-query-cypher-path $temporal_query_path/IS1_TGQL_cypher.txt"
temporal_q2="--temporal-query-cypher-path $temporal_query_path/IS2_TGQL_cypher.txt"
temporal_q3="--temporal-query-cypher-path $temporal_query_path/IS3_TGQL_cypher.txt"
temporal_q4="--temporal-query-cypher-path $temporal_query_path/IS4_TGQL_cypher.txt"
temporal_q5="--temporal-query-cypher-path $temporal_query_path/IS5_TGQL_cypher.txt"
temporal_q6="--temporal-query-cypher-path $temporal_query_path/IS6_TGQL_cypher.txt"
temporal_q7="--temporal-query-cypher-path $temporal_query_path/IS7_TGQL_cypher.txt"
echo "T-GQL q1 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "T-GQL q2 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q2
echo "T-GQL q3 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "T-GQL q4 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "T-GQL q5 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "T-GQL q6 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q6
echo "T-GQL q7 mix"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7