import argparse
import sys
import os
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

def get_space(folder_path):
    total_size = 0
    snapshot_directory=folder_path+"/memgraph/snapshots"
    max_timestamp_filename = find_file_with_max_timestamp(snapshot_directory)
    snapshot_file_name=os.path.join(snapshot_directory, max_timestamp_filename)
    total_size += os.path.getsize(snapshot_file_name)

    #get historical data
    folder_path=folder_path+"/memgraph/historical_deltes"
    file_extension = '.log'
    file_extension2='.sst'
    for root, dirs, files in os.walk(folder_path):
        for file in files:
            if file.endswith(file_extension) or file.endswith(file_extension2):
                file_path = os.path.join(root, file)
                # 获取文件大小
                file_size = os.path.getsize(file_path)
                total_size += file_size
    return total_size


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

    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")
    #
    aeong = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges, memgraph_port=7687,
                             snapshot_interval_sec=30, memory_limit=0, anchor_num=10, real_time_flag=False)
    client = runners.Client(args.client_binary, args.data_directory, memgraph_port=7687)
    aeong.start_dataset()
    print("=========create index========")
    client.execute(file_path=args.index_cypher_path, num_workers=args.num_workers)
    print("=========create original database========")
    ret = client.execute(file_path=args.original_dataset_cypher_path, num_workers=args.num_workers)
    print("=========process graph operations to generate historical data========")
    graph_op_ret = client.execute(file_path=args.graph_operation_cypher_path, num_workers=args.num_workers)
    print("graph operation latency(s):", graph_op_ret[0]['duration']/graph_op_ret[0]['count'])
    print("=========close databases and get space consumptions========")
    aeong.stop()
    print("storage consumption(kb):",get_space(args.data_directory))
