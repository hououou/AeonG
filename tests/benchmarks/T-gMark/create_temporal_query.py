import random
import csv
import os
import re
import argparse

class gMark():
    def __init__(self, size="sf1", max_op=0.1, update_ratio=1, delete_ratio=0):
        SIZES = {
            "sf1": {"vertices": 100000, "edges": 239737}
        }

        self._size = size
        self.max_op_ratio = max_op
        self._num_vertices = SIZES[size]["vertices"]
        self._num_edges = SIZES[size]["edges"]
        self._max_graph_op = self.max_op_ratio  # 100000#int(self._num_vertices*self.max_op_ratio) #图操作的数量
        self._max_update_op = int(self._max_graph_op * update_ratio)  # update操作的数量
        self._max_delete_op = int(self._max_graph_op * delete_ratio)  # delete操作的数量
        self._max_create_op = self._max_graph_op - self._max_update_op - self._max_delete_op  # create操作的数量
        self._count_update_num = 0

    # help function
    def write_to_file(self, file_path, write_lists):
        f1 = open(file_path, "w", encoding='utf-8')
        for key in write_lists:
            f1.write(str(key) + "\n")
        f1.close()

    def write_to_file2(self, file_path, write_lists):
        f1 = open(file_path, "w", encoding='utf-8')
        for key in write_lists:
            vids = re.findall(r"\d+\.?\d*", key)
            write_key = ""
            for vid in vids:
                write_key = write_key + " " + str(vid)
            f1.write(write_key + "\n")
        f1.close()

    def read_from_file(self, file_path):
        write_lists = []
        with open(file_path) as f1:
            reader = csv.reader(f1, delimiter='#')
            for row in reader:
                write_lists.append(row[0])
        f1.close()
        return write_lists

    def exist_file(self, file_path):
        return os.path.exists(file_path)

    def _get_random_time(self, min_t, max_t):
        return random.randint(min_t, max_t)

    def _as_of(self, ts):
        return f" TT AS {ts}"

    def generate_where_clause(self, node):
        num = node[-1]
        match_clause = f"MATCH ({node})-[:OBJECT_ATTRIBUTE]-(:Attribute)-[:ATTRIBUTE_VALUE]-(val{num}:Value) "
        where_clause = f"WHERE val{num}.validTimeStart<=1699554954708916 AND val{num}.validTimeEnd>1699554954708916 "
        clause = match_clause + where_clause
        return clause

    def get_all_queries(self, query_size, min, max, gmark_query_path):
        cypher_lists = []
        TGQL_cypher_lists = []
        for index in range(query_size):
            file1 = f"{gmark_query_path}/query-{index}.cypher"
            get_lists = self.read_from_file(file1)
            q = get_lists[0]
            q_prefix = q.split("RETURN")[0]
            q_return = " RETURN " + q.split("RETURN")[1]
            q_return_rest = q.split("RETURN")[1].replace("DISTINCT", "").replace(";", "").replace(" ", "").replace(
                "\"true\"LIMIT1", "")
            q_return_obj = []
            tgql_opt_clause = ""
            if len(q_return_rest) > 0:
                q_return_obj = q_return_rest.split(",")
            if len(q_return_obj) != 0:
                for node in q_return_obj:
                    tgql_opt_clause = tgql_opt_clause + self.generate_where_clause(node)
            ts = self._get_random_time(min, max)
            cypher = q_prefix + self._as_of(ts) + q_return
            cypher_lists.append(cypher)
            tgql_cypher = q_prefix + tgql_opt_clause + q_return
            TGQL_cypher_lists.append(tgql_cypher)
        return cypher_lists,TGQL_cypher_lists

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="small",
                        help="Dataset size")
    parser.add_argument("--num-op",
                        default=80000,
                        help="The number of graph operation queries")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of reults")
    parser.add_argument("--max-time", type=int,
                        default=100,
                        help="Max time of the datasets life")
    parser.add_argument("--min-time", type=int,
                        default=0,
                        help="Min time of the datasets life")
    parser.add_argument("--query-size",
                        default=5,
                        help="Original gmark query sizes")
    parser.add_argument("--gmark-query-path",
                        default="/data/hjm/gMark/vldb_version/schemas/datasets/bib/bib-a-100k/query-limit/processed",
                        help="Original gmark queires")

    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")
    gmark = gMark(size="sf1", max_op=320000, update_ratio=1, delete_ratio=0)
    cypher_lists,TGQL_cypher_lists=gmark.get_all_queries(args.query_size, args.min_time, args.max_time, args.gmark_query_path)
    gmark.write_to_file(f"{args.write_path}/temporal_query/cypher.txt",cypher_lists)
    gmark.write_to_file(f"{args.write_path}/temporal_query/TGQL_cypher.txt",TGQL_cypher_lists)
    print("=========done!========")
