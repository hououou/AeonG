#!/bin/bash
update_num=1000000
clockg_binary=$1 #/home/hjm/vldb/clockg/build/memgraph
memgraph_binary=$2 #/home/hjm/vldb/memgraph-master/build/memgraph
scale_factor=1

function print_help () {
    echo "Usage: $0 [OPTION]"
    echo "Optional arguments:"
    echo -e "  -h|--help -> Prints help."
    echo -e "  --scale-factor Positive_Integer -> Defines the dataset size."
}

temp_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="${temp_dir}/../.."
build_dir="${base_dir}/build"
scripts_dir="${base_dir}/tests/scripts" # scripts directory for test
dataset_root="${base_dir}/tests/datasets/T-LDBC"
database_root="${base_dir}/tests/results/database"
aeong_database_root="${database_root}/ldbc/aeong"
clockg_database_root="${database_root}/ldbc/clokg"
tgql_database_root="${database_root}/ldbc/tgql"
mkdir -p $dataset_root
mkdir -p $aeong_database_root
mkdir -p $clockg_database_root
mkdir -p $tgql_database_root

# download original ldbc dataset and cypher query
cd $dataset_root
wget --no-check-certificate https://repository.surfsara.nl/datasets/cwi/snb/files/social_network-csv_basic/social_network-csv_basic-sf${scale_factor}.tar.zst
zstd -d social_network-csv_basic-sf${scale_factor}.tar.zst
tar -xf social_network-csv_basic-sf${scale_factor}.tar
rm -rf social_network-csv_basic-sf${scale_factor}.tar.zst
rm -rf social_network-csv_basic-sf${scale_factor}.tar
mv social_network-csv_basic-sf${scale_factor} original_csv

#download cypher
wget --no-check-certificate https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/ldbc/benchmark/interactive/ldbc_interactive_sf${scale_factor}.cypher.gz
gzip -d ldbc_interactive_sf${scale_factor}.cypher.gz
mv ldbc_interactive_sf${scale_factor}.cypher ldbc.cypher

# convert to ldbc-tgql dataset
tgql_script="${base_dir}/tests/experiments/get_ldbc_tqgl_dataset.py"
csv_path="--ldbc-csv-path $dataset_root/original_csv"
TGQL_cypher_file_path="--TGQL-cypher-file-path $dataset_root/tgql/"
mkdir -p $dataset_root/tgql/edges
output=$(python3 $tgql_script $csv_path $TGQL_cypher_file_path)

#create graph operation
echo "Create graph operation query statements"
prefix_path="$base_dir/tests/results/T-LDBC/"
graph_op_path="${prefix_path}graph_op/"
peak_vertices_path="${prefix_path}peak_vertices/"
echo $graph_op_path
rm -rf $graph_op_path
mkdir -p $graph_op_path
rm -rf $peak_vertices_path
mkdir -p $peak_vertices_path
update_num_arg="--num-op $update_num"
write_path="--write-path $prefix_path"
dataset_path="--ldbc-dataset-path ${dataset_root}/original_csv/"
python_script="$base_dir/tests/benchmarks/T-LDBC/create_graph_op_queries.py"
output=$(python3 $python_script $update_num_arg $dataset_path $write_path)

