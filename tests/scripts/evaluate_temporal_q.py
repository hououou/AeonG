import argparse
import sys
import os
sys.path.append('../mgbench')
import helpers
import runners

def get_binary(args):
    if args.binary_type == "aeong":
        aeong = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                 memgraph_port=7687,
                                 snapshot_interval_sec=30, memory_limit=0, anchor_num=10, real_time_flag=False)
        aeong.start_benchmark()
        return aeong
    if args.binary_type == "tgql":
        tgql = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                memgraph_port=7687,
                                snapshot_interval_sec=30, memory_limit=0, anchor_num=10, real_time_flag=False)
        tgql.start_tgql_benchmark()
        return tgql
    if args.binary_type == "clockg":
        clockg = runners.Memgraph(args.aeong_binary, args.data_directory, not args.no_properties_on_edges,
                                  memgraph_port=7687,
                                  snapshot_interval_sec=30, memory_limit=0, anchor_num=10, real_time_flag=False)
        clockg.start_tgql_benchmark()
        return clockg

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG evaluate temporal query performance.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--aeong-binary",
                        default=helpers.get_binary_path("memgraph"),
                        help="AeonG binary used for benchmarking")
    parser.add_argument("--client-binary",
                        default=helpers.get_binary_path("tests/mgbench/client"),
                        help="client binary used for benchmarking")
    parser.add_argument("--num-workers", type=int,
                        default=1,
                        help="number of workers used to execute the benchmark")
    parser.add_argument("--data-directory",
                        default=helpers.get_binary_path("../tests/results/database"),
                        help="directory path where temporal data should "
                             "be stored")
    parser.add_argument("--index-cypher-path",
                        default=helpers.get_binary_path("../tests/datasets/T-mgBench/index.cypher"),
                        help="index cypher")
    parser.add_argument("--temporal-query-cypher-path",
                        default=helpers.get_binary_path("../tests/results/temporal_query/cypher_Q1.txt"),
                        help="directory path where temporal data should "
                             "be stored")
    parser.add_argument("--no-properties-on-edges",
                        action="store_true",
                        help="disable properties on edges")
    parser.add_argument("--storage-gc-cycle-sec", type=int,
                        default=30,
                        help="Storage garbage collector interval (in seconds).")
    parser.add_argument("--binary-type",
                        default="aeong",
                        help="aeong, tgql, clockg")

    args = parser.parse_args()
    parsed_args = vars(args)
    # print("=========check your configuration========")
    # for key, value in parsed_args.items():
    #     print(f"  {key}: {value}")
    #
    aeong = get_binary(args)
    client = runners.Client(args.client_binary, args.data_directory, memgraph_port=7687)
    # if args.binary_type == "aeong":
    client.execute(file_path=args.index_cypher_path, num_workers=args.num_workers)
    # Evaluate temporal query
    client.execute(file_path=args.temporal_query_cypher_path, num_workers=args.num_workers)
    temporal_q_ret = client.execute(file_path=args.temporal_query_cypher_path, num_workers=args.num_workers)
    print("temporal query latency(s):", temporal_q_ret[0]['duration']/temporal_q_ret[0]['count'])
    aeong.stop()
