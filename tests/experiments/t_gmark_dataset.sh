#!/bin/bash
update_num=320000
nodes=100000
type="test"
schema_types=("test" "shop" "social" "uniprot")
schema_types=("test")
clockg_binary=$1
memgraph_binary=$2

temp_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="$( cd ../.. "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
echo $base_dir
build_dir="${base_dir}/build"
test_dir="${base_dir}/tests"
dataset_root="${test_dir}/datasets/T-gMark"
result_dir="$test_dir/results"
gmark_dir="$test_dir/results/gmark"
scripts_dir="$test_dir/scripts"
database_root="$test_dir/results/database"
aeong_database_root="${database_root}/gmark/aeong"
clockg_database_root="${database_root}/gmark/clokg"
tgql_database_root="${database_root}/gmark/tgql"
mkdir -p $dataset_root
mkdir -p $aeong_database_root
mkdir -p $clockg_database_root
mkdir -p $tgql_database_root

# HOW to use T-gMark
# replace some original gmark scripts with T-gMark versions
cd $test_dir/results
rm -rf $test_dir/results/gmark
git clone https://github.com/gbagan/gmark.git
rm -rf $test_dir/results/gmark/use-cases/*
cp -r $test_dir/experiments/gmark-use-cases/* $test_dir/results/gmark/use-cases/

# To compile the code:
cd ${gmark_dir}/demo/scripts
./compile-all.sh
#
## clear the dataset directory
save_dir="$dataset_root"
rm -rf ${save_dir}/*

for item in "${schema_types[@]}"
do
  echo "$item"
  type=$item
  echo $nodes
  num=$[nodes/1000]
  echo $num
  echo $type
  config_name=$type
  if [ "$type" = "social" ]; then
    config_name="social-network-ratio"
  fi

  graph_dir="${gmark_dir}/demo/${type}-a-${num}k"
  echo ${graph_dir}
  if [ -d "$graph_dir" ]; then
    # 如果目标文件夹存在，则删除
    echo "remove $graph_dir"
    rm -rf "$graph_dir"
  fi

  mkdir -p ${graph_dir}
  cd ${gmark_dir}/src
  # Generation of the graph and query workload in internal format, and html reports for both
  ./test -c ../use-cases/${config_name}.xml -g ${graph_dir}/${type}-a-graph.txt -w ${graph_dir}/${type}-a-workload.xml -r ${graph_dir}/ -a -n ${nodes}
  mv ${graph_dir}/${type}-a-graph.txt0.txt ${graph_dir}/${type}-a-graph.txt

  cd querytranslate
  # echo ${graph_dir}/query
  mkdir -p ${graph_dir}/query
  # Translation of the queries into cypher
  ./test -w ${graph_dir}/${type}-a-workload.xml -o ${graph_dir}/query
  find ${graph_dir}/query -type f \( -name "*.lb" -o -name "*.sql" -o -name "*.sparql" \) -delete
  mv ${graph_dir} ${save_dir}/
  dataset_dir=${save_dir}/${type}-a-${num}k

  # generate to T-gMark dataset and original workload
  cd $temp_dir
  mkdir -p ${dataset_dir}/tgql
  python_script="${temp_dir}/get_gmark_dataset.py"
  args_1="--directory $save_dir/${type}-a-${num}k"
  args_2="--dbtype $type"
  args_3="--number $num"
  output=$(python3 "$python_script" $args_1 $args_2 $args_3)

  # create index
  echo "create index"
  rm -rf ${save_dir}/gmark_index.cypher
  rm -rf ${save_dir}/gmark_tgql_index.cypher
  echo "CREATE INDEX ON :Node(id)" >> ${save_dir}/gmark_index.cypher
  echo "CREATE INDEX ON :Object (title);" >> ${save_dir}/gmark_tgql_index.cypher
  echo "CREATE INDEX ON :Attribute(title);" >> ${save_dir}/gmark_tgql_index.cypher
  echo "CREATE INDEX ON :Value(title);" >> ${save_dir}/gmark_tgql_index.cypher

  #create graph operation
  echo "Create graph operation query statements"
  prefix_path="$base_dir/tests/results/T-gMark/${type}/"
  graph_op_path="${prefix_path}graph_op/"
  peak_vertices_path="${prefix_path}peak_vertices/"
  rm -rf $graph_op_path
  mkdir -p $graph_op_path
  rm -rf $peak_vertices_path
  mkdir -p $peak_vertices_path
  update_num_arg="--num-op $update_num"
  write_path="--write-path $prefix_path"
  dataset_path="--gmark-dataset-path ${dataset_root}/${type}-a-${num}k/${type}-a-nodes.csv"
  python_script="${test_dir}/benchmarks/T-gMark/create_graph_op_queries.py"
  output=$(python3 $python_script $update_num_arg $dataset_path $write_path)

  # generate the original T-gMark database
  gmark_dataset="
  --nodes ${save_dir}/${type}-a-${num}k/${type}-a-nodes.csv \
  --relationships ${save_dir}/${type}-a-${num}k/${type}-a-graph.csv"

  cd $build_dir
  make -j$(nproc) mg_import_csv

  echo "AeonG & ClockG create origin database and get storage consumption"
  echo ${aeong_database_root}
  aeong_database=${aeong_database_root}/${type}
  if [ -d "$aeong_database" ]; then
    # 如果目标文件夹存在，则删除
    echo "remove $aeong_database"
    rm -rf "$aeong_database"
  fi
  mkdir -p ${aeong_database}
  cd ${aeong_database}
  echo "Converting CSV dataset to '${aeong_database}'"
  ${build_dir}/src/mg_import_csv  --data-directory ${aeong_database} ${gmark_dataset} --delimiter "|" --array-delimiter ";"

   # convert to gmark-clockg dataset
  clockg_database=${clockg_database_root}/${type}
  rm -rf ${clockg_database_root}/${type}
  mkdir -p ${clockg_database_root}/${type}
  cp -r ${aeong_database} ${clockg_database}/

   #Create AeonG temporal database, get graph operation latency, and get space
  cd $scripts_dir
  aeong_binary="--aeong-binary ${build_dir}/memgraph"
  client_binary="--client-binary ${build_dir}/tests/mgbench/client"
  number_workers="--num-workers 20"
  database_directory="--data-directory $aeong_database"
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
#
  #Create ClockG temporal database, get graph operation latency, and get space"
  aeong_binary="--aeong-binary $clockg_binary"
  clockg_snapshot="--clockg-snapshot 80000"
  database_directory="--data-directory $clockg_database"
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
  tgql_database=$tgql_database_root/${type}
  aeong_binary="--aeong-binary $memgraph_binary"
  database_directory="--data-directory $tgql_database"
  rm -rf $tgql_database
  mkdir -p $tgql_database
  index_path="--index-cypher-path $dataset_root/gmark_tgql_index.cypher"
  original_dataset_path="--original-dataset-cypher-path $dataset_dir/tgql"
  graph_op_cypher_path="--graph-operation-cypher-path $graph_op_path/TGQL_cypher.txt"
  binary_type="--binary-type tgql"
  load_tgql_type="--load-tgql-flag 1"
  benchamrk_type="--benchmark-type gmark"
  python_script="${scripts_dir}/create_temporal_database.py"
  echo "=============T-GQL create database, it cost time==========="
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
  write_path="--write-path $prefix_path/T-gMark/${type}/"
  gmark_query_path="--gmark-query-path $save_dir/${type}-a-${num}k/query/processed"
  temporal_query_path="${prefix_path}T-gMark/${type}/temporal_query"
  echo $temporal_query_path
  rm -rf $temporal_query_path
  mkdir -p $temporal_query_path
  python_script="${test_dir}/benchmarks/T-gMark/create_temporal_query.py"
  output=$(python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path $gmark_query_path)

  aeong_binary="--aeong-binary ${build_dir}/memgraph"
  client_binary="--client-binary ${build_dir}/tests/mgbench/client"
  number_workers="--num-workers 1"
  database_directory="--data-directory $aeong_database"
  index_path="--index-cypher-path $dataset_root/gmark_index.cypher"
  python_script=${scripts_dir}/evaluate_temporal_q.py
  temporal_path="--temporal-query-cypher-path $prefix_path/T-gMark/${type}/temporal_query/cypher.txt"
  echo $tempoal_path
  echo "AeonG query:"
  echo $database_directory
  echo $python_script
  echo $aeong_binary $tempoal_path $client_binary $number_workers $database_directory $index_path
  python3 $python_script $aeong_binary $tempoal_path $client_binary $number_workers $database_directory $index_path

#  echo "Evaluate Clock-G temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $clockg_binary"
  binary_type="--binary-type clockg"
  database_directory="--data-directory $clockg_database"
  echo "Clock-G query:"
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $tempoal_path $binary_type

  echo "Evaluate T-GQL temporal database, get temporal query latency,"
  aeong_binary="--aeong-binary $memgraph_binary"
  start_time=0
  end_time=1
  min_time="--min-time $start_time"
  max_time="--max-time $end_time"
  binary_type="--binary-type tgql"
  python_script="${test_dir}/benchmarks/T-gMark/create_temporal_query.py"
  index_path="--index-cypher-path $dataset_root/gmark_tgql_index.cypher"
  python3 "$python_script" $op_num $min_time $max_time $frequency_type $write_path $gmark_query_path
  temporal_q_path="--temporal-query-cypher-path $prefix_path/T-gMark/${type}/temporal_query/TGQL_cypher.txt"
  echo "T-GQL query:"
  database_directory="--data-directory $tgql_database"
  python_script=${scripts_dir}/evaluate_temporal_q.py
  python3 "$python_script" $aeong_binary $client_binary $number_workers $database_directory $index_path $temporal_q_path $binary_type
done