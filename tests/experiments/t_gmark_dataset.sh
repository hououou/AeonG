#!/bin/bash

temp_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="${temp_dir}/../.."
build_dir="${base_dir}/build"
test_dir="${base_dir}/tests"
dataset_root="${test_dir}/datasets/T-gMark"
result_dir="$test_dir/results"
gmark_dir="$test_dir/gmark"
database_root="$test_dir/results/database"
aeong_database_root="${database_root}/gmark/aeong"
clockg_database_root="${database_root}/gmark/clokg"
tgql_database_root="${database_root}/gmark/tgql"
mkdir -p $dataset_root
mkdir -p $aeong_database_root
mkdir -p $clockg_database_root
mkdir -p $tgql_database_root

cd $test_dir
git clone https://github.com/gbagan/gmark.git

update_num=320000
nodes=$1
type=$2
clockg_binary=$2 #/home/hjm/vldb/clockg/build/memgraph
memgraph_binary=$3 #/home/hjm/vldb/memgraph-master/build/memgraph

echo $nodes
num=$[nodes/1000]
echo $num
echo $type
config_name=$type
if [ "$type" = "social" ]; then
  config_name="social-network-ratio"
fi


graph_dir="${gmark_dir}/demo/${type}-a-${num}k"
# save_dir="/data/hjm/gMark/datasets/social-LDBC/"
save_dir="$dataset_root/"
echo ${graph_dir}
if [ -d "$graph_dir" ]; then
  # 如果目标文件夹存在，则删除
  echo "remove $graph_dir"
  rm -rf "$graph_dir"
fi

mkdir -p ${graph_dir}
cd ${gmark_dir}/src
# ./test -c ../use-cases/${config_name}.xml -g ${graph_dir}/${type}-a-graph.txt -w ${graph_dir}/${type}-a-workload.xml -r ${graph_dir}/ -a -n ${nodes}
# mv ${graph_dir}/${type}-a-graph.txt0.txt ${graph_dir}/${type}-a-graph.txt

# test-a-version bib
./test -c ../use-cases/${config_name}.xml -g ${graph_dir}/${type}-a-graph.txt -w ${graph_dir}/${type}-a-workload.xml -r ${graph_dir}/ -a -n ${nodes}
mv ${graph_dir}/${type}-a-graph.txt0.txt ${graph_dir}/${type}-a-graph.txt

cd querytranslate
echo ${graph_dir}/query
mkdir -p ${graph_dir}/query
./test -w ${graph_dir}/${type}-a-workload.xml -o ${graph_dir}/query
find ${graph_dir}/query -type f \( -name "*.lb" -o -name "*.sql" -o -name "*.sparql" \) -delete

mv ${graph_dir} ${save_dir}/

# generate to gMark dataset and original workload
cd $temp_dir
python_script="${scripts_dir}/get_gmark_dataset.py"
args_1="--directory $save_dir/${type}-a-${num}k"
args_2="--dbtype $type"
args_3="--number $num"
output=$(python3 "$python_script" $args_1 $args_2 $args_3)

# generate the original T-gMark database

gmark_dataset="
--nodes ${save_dir}/${type}-a-${num}k/${type}-a-nodes.csv \
--relationships ${save_dir}/${type}-a-${num}k/${type}-a-graph.csv"

cd $build_dir
make -j$(nproc) mg_import_csv

echo ${aeong_database_root}
if [ -d "$aeong_database_root" ]; then
  # 如果目标文件夹存在，则删除
  echo "remove $aeong_database_root"
  rm -rf "$aeong_database_root"
fi
mkdir -p ${aeong_database_root}
cd ${aeong_database_root}
echo "Converting CSV dataset to '${aeong_database_root}'"
${build_dir}/src/mg_import_csv  --data-directory ${aeong_database_root} ${gmark_dataset} --delimiter "|" --array-delimiter ";"

# convert to gmark-clockg dataset
mkdir -p ${clockg_database_root}
cp -r ${aeong_database_root}/* ${clockg_database_root}/

#Create AeonG temporal database, get graph operation latency, and get space
cd $scripts_dir
aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 20"
database_directory="--data-directory $aeong_database_root"
index_path="--index-cypher-path $dataset_root/gmark_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
benchmark_type="--benchmark-type gmark"
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
database_directory="--data-directory $clockg_database_root"
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
database_directory="--data-directory $tgql_database_root"
rm -rf $tgql_database_root
index_path="--index-cypher-path $dataset_root/gmark_tgql_index.cypher"
original_dataset_path="--original-dataset-cypher-path $dataset_root/tgql"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
binary_type="--binary-type tgql"
load_tgql_type="--load-tgql-flag 1"
benchamrk_type="--benchmark-type gmark"
python_script="${scripts_dir}/create_temporal_database.py"
echo "=============T-GQL create database, it cost time==========="
# python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $index_path $load_tgql_type $benchamrk_type $original_dataset_path
output=$(python3 $python_script $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $index_path $load_tgql_type $benchamrk_type $original_dataset_path)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============T-GQL graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

# Evaluation on T-gMark
echo "=============Various temporal query performance==========="
prefix_path="$base_dir/tests/results/"
op_num="--num-op $update_num"
min_time="--min-time 1076408" # 269547
max_time="--max-time 2086333" # 269547
write_path="--write-path $prefix_path/T-gMark/"
gmark_query_path="--gmark-query-path $save_dir/${type}-a-${num}k/query/processed"
python_script="${test_dir}/benchmarks/T-gMark/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path $gmark_query_path)

aeong_binary="--aeong-binary ${build_dir}/memgraph"
client_binary="--client-binary ${build_dir}/tests/mgbench/client"
number_workers="--num-workers 20"
database_directory="--data-directory $aeong_database_root"
index_path="--index-cypher-path $dataset_root/gmark_index.cypher"
python_script="${scripts_dir}/evaluate_temporal_q.py"
temporal_q1="--temporal-query-cypher-path $write_path/temporal_query/cypher.txt"

echo "AeonG q1"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1

echo "Evaluate Clock-G temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $clockg_binary"
binary_type="--binary-type clockg"
echo "Clock-G q1"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1

echo "Evaluate T-GQL temporal database, get temporal query latency,"
aeong_binary="--aeong-binary $memgraph_binary"
min_time="--min-time $start_time"
max_time="--max-time $end_time"
python_script="${test_dir}/benchmarks/T-gMark/create_temporal_query.py"
output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)
temporal_q1="--temporal-query-cypher-path $write_path/temporal_query/TGQL_cypher.txt"
echo "T-GQL q1"
python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1

