import random
import csv
import os
import re
import numpy as np
import copy
import pandas as pd
import argparse

class mgbench():
    def __init__(self, size="small", dataset_path="../../datasets/T-mgBench/", max_ops=80000, update_ratio=0.8, delete_ratio=0.1):
        SIZES = {
            "small": {"vertices": 10000, "edges": 121716},
            "medium": {"vertices": 100000, "edges": 1768515},
            "large": {"vertices": 1632803, "edges": 30622564},
        }

        Dataset = {
            "small": dataset_path+"small.cypher",
            "medium": dataset_path+"medium.cypher",
            "large": dataset_path+"large.cypher",
        }

        self._size = size
        self._num_vertices = SIZES[size]["vertices"]
        self._num_edges = SIZES[size]["edges"]
        self._dataset_file_path = Dataset[size]
        self._max_graph_op = max_ops  # 图操作的数量
        self._max_update_op = int(self._max_graph_op * update_ratio)  # update操作的数量
        self._max_delete_op = int(self._max_graph_op * delete_ratio)  # delete操作的数量
        self._max_create_op = self._max_graph_op - self._max_update_op - self._max_delete_op  # create操作的数量

        self._update_vertices_lists = []  # 更新的节点
        self._create_vertices_lists = []  # 创建的节点
        self._create_edge_lists = []  # 创建的边
        self._delete_edge_lists = []  # 删除的边
        self._count_update_num = 0

    #####help function#####
    def Zipf(self, a: np.float64, min: np.uint64, max: np.uint64, size=None):
        """
        Generate Zipf-like random variables,
        but in inclusive [min...max] interval
        """
        if min == 0:
            raise ZeroDivisionError("")

        values = np.arange(min, max + 1, dtype=np.uint64)  # values to sample
        index = copy.deepcopy(values)
        np.random.shuffle(values)
        p = 1.0 / np.power(index - min + 1, a)  # probabilities
        p /= np.sum(p)  # normalized

        return np.random.choice(values, size=size, replace=True, p=p)

    def _get_random_vertex_u(self):
        # All vertices in the Pokec dataset have an ID in the range
        # [1, _num_vertices].
        # print("here")
        return random.randint(1, self._num_vertices)

    def _get_random_num(self):
        return random.randint(1, 100)

    def write_to_file(self, file_path, write_lists):
        f1 = open(file_path, "w", encoding='utf-8')
        for key in write_lists:
            f1.write(str(key) + "\n")
        f1.close()

    def read_from_file(self, file_path):
        write_lists = []
        with open(file_path) as f1:
            reader = csv.reader(f1, delimiter=',')
            for row in reader:
                write_lists.append(row[0])
        f1.close()
        return write_lists

    def exist_file(self, file_path):
        return os.path.exists(file_path)

    def _get_random_vertex(self):
        max_vertex = int(self._max_create_op / 2)
        return random.randint(self._num_vertices, self._num_vertices + max_vertex)

    def _get_random_from_to(self):
        vertex_from = self._get_random_vertex()
        vertex_to = vertex_from
        while vertex_to == vertex_from:
            vertex_to = self._get_random_vertex()
        return (vertex_from, vertex_to)

    def _get_random_from_to_str(self):
        vertex_from = self._get_random_vertex()
        vertex_to = vertex_from
        while vertex_to == vertex_from:
            vertex_to = self._get_random_vertex()
        return str(vertex_from) + "#" + str(vertex_to)

    def get_various_id_lists(self, file_path):
        # update peak vertex
        update_path = file_path + "_update.csv"
        update_count_path = file_path + "_update_count.csv"
        update_count_path_hot = file_path + "_update_count_hot.csv"
        update_count_path_warm = file_path + "_update_count_warm.csv"
        update_count_path_cold = file_path + "_update_count_cold.csv"
        if not self.exist_file(update_path):
            # write peak vertex
            left = np.uint64(1)
            right = np.uint64(self._num_vertices)
            self._update_vertices_lists = self.Zipf(1.1, left, right, self._max_update_op)
            self.write_to_file(file_path=update_path, write_lists=self._update_vertices_lists)
            # write vertex count
            data = pd.value_counts(self._update_vertices_lists)
            data.to_csv(update_count_path, header=False)
            # write hot, warm, cold
            total_count = data.sum()  # 计算概率质量函数 (PMF)
            pmf = data / total_count
            cdf = np.cumsum(pmf)  # 计算累积分布函数 (CDF)
            data_quantile1 = data[cdf <= 0.3]
            data_quantile2 = data[(cdf > 0.3) & (cdf <= 0.6)]
            data_quantile3 = data[cdf > 0.6]
            data_quantile1.to_csv(update_count_path_hot, header=False)
            data_quantile2.to_csv(update_count_path_warm, header=False)
            data_quantile3.to_csv(update_count_path_cold, header=False)
        else:
            self._update_vertices_lists = self.read_from_file(update_path)

        # create vertex
        max_vertex = int(self._max_create_op / 2)
        create_v_path = file_path + "_create_vertex.csv"
        if not self.exist_file(create_v_path):
            self._create_vertices_lists = list(range(self._num_vertices, self._num_vertices + max_vertex))
            self.write_to_file(file_path=create_v_path, write_lists=self._create_vertices_lists)
        else:
            self._create_vertices_lists = self.read_from_file(create_v_path)

        # create edge
        create_e_path = file_path + "_create_edge.csv"
        if not self.exist_file(create_e_path):
            for i in range(max_vertex):
                self._create_edge_lists.append(self._get_random_from_to_str())
            self.write_to_file(file_path=create_e_path, write_lists=self._create_edge_lists)
        else:
            self._create_edge_lists = self.read_from_file(create_e_path)

        # delete edge
        delete_edge_lists = []
        delete_e_path = file_path + "_delete.csv"
        if not self.exist_file(delete_e_path):
            with open(self._dataset_file_path, "r") as f:
                vid_sets = set()
                lines = f.readlines()
                resultlists = random.sample(range(self._num_vertices + 1, self._num_vertices + self._num_edges),
                                            self._max_delete_op)
                for i in resultlists:
                    query = str(lines[i])
                    vids = re.findall(r"\d+\.?\d*", query)
                    if len(vids) < 2:
                        continue
                    self._delete_edge_lists.append(str(vids[0]) + "#" + str(vids[1]))
            self.write_to_file(file_path=delete_e_path, write_lists=self._delete_edge_lists)
        else:
            self._delete_edge_lists = self.read_from_file(delete_e_path)

    ######graph operation#######
    def check_count_num(self):
        return self._count_update_num >= self._max_update_op

    def _update__vertex_on_property(self, v_id):
        query_statement = " MATCH (n:User {id:" + str(v_id) + "}) SET n.completion_percentage = " + str(
            self._get_random_num()) + ";"
        # this query is special for T-GQL
        query_statement2 = " MATCH (n :Value{title:" + str(
            v_id) + "})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o:Object{title: 'User'}) " + \
                           " Match (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute { title:'completion_percentage' })-[:ATTRIBUTE_VALUE]->(v:Value) " + \
                           " where v.validTimeEnd=9223372036854775000 " + \
                           " set v.validTimeEnd=timestamp() " + \
                           " Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {title:" + str(self._get_random_num()) + \
                           ", validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) ;"
        return query_statement, query_statement2

    def _create_vertex(self, v_id):
        create_q = "CREATE (n:User {id : " + str(v_id) + "}) set n.completion_percentage = " + str(
            self._get_random_num()) + " RETURN n ;"
        query_state = " Create (n:Object{ title:'User',id:" + str(
            v_id) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a1:Attribute {title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a2:Attribute {title:'completion_percentage',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a1)-[:ATTRIBUTE_VALUE]->(:Value {title:" + str(
            v_id) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a2)-[:ATTRIBUTE_VALUE]->(:Value {title:" + str(
            self._get_random_num()) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "
        return create_q, query_state

    def _create_edge(self, vertex_from, vertex_to):
        create_q = "MATCH (a:User {id:" + str(vertex_from) + "}), (b:User {id: " + str(
            vertex_to) + "}) CREATE (a)-[:Friend]->(b);"
        create_q2 = " Match (n:Object{ id:" + str(vertex_from) + " }), (m:Object{ id:" + str(vertex_to) + "})" + \
                    " Create (n)-[e:Friend]->(m) set e.validTimeStart=timestamp(), e.validTimeEnd=9223372036854775000"
        return (create_q, create_q2)

    def _delete_edges(self, vid_from, vid_to):
        del_query = "MATCH (n:User {id:" + str(vid_from) + "})-[e]->(m:User {id:" + str(vid_to) + "}) DELETE e  ;"
        delete_q = " Match (n:Object{ id:" + str(vid_from) + " })-[e]->(m:Object{ id:" + str(vid_to) + "})" + \
                   " where e.validTimeEnd=9223372036854775000 set e.validTimeEnd=timestamp();"
        return (del_query, delete_q)

    def get_all_queries(self):
        write_lists = []
        TGQL_write_lists = []
        use_flag = 1
        update_v_idx = 0
        create_v_idx = 0
        create_e_idx = 0
        delete_e_idx = 0
        for i in range(self._max_graph_op):
            if use_flag <= 8:
                use_flag += 1
                if update_v_idx < len(self._update_vertices_lists):
                    update_id = self._update_vertices_lists[update_v_idx]
                    update_v_idx += 1
                    update_q, update_q2 = self._update__vertex_on_property(update_id)
                    write_lists.append(update_q)
                    TGQL_write_lists.append(update_q2)
            else:
                use_flag = 1
                # create vertex
                if create_v_idx < len(self._create_vertices_lists):
                    create_id = self._create_vertices_lists[create_v_idx]
                    create_q, create_q2 = self._create_vertex(create_id)
                    create_v_idx += 1
                    write_lists.append(create_q)
                    TGQL_write_lists.append(create_q2)
                # create edge
                if create_e_idx < len(self._create_edge_lists):
                    create_e_id = self._create_edge_lists[create_e_idx]
                    ids = create_e_id.split("#")
                    create_e_from = ids[0]
                    create_e_to = ids[1]
                    create_e_q, create_e_q2 = self._create_edge(create_e_from, create_e_to)
                    create_e_idx += 1
                    write_lists.append(create_e_q)
                    TGQL_write_lists.append(create_e_q2)
                # delete edge
                if delete_e_idx < len(self._delete_edge_lists):
                    delete_e_id = self._delete_edge_lists[delete_e_idx]
                    ids = delete_e_id.split("#")
                    delete_e_from = ids[0]
                    delete_e_to = ids[1]
                    delete_e_q, delete_e_q2 = self._delete_edges(delete_e_from, delete_e_to)
                    delete_e_idx += 1
                    write_lists.append(delete_e_q)
                    TGQL_write_lists.append(delete_e_q2)
        return write_lists, TGQL_write_lists

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="small",
                        help="Dataset size")
    parser.add_argument("--num-op", type=int,
                        default=80000,
                        help="The number of graph operation queries")
    parser.add_argument("--update-ratio",
                        default=0.8,
                        help="The update ratio of graph operation queries")
    parser.add_argument("--delete-ratio",
                        default=0.1,
                        help="The delete ratio of graph operation queries")
    parser.add_argument("--dataset-path",
                        default="../../datasets/T-mgBench/",
                        help="The original dataset path")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of results")
    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")
    mgbench = mgbench(args.size, args.dataset_path, args.num_op, args.update_ratio, args.delete_ratio)
    file_name = "num" + str(mgbench._max_graph_op)
    # get update node ids and cache in the file
    mgbench.get_various_id_lists(args.write_path + "peak_vertices/" + file_name)
    # get all queries
    cypher, TGQL_cypher = mgbench.get_all_queries()
    # write cypher queries
    mgbench.write_to_file(args.write_path + "graph_op/cypher.txt", cypher)
    mgbench.write_to_file(args.write_path + "graph_op/TGQL_cypher.txt", TGQL_cypher)
    print("=========done!========")