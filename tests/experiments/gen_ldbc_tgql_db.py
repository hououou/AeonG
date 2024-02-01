import argparse
import time
import sys
sys.path.append(".../mgbench/")
import helpers
import runners
from pathlib import Path

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="Memgraph benchmark executor.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--memgraph-binary",
                        default="/home/hjm/memgraph/build/memgraph",
                        help="Memgraph binary used for benchmarking")
    parser.add_argument("--client-binary",
                        default=helpers.get_binary_path("tests/mgbench/client"),
                        help="client binary used for benchmarking")
    parser.add_argument("--data-directory",
                        default="../results/database/default",
                        help="data directory used for benchmarking")
    parser.add_argument("--dataset-path",
                        default="../results/database/default",
                        help="tgql cypher path of dataset")
    parser.add_argument("--num-workers",
                        default=5,
                        type=int,
                        help="nums of workers used for import")
    parser.add_argument("--index-cypher-path",
                        default=helpers.get_binary_path("../tests/datasets/T-mgBench/index.cypher"),
                        help="index cypher")
    args = parser.parse_args()

    # args.temporary_directory="/data/hjm/0_ldbc/TGQL_origin_s3"
    # args.memgraph_binary="/home/hjm/memgraph-master/build/memgraph"
    # print(args.memgraph_binary)
    # print(args.temporary_directory)
    # print(args.no_properties_on_edges)
    memgraph = runners.Memgraph(args.memgraph_binary, args.data_directory,
                                True,7687,snapshot_interval_sec=1200,memory_limit=0,anchor_num=11)
    client = runners.Client(args.client_binary, args.temporary_directory,7687)

    # create index
    client.execute(file_path=args.index_cypher_path, num_workers=args.num_workers)

    #create nodes
    working_directory = Path(args.dataset_path).absolute()
    nodes_file = sorted(working_directory.glob("*.txt"))
    # filter_file=["Tag.txt","TagClass.txt"]
    for file in nodes_file:
        # if file.name not in filter_file:
        #     continue
        ret1_test = client.execute(file_path=args.dataset_path+file.name, num_workers=args.num_workers)

    #create edges
    working_directory = Path(f'{args.dataset_path}/edges').absolute()
    edges_file = sorted(working_directory.glob("*.txt"))
    for file in edges_file:
        ret1_test = client.execute(file_path=f'{args.dataset_path}/edges/{file.name}', num_workers=args.num_workers)
        time.sleep(3)
    print("create datasets done!")