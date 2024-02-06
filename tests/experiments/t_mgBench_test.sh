#!/bin/bash
update_num=320000 #$1 #320000
clockg_binary=/home/hjm/vldb/clockg/build/memgraph #$2 #/home/hjm/vldb/clockg/build/memgraph
memgraph_binary=/home/hjm/vldb/memgraph-master/build/memgraph #$3 #/home/hjm/vldb/memgraph-master/build/memgraph

# # download T-mgBench
echo "Prepare datasets"
#download original dataset
mkdir -p ../datasets/T-mgBench
mgbench_download_dir="../datasets/T-mgBench"
dataset_url="https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/pokec_small_import.cypher"
curl -o "$mgbench_download_dir/cypher.cypher" "$dataset_url"
index_url="https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/memgraph.cypher"
curl -o "$mgbench_download_dir/cypher_index.cypher" "$index_url"
echo "Download mgbench dataset completed."

convert to tgql dataset
python_script="get_mgbench_tgql_dataset.py"
cypher_file_path="--cypher-file-path $mgbench_download_dir/cypher.cypher"
TGQL_cypher_file_path="--TGQL-cypher-file-path $mgbench_download_dir/TGQL.cypher"
python_script="get_mgbench_tqgl_dataset.py"
output=$(python3 "$python_script" $cypher_file_path $TGQL_cypher_file_path)

#create graph operation
#echo "Create graph operation query statements"
prefix_path="../results/"
graph_op_path="$prefix_path/graph_op"
rm -rf "$graph_op_path"
mkdir -p "$graph_op_path"
update_num_arg="--num-op $update_num"
write_path="--write-path $prefix_path"
dataset_path="--dataset-path ../datasets/T-mgBench/"
python_script="../benchmarks/T-mgBench/create_graph_op_queries.py"
output=$(python3 "$python_script" $update_num_arg $dataset_path $write_path)


