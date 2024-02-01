#!/bin/bash

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="${script_dir}/../.."
build_dir="${base_dir}/build"
test_dir="${script_dir}/.."
dataset_root="${test_dir}/datasets/T-gMark"
result_dir="$test_dir/results"
gmark_dir="$test_dir/gmark"
database_root="$test_dir/results/database/T-gMark"
cd $test_dir
git clone https://github.com/gbagan/gmark.git

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


graph_dir="${script_dir}/demo/${type}-a-${num}k"
# save_dir="/data/hjm/gMark/datasets/social-LDBC/"
save_dir="$dataset_root/"
echo ${graph_dir}
if [ -d "$graph_dir" ]; then
  # 如果目标文件夹存在，则删除
  echo "remove $graph_dir"
  rm -rf "$graph_dir"
fi

mkdir -p ${graph_dir}
mkdir -p ${graph_dir}/query
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
# rm -rf ${graph_dir}/query/*.lb
# rm -rf ${graph_dir}/query/*.
find ${graph_dir}/query -type f \( -name "*.lb" -o -name "*.sql" -o -name "*.sparql" \) -delete

mv ${graph_dir} ${save_dir}/${type}-a-${num}k

# generate to gMark dataset and original workload
cd $script_dir
python_script="${script_dir}/get_gmark_dataset.py"
args_1="--directory $save_dir/${type}-a-${num}k"
args_2="--dbtype $type"
args_3="--number $num"
output=$(python3 "$python_script" $args_1 $args_2 $args_3)

# generate the original T-gMark database

gmark_dataset="
--nodes ${save_dir}/${type}-a-${num}k/${type}-a-nodes.csv \
--relationships ${save_dir}/${type}-a-${num}k/${type}-a-graph.csv"

memgraph_snapshot_dir=${database_root}/aeong/${type}-a-${num}k
echo ${memgraph_snapshot_dir}
if [ -d "$memgraph_snapshot_dir" ]; then
  # 如果目标文件夹存在，则删除
  echo "remove $memgraph_snapshot_dir"
  rm -rf "$memgraph_snapshot_dir"
fi
mkdir -p ${memgraph_snapshot_dir}
cd ${memgraph_snapshot_dir}
echo "Converting CSV dataset to '${memgraph_snapshot_dir}'"
${build_dir}/tools/src/mg_import_csv  --data-directory memgraph ${gmark_dataset} --delimiter "|" --array-delimiter ";"

# convert to gmark-clockg dataset
clockg_dir=${database_root}/clockg
mkdir -p ${clockg_dir}
cp -r ${memgraph_snapshot_dir} ${clockg_dir}/

# build origin tgql database using gen_ldbc_db
tgql_dir=${database_root}/tgql
tgql_node_dir=${save_dir}/${type}-a-${num}k/tgql_node.txt
tgql_edge_dir=${save_dir}/${type}-a-${num}k/tgql_edge.txt
mkdir -p ${tgql_dir}

tgql_db_script="${script_dir}/get_gmark_tgql_db.py"
memg_binary="--aeong-binary $memgraph_binary"
client_binary="--client-binary ../../build/tests/mgbench/client"
number_workers="--num-workers 1"
db_dir="--data-directory $tgql_dir/${type}-a-${num}k"
tgql_node_path="--node-path $tgql_node_dir"
tgql_edge_path="--edge-path $tgql_edge_dir"
index_path="--index-cypher-path $dataset_root/TGQL_index.cypher"
output=$(python3 "$tgql_db_script" $memg_binary $client_binary $db_dir $tgql_node_path $tgql_edge_path $number_workers $index_path)

#Create AeonG temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary ../../build/memgraph"
client_binary="--client-binary ../../build/tests/mgbench/client"
number_workers="--num-workers 1"
database_directory="--data-directory ${database_root}/aeong/${type}-a-${num}k"
index_path="--index-cypher-path $dataset_root/cypher_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
benchmark_type="--benchmark-type gmark"
python_script="../scripts/create_temporal_database.py"
echo "=============AeonG create database, it cost time==========="
output=$(python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path $benchmark_type)
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
database_directory="--data-directory $database_root/clockg/${type}-a-${num}k"
binary_type="--binary-type clockg"
python_script="../scripts/create_temporal_database.py"
echo "=============Clock-G create database, it cost time==========="
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $clockg_snapshot $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============Clock-G graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create TGQL temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary $memgraph_binary"
database_directory="--data-directory $database_root/tgql/${type}-a-${num}k"
index_path="--index-cypher-path $dataset_root/TGQL_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
binary_type="--binary-type tgql"
python_script="../scripts/create_temporal_database.py"
echo "=============T-GQL create database, it cost time==========="
python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $original_dataset $index_path
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path $binary_type $benchmark_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============T-GQL graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

# Evaluation on T-gMark
if [ "$update_num" -eq 100000 ]; then
  echo "=============Various temporal query performance==========="
  prefix_path="../results/"
  op_num="--num-op $update_num"
  min_time="--min-time 453365" # 269547
  max_time="--max-time 812243" # 269547
  write_path="--write-path $prefix_path/T-gMark/${type}-a-${num}k/"
  gmark_query_path="--gmark-query-path $save_dir/${type}-a-${num}k/query/processed"
  python_script="../benchmarks/T-gMark/create_temporal_query.py"
  output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path gmark_query_path)

  aeong_binary="--aeong-binary ../../build/memgraph"
  client_binary="--client-binary ../../build/tests/mgbench/client"
  number_workers="--num-workers 1"
  database_directory="--data-directory ${database_root}/aeong/${type}-a-${num}k"
  index_path="--index-cypher-path $dataset_root/cypher_index.cypher"
  python_script="../scripts/evaluate_temporal_q.py"
  temporal_q1="--temporal-query-cypher-path $write_path/temporal_query/cypher.txt"
  
  echo "AeonG q1"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
  
#  echo "Evaluate Clock-G temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $clockg_binary"
  binary_type="--binary-type clockg"
  echo "Clock-G q1"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1

#  echo "Evaluate T-GQL temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $memgraph_binary"
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  python_script="../benchmarks/T-gMark/create_temporal_query.py"
  output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)
  temporal_q1="--temporal-query-cypher-path $write_path/temporal_query/TGQL_cypher.txt"
  echo "T-GQL q1"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
fi

