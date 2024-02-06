import argparse
import sys
import os
import time
from datetime import datetime

sys.path.append('../mgbench')
import helpers
import runners


def extract_timestamp(filename):
    parts = filename.split('_')
    timestamp_part = parts[0]
    try:
        timestamp = int(timestamp_part)
    except ValueError:
        timestamp = 0
    return timestamp


def find_file_with_max_timestamp(directory):
    max_timestamp = float('-inf')  # Initialize with negative infinity
    max_timestamp_filename = None
    # Iterate over all files in the directory
    for filename in os.listdir(directory):
        # Check if it's a file (not a directory)
        if os.path.isfile(os.path.join(directory, filename)):
            # Extract the timestamp from the filename
            timestamp = extract_timestamp(filename)

            # Update max timestamp and filename if needed
            if timestamp > max_timestamp:
                max_timestamp = timestamp
                max_timestamp_filename = filename
    return max_timestamp_filename


def get_historical_space(folder_path):
    file_extension = '.log'
    file_extension2 = '.sst'
    get_size = 0
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(file_extension) or file.endswith(file_extension2):
                file_path = os.path.join(root, file)
                # 获取文件大小
                file_size = os.path.getsize(file_path)
                get_size += file_size
    return get_size


def get_space(folder_path, binary_type):
    total_size = 0
    snapshot_directory = folder_path + "/memgraph/snapshots"
    max_timestamp_filename = find_file_with_max_timestamp(snapshot_directory)
    snapshot_file_name = os.path.join(snapshot_directory, max_timestamp_filename)
    total_size += os.path.getsize(snapshot_file_name)

    # get historical data
    if binary_type != "clockg":
        folder_path = folder_path + "/memgraph/history_deltas"
        total_size += get_historical_space(folder_path)
        return total_size
    else:
        total_size += get_historical_space(folder_path + "/memgraph/history_deltas1")
        total_size += get_historical_space(folder_path + "/memgraph/history_deltas2")
        total_size += get_historical_space(folder_path + "/memgraph/history_deltas3")
        total_size += get_historical_space(folder_path + "/memgraph/history_deltas4")
        total_size += get_historical_space(folder_path + "/memgraph/history_copy1")
        total_size += get_historical_space(folder_path + "/memgraph/history_copy2")
        total_size += get_historical_space(folder_path + "/memgraph/history_copy3")
        total_size += get_historical_space(folder_path + "/memgraph/history_copy4")
        return total_size


def get_binary(args):
    if args.binary_type == "aeong":
        aeong = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                 memgraph_port=7687, snapshot_interval_sec=30, memory_limit=0,
                                 anchor_num=args.anchor_num, retention_interval_sec=args.retention_period_sec,
                                 real_time_flag=False)
        aeong.start_dataset()
        return aeong
    if args.binary_type == "tgql":
        tgql = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                memgraph_port=7687,
                                snapshot_interval_sec=30, memory_limit=0, anchor_num=10, real_time_flag=False)
        tgql.start_tgql_dataset()
        return tgql
    if args.binary_type == "clockg":
        clockg = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                  memgraph_port=7687, memory_limit=0, snapshot_interval_sec=0, anchor_num=10,
                                  graph_operations=args.clockg_snapshot)
        clockg.start_clockg_dataset()
        return clockg


if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create temporal database executor.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--aeong-binary",
                        default=helpers.get_binary_path("memgraph"),
                        help="AeonG binary")
    parser.add_argument("--client-binary",
                        default=helpers.get_binary_path("tests/mgbench/client"),
                        help="client binary")
    parser.add_argument("--num-workers", type=int,
                        default=1,
                        help="number of workers ")
    parser.add_argument("--data-directory",
                        default=helpers.get_binary_path("../tests/results/database"),
                        help="directory path where temporal data should "
                             "be stored")
    parser.add_argument("--original-dataset-cypher-path",
                        default=helpers.get_binary_path("../tests/datasets/T-mgBench/small.cypher"),
                        help="directory path where temporal data should "
                             "be stored")
    parser.add_argument("--index-cypher-path",
                        default=helpers.get_binary_path("../tests/datasets/T-mgBench/index.cypher"),
                        help="index cypher")
    parser.add_argument("--graph-operation-cypher-path",
                        default=helpers.get_binary_path("../tests/results/graph_op/cypher.txt"),
                        help="directory path where temporal data should "
                             "be stored")
    parser.add_argument("--no-properties-on-edges",
                        action="store_true",
                        help="disable properties on edges")
    parser.add_argument("--clockg-snapshot", type=int,
                        default=80000,
                        help="every x graph operations create a snapshot")
    parser.add_argument("--binary-type",
                        default="aeong",
                        help="aeong, tgql, clockg")
    parser.add_argument("--benchmark-type",
                        default="mgbench",
                        help="mgbench, ldbc, gmark")
    parser.add_argument("--anchor_num", type=int,
                        default=10,
                        help="interval between two anchors")
    parser.add_argument("--retention-period-sec", type=int,
                        default=0,
                        help="Retention period duration (seconds)")
    parser.add_argument("--load-tgql-flag", type=int,
                        default=0,
                        help="whether or not to create tgql database")

    args = parser.parse_args()
    parsed_args = vars(args)
    # print("=========check your configuration========")
    # for key, value in parsed_args.items():
    #     print(f"  {key}: {value}")

    # print("=========create temporal database now, it will spend some time========")
    aeong = get_binary(args)
    client = runners.Client(args.client_binary, args.data_directory, memgraph_port=7687)
    # create index
    client.execute(file_path=args.index_cypher_path, num_workers=args.num_workers)
    # create original database
    if args.load_tgql_flag == 1:
        if args.benchmark_type == "ldbc":
            #create nodes
            folder_path = args.original_dataset_cypher_path
            files_in_folder = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]
            for filename in files_in_folder:
                # print(args.original_dataset_cypher_path+"/"+filename)
                ret1_test = client.execute(file_path=args.original_dataset_cypher_path+"/"+filename, num_workers=args.num_workers)
            #create edges
            working_directory2 = f'{args.original_dataset_cypher_path}/edges'
            for root, _, filenames in os.walk(working_directory2):
                for filename in filenames:
                    edge_path=f"{args.original_dataset_cypher_path}/edges/{filename}"
                    # print(edge_path)
                    ret1_test = client.execute(file_path=edge_path, num_workers=args.num_workers)
                    time.sleep(3)
        elif args.benchmark_type == "gmark":
            #create nodes
            ret1_test = client.execute(file_path=f'{args.original_dataset_cypher_path}/tgql_node.txt', num_workers=args.num_workers)
            #create edges
            ret1_test = client.execute(file_path=f'{args.original_dataset_cypher_path}/tgql_edge.txt', num_workers=args.num_workers)
        else:
            client.execute(file_path=args.original_dataset_cypher_path, num_workers=args.num_workers)
    else:
        if args.benchmark_type != "gmark":
            client.execute(file_path=args.original_dataset_cypher_path, num_workers=args.num_workers)
    # process graph operations to generate historical data
    start_time = int(time.time() * 1000000)
    graph_op_ret = client.execute(file_path=args.graph_operation_cypher_path, num_workers=args.num_workers)
    end_time = int(time.time() * 1000000)
    if args.binary_type == "clockg":
        # need time to store historical data
        time.sleep(5 * 60)
    if args.binary_type == "aeong":
        time.sleep(60)
    aeong.stop()
    print(graph_op_ret[0]['duration'] / graph_op_ret[0]['count'],
        get_space(args.data_directory, args.binary_type) / 1024 / 1024, start_time, end_time)