#Create AeonG temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary ../../build/memgraph"
client_binary="--client-binary ../../build/tests/mgbench/client"
number_workers="--num-workers 20"
rm -rf $prefix_path/database/aeong
mkdir -p $prefix_path/database/aeong
database_directory="--data-directory $prefix_path/database/aeong"
original_dataset="--original-dataset-cypher-path $mgbench_download_dir/cypher.cypher"
index_path="--index-cypher-path $mgbench_download_dir/cypher_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
python_script="../scripts/create_temporal_database.py"
echo "=============AeonG create database, it cost time==========="
output=$(python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============AeonG graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

#Create ClockG temporal database, get graph operation latency, and get space"
aeong_binary="--aeong-binary ../../build/memgraph"
clockg_snapshot="--clockg-snapshot 80000"
database_directory="--data-directory $prefix_path/database/clockg"
rm -rf $prefix_path/database/clockg
mkdir -p $prefix_path/database/clockg
python_script="../scripts/create_temporal_database.py"
index_path="--index-cypher-path $mgbench_download_dir/cypher_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $mgbench_download_dir/cypher_index.cypher"
output=$(python3 $python_script $aeong_binary $client_binary $original_dataset_path $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path)
echo "=============Clock-G create database, it cost time==========="
aeong_binary="--aeong-binary $clockg_binary"
binary_type="--binary-type clockg"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/cypher.txt"
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $clockg_snapshot $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============Clock-G graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

Create TGQL temporal database, get graph operation latency, and get space
aeong_binary="--aeong-binary $memgraph_binary"
rm -rf $prefix_path/database/TGQL
mkdir -p $prefix_path/database/TGQL
database_directory="--data-directory $prefix_path/database/TGQL"
original_dataset="--original-dataset-cypher-path $mgbench_download_dir/TGQL.cypher"
index_path="--index-cypher-path $mgbench_download_dir/TGQL_index.cypher"
graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
binary_type="--binary-type tgql"
python_script="../scripts/create_temporal_database.py"
echo "=============T-GQL create database, it cost time==========="
python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $graph_op_cypher_path $database_directory $original_dataset $index_path
output=$(python3 "$python_script" $aeong_binary $client_binary $binary_type $number_workers $database_directory $original_dataset $index_path $graph_op_cypher_path $binary_type)
graph_op_latency=$(echo "$output" | awk '{print $1}')
storage_consumption=$(echo "$output" | awk '{print $2}')
start_time=$(echo "$output" | awk '{print $3}')
end_time=$(echo "$output" | awk '{print $4}')
echo "=============T-GQL graph operation latency & spance==========="
echo "graph_op_latency:$graph_op_latency"
echo "storage_consumption:$storage_consumption"

if [ "$update_num" -eq 320000 ]; then
  echo "=============Various temporal query performance==========="
  prefix_path="../results/"
  op_num="--num-op $update_num"
  min_time="--min-time 453365"
  max_time="--max-time 812243"
  frequency_type="--frequency-type mix"
  write_path="--write-path $prefix_path"
  temporal_query_path=$prefix_path"temporal_query"
  rm -rf temporal_query_path
  mkdir -p temporal_query_path
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)

  aeong_binary="--aeong-binary ../../build/memgraph"
  client_binary="--client-binary ../../build/tests/mgbench/client"
  number_workers="--num-workers 1"
  database_directory="--data-directory $prefix_path/database/aeong"
  index_path="--index-cypher-path ../datasets/T-mgBench/cypher_index.cypher"
  python_script="../scripts/evaluate_temporal_q.py"
  temporal_q1="--temporal-query-cypher-path $temporal_query_path/cypher_Q1.txt"
  temporal_q2="--temporal-query-cypher-path $temporal_query_path/cypher_Q2.txt"
  temporal_q3="--temporal-query-cypher-path $temporal_query_path/cypher_Q3.txt"
  temporal_q4="--temporal-query-cypher-path $temporal_query_path/cypher_Q4.txt"
  echo "AeonG q1 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
  echo "AeonG q2 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q2
  echo "AeonG q3 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
  echo "AeonG q4 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4

  echo "Evaluate Clock-G temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $clockg_binary"
  binary_type="--binary-type clockg"
  echo "Clock-G q1 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $binary_type $index_path $temporal_q1
  echo "Clock-G q2 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $binary_type $index_path $temporal_q2
  echo "Clock-G q3 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $binary_type $index_path $temporal_q3
  echo "Clock-G q4 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $binary_type $index_path $temporal_q4

  echo "Evaluate T-GQL temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $memgraph_binary"
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path)
  temporal_q1="--temporal-query-cypher-path $temporal_query_path/TGQL_cypher_Q1.txt"
  temporal_q2="--temporal-query-cypher-path $temporal_query_path/TGQL_cypher_Q2.txt"
  temporal_q3="--temporal-query-cypher-path $temporal_query_path/TGQL_cypher_Q3.txt"
  temporal_q4="--temporal-query-cypher-path $temporal_query_path/TGQL_cypher_Q4.txt"
  echo "T-GQL q1 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q1
  echo "T-GQL q2 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q2
  echo "T-GQL q3 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q3
  echo "T-GQL q4 mix"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q4

  echo "=============Temporal query performance varying frequency level==========="
  #generate hot query
  frequency_type="--frequency-type hot"
  write_path="--write-path $prefix_path"
  temporal_query_path=$prefix_path"temporal_query"
  rm -rf temporal_query_path
  mkdir -p temporal_query_path
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  echo "AeonG hot"
  python_script="../scripts/evaluate_temporal_q.py"
  temporal_q="--temporal-query-cypher-path $temporal_query_path/cypher_Q3.txt"
  aeong_binary="--aeong-binary ../../build/memgraph"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q
  echo "Clock-G hot"
  binary_type="--binary-type clockg"
  aeong_binary="--aeong-binary $clockg_binary"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $binary_type $database_directory $index_path $temporal_q
  echo "TGQL hot"
  aeong_binary="--aeong-binary $memgraph_binary"
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  temporal_q3="--temporal-query-cypher-path $temporal_query_path/TGQLcypher_Q3.txt"
  python_script="../scripts/evaluate_temporal_q.py"
  python3 "$python_script" $aeong_binary $client_binary $op_num $number_workers $database_directory $index_path $temporal_q3

  frequency_type="--frequency-type warm"
  write_path="--write-path $prefix_path"
  temporal_query_path=$prefix_path"temporal_query"
  rm -rf temporal_query_path
  mkdir -p temporal_query_path
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  echo "AeonG warm"
  python_script="../scripts/evaluate_temporal_q.py"
  temporal_q="--temporal-query-cypher-path $temporal_query_path/cypher_Q3.txt"
  aeong_binary="--aeong-binary ../../build/memgraph"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q
  echo "Clock-G warm"
  binary_type="--binary-type clockg"
  aeong_binary="--aeong-binary $clockg_binary"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $binary_type $database_directory $index_path $temporal_q
  echo "TGQL warm"
  aeong_binary="--aeong-binary $memgraph_binary"
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  temporal_q3="--temporal-query-cypher-path $temporal_query_path/TGQLcypher_Q1.txt"
  python_script="../scripts/evaluate_temporal_q.py"
  python3 "$python_script" $aeong_binary $client_binary $op_num $number_workers $database_directory $index_path $temporal_q3

  frequency_type="--frequency-type cold"
  write_path="--write-path $prefix_path"
  temporal_query_path=$prefix_path"temporal_query"
  rm -rf temporal_query_path
  mkdir -p temporal_query_path
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  echo "AeonG cold"
  python_script="../scripts/evaluate_temporal_q.py"
  temporal_q="--temporal-query-cypher-path $temporal_query_path/cypher_Q3.txt"
  aeong_binary="--aeong-binary ../../build/memgraph"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q
  echo "Clock-G cold"
  binary_type="--binary-type clockg"
  aeong_binary="--aeong-binary $clockg_binary"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $binary_type $database_directory $index_path $temporal_q
  echo "TGQL cold"
  aeong_binary="--aeong-binary $memgraph_binary"
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  python_script="../benchmarks/T-mgBench/create_temporal_query.py"
  output=$(python3 "$python_script" $min_time $max_time $op_num $frequency_type $write_path)
  temporal_q3="--temporal-query-cypher-path $temporal_query_path/TGQLcypher_Q1.txt"
  python_script="../scripts/evaluate_temporal_q.py"
  python3 "$python_script" $aeong_binary $client_binary $op_num $number_workers $database_directory $index_path $temporal_q3

fi