#Create AeonG temporal database, get graph operation latency, and get space
cd $scripts_dir
rm -rf $aeong_database_root
aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 20"
database_directory="--data-directory $aeong_database_root"
original_dataset_path="--original-dataset-cypher-path $dataset_root/ldbc.cypher"
index_path="--index-cypher-path $dataset_root/ldbc_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
python_script="../scripts/create_temporal_database.py"
echo "=============AeonG create database, it cost time==========="
output=$(python3 $python_script $aeong_binary $client_binary $original_dataset_path $number_workers $database_directory $index_path $graph_op_cypher_path $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============AeonG graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create ClockG temporal database, get graph operation latency, and get space"
aeong_binary="--aeong-binary ${build_dir}/memgraph"
clockg_snapshot="--clockg-snapshot 250"
database_directory="--data-directory $clockg_database_root"
rm -rf $clockg_database_root
graph_op_cypher_path="--graph-operation-cypher-path $dataset_root/ldbc_index.cypher"
output=$(python3 $python_script $aeong_binary $client_binary $original_dataset_path $clockg_snapshot $number_workers $database_directory $index_path $graph_op_cypher_path)
binary_type="--binary-type clockg"
python_script="${scripts_dir}/create_temporal_database.py"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
echo "=============Clock-G create database, it cost time==========="
aeong_binary="--aeong-binary $clockg_binary"
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $original_dataset_path $clockg_snapshot $number_workers $database_directory $index_path $graph_op_cypher_path)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============Clock-G graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create TGQL temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary $memgraph_binary"
database_directory="--data-directory $tgql_database_root"
rm -rf $tgql_database_root
index_path="--index-cypher-path $dataset_root/ldbc_tgql_index.cypher"
original_dataset_path="--original-dataset-cypher-path $dataset_root/tgql"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
binary_type="--binary-type tgql"
load_tgql_type="--load-tgql-flag 1"
benchamrk_type="--benchmark-type ldbc"
python_script="${scripts_dir}/create_temporal_database.py"
echo "=============T-GQL create database, it cost time==========="
python3 $python_script $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $index_path $load_tgql_type $benchamrk_type $original_dataset_path
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============T-GQL graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"


echo "=============Various temporal query performance==========="
prefix_path="$base_dir/tests/results/"
op_num="--num-op $update_num"
min_time="--min-time 90791306"
max_time="--max-time 92732774"
write_path="--write-path $prefix_path/T-LDBC/"
temporal_query_path="${prefix_path}T-LDBC/temporal_query"
echo $temporal_query_path
rm -rf $temporal_query_path
mkdir -p $temporal_query_path
python_script="$base_dir/tests/benchmarks/T-LDBC/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $write_path)

aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 20"
database_directory="--data-directory $aeong_database_root"
index_path="--index-cypher-path $dataset_root/ldbc_index.cypher"
python_script="${scripts_dir}/evaluate_temporal_q.py"
temporal_q1="--temporal-query-cypher-path $temporal_query_path/IS1_cypher.txt"
temporal_q3="--temporal-query-cypher-path $temporal_query_path/IS3_cypher.txt"
temporal_q4="--temporal-query-cypher-path $temporal_query_path/IS4_cypher.txt"
temporal_q5="--temporal-query-cypher-path $temporal_query_path/IS5_cypher.txt"
temporal_q7="--temporal-query-cypher-path $temporal_query_path/IS7_cypher.txt"

echo "AeonG q1 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "AeonG q3 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "AeonG q4 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "AeonG q5 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "AeonG q7 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7

echo "Evaluate Clock-G temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $clockg_binary"
binary_type="--binary-type clockg"
echo "Clock-G q1 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "Clock-G q3 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "Clock-G q4 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "Clock-G q5 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "Clock-G q7 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7

echo "Evaluate T-GQL temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $memgraph_binary"
min_time="--min-time $start_time"
max_time="--max-time $end_time"
python_script="$base_dir/tests/benchmarks/T-LDBC/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $write_path)
temporal_q1="--temporal-query-cypher-path $temporal_query_path/IS1_TGQL_cypher.txt"
temporal_q3="--temporal-query-cypher-path $temporal_query_path/IS3_TGQL_cypher.txt"
temporal_q4="--temporal-query-cypher-path $temporal_query_path/IS4_TGQL_cypher.txt"
temporal_q5="--temporal-query-cypher-path $temporal_query_path/IS5_TGQL_cypher.txt"
temporal_q7="--temporal-query-cypher-path $temporal_query_path/IS7_TGQL_cypher.txt"
echo "T-GQL q1 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
echo "T-GQL q3 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
echo "T-GQL q4 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4
echo "T-GQL q5 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q5
echo "T-GQL q7 "
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q7