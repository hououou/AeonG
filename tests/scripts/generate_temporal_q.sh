#!/bin/bash

#create directory
prefix_path="../results/"
graph_op_path="$prefix_path$update_num/temporal_query"
rm -rf "$graph_op_path"
mkdir -p "$graph_op_path"

#generate graph operation queries
python_script="../benchmarks/T-mgBench/create_temporal_query.py"
python3 "$python_script"