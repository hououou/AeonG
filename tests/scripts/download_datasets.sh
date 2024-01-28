#!/bin/bash

# rm -rf ../datasets

# # download T-mgBench
mkdir -p ../datasets/T-mgBench
mgbench_download_dir="../datasets/T-mgBench"
dataset_url="https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/pokec_small_import.cypher"
curl -o "$mgbench_download_dir/small.cypher" "$dataset_url"
echo "Download mgbench dataset completed."

# # download T-LDBC
#mkdir -p ../datasets/T-LDBC
#mgbench_download_dir="../datasets/T-LDBC"
#dataset_url="https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/ldbc/benchmark/interactive/ldbc_interactive_sf1.cypher.gz"
#curl -o "$mgbench_download_dir/ldbc1.cypher.gz" "$dataset_url"
#gzip -d "$mgbench_download_dir/ldbc1.cypher.gz"
#rm -rf "$mgbench_download_dir/ldbc1.cypher.gz"
#echo "Download ldbc dataset completed."

