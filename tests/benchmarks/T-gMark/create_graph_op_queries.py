import random
import csv
import os
import string
import numpy as np
import copy
import pandas as pd
import argparse

class gMark():
    def __init__(self, size="sf1", max_op=10000, update_ratio=0.8, delete_ratio=0.1):
        SIZES = {
            "sf1": {"vertices": 100000, "edges": 239737}
        }
        self._size = size
        self._num_vertices = SIZES[size]["vertices"]
        self._num_edges = SIZES[size]["edges"]
        self._max_graph_op = max_op
        self._id_to_be=SIZES[size]["vertices"]
        self._max_update_op = int(self._max_graph_op * update_ratio)  # update操作的数量
        self._max_delete_op = int(self._max_graph_op * delete_ratio)  # delete操作的数量
        self._max_create_op = self._max_graph_op - self._max_update_op - self._max_delete_op  # create操作的数量
        # 更新的节点id
        self._update_node_lists = []
        # 每一个类别create操作的个数上限
        self._create_node_num = int(self._max_create_op / 2)
        self._create_edge_num = self._max_create_op - self._create_node_num

    ###########help function###########
    def ranstr(self, num):
        salt = ''.join(random.sample(string.ascii_letters + string.digits, num))
        return salt

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
    def get_csv_nodes(self,file_path):
        write_lists=[]
        with open(file_path) as f1:
            reader = csv.reader(f1, delimiter='|')
            for row in reader:
                write_lists.append(row[0])
        f1.close()
        return write_lists

    def exist_file(self, file_path):
        return os.path.exists(file_path)

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

    def _get_type_lists(self, file_path, csv_path):
        # update peak vertex
        file_path2 = file_path.replace(".csv", "")
        update_path = file_path2 + "_update.csv"
        update_count_path = file_path2 + "_update_count.csv"
        update_count_path_hot = file_path2 + "_update_count_hot.csv"
        update_count_path_warm = file_path2 + "_update_count_warm.csv"
        update_count_path_cold = file_path2 + "_update_count_cold.csv"
        if not self.exist_file(update_path) :
            # write peak vertex
            update_type_lists = []
            id_lists = self.get_csv_nodes(csv_path)
            lens = len(id_lists)
            # print(lens)
            left = np.uint64(1)
            right = np.uint64(lens - 1)  # 文件的行数
            selected_lists = self.Zipf(1.1, left, right, self._max_update_op)
            for i in selected_lists:
                update_id = id_lists[i]
                update_type_lists.append(update_id)

            self.write_to_file(file_path=update_path, write_lists=update_type_lists)
            self._update_node_lists=update_type_lists
            # write vertex count
            data = pd.value_counts(update_type_lists)
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
            return update_type_lists
        else:
            return self.read_from_file(update_path)

    ########### update query ###########
    def update_query(self, v_id):
        query = f"MATCH (c:Node {{id: '{v_id}'}}) SET c.name ={self._num_vertices};"
        tgql_query = f" MATCH (n :Object {{id:{v_id}}})-[:OBJECT_ATTRIBUTE]-(a:Attribute {{title:'name'}})-[:ATTRIBUTE_VALUE]-(v:Value) " + \
                     " where v.validTimeEnd=9223372036854775000 " + \
                     " set v.validTimeEnd=timestamp() " + \
                     f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title: '{self._num_vertices}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}});"
        self._num_vertices += 1
        return query, tgql_query

    def _update(self, update_id_lists):
        tgdb_write_lists = []
        tgql_write_lists = []
        for update_id in update_id_lists:
            query, tgql_query = self.update_query(update_id)
            tgdb_write_lists.append(query)
            tgql_write_lists.append(tgql_query)
        random.shuffle(tgdb_write_lists)
        random.shuffle(tgql_write_lists)
        return tgdb_write_lists, tgql_write_lists

    ######## add query #########
    def add_node(self):
        self._id_to_be = self._id_to_be + 1
        query=f"Create (n:Node {{id:{self._id_to_be}}})"
        tgql_query=f"Create (n:Object {{ title:'Node',id:{self._id_to_be},validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }}) Create (n)-[:OBJECT_ATTRIBUTE]->(att:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (att)-[:ATTRIBUTE_VALUE]->(:Value {{title:0,validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (n)-[:OBJECT_ATTRIBUTE]->(att2:Attribute {{title:'name',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (att2)-[:ATTRIBUTE_VALUE]->(:Value {{title:0,validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) ;"
        return query,tgql_query
    def add_edge(self,from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}}),(n2 {{id:{to_node}}}) with n1, n2 Create (n1)-[:{edge_type}]->(n2);"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 Create (o1)-[:edge_type]-(o2);"
        return query,tgql_query

    def _create(self):
        cypher_lists = []
        tgql_cypher_lists = []
        if self._max_create_op == 0:
            return cypher_lists, tgql_cypher_lists
        node_edge_list_1=random.sample(self._update_node_lists,self._create_edge_num)
        node_edge_list_2=random.sample(self._update_node_lists,self._create_edge_num)
        for i in range(self._create_node_num):
            create_query,tgql_create_query=self.add_node()
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
        for i in range(self._create_edge_num):
            create_query,tgql_create_query=self.add_edge(node_edge_list_1[i],"RELATES",node_edge_list_2[i])
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
        return cypher_lists,tgql_cypher_lists

    ######### delete query ############
    def delete_node(self,node_label,v_id):
        query=f"MATCH (c:Node {{id: '{v_id}'}})-[e]-() delete e, c;"
        tgql_query1=f"MATCH (p:Object {{id:{node_label}{v_id}}})-[o:OBJECT_ATTRIBUTE]-(att)-[a:ATTRIBUTE_VALUE]-(v) delete o,a,att,v;"
        tgql_query2=f"MATCH (p:Object {{id:{node_label}{v_id}}})-[e]-() delete e,p;"
        return query, tgql_query1,tgql_query2

    def delete_edge(self,from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}})-[e:{edge_type}]-(n2 {{id:{to_node}}}) delete e;"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 MATCH (o1)-[e:edge_type]-(o2) delete e;"
        return query,tgql_query

    def _delete(self):
        cypher_lists = []
        tgql_cypher_lists = []
        if self._max_delete_op == 0:
            return cypher_lists, tgql_cypher_lists
        node_edge_list=random.sample(self._update_node_lists,self._create_node_num)
        for to_do in node_edge_list:
            delete_query,tgql_delete_query_1, tgql_delete_query_2=self.delete_node("Node",to_do)
            cypher_lists.append(delete_query)
            tgql_cypher_lists.append(tgql_delete_query_1)
            tgql_cypher_lists.append(tgql_delete_query_2)
        return cypher_lists,tgql_cypher_lists

    def get_all_queries(self,dataset_path,write_path):
        peak_vertex_path = f"{write_path}peak_vertices"
        write_lists = []
        TGQL_write_lists = []
        # 1. get update vertex id lists 2.get queries
        update_id_lists=self._get_type_lists(f"{args.write_path}peak_vertices/update_Num{gmark._max_graph_op}", args.gmark_dataset_path)
        self._update_node_lists = update_id_lists
        # 2.1 prepare for update query
        cypher_lists, tgql_cypher_lists = self._update(update_id_lists)
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        # 2.2 prepare for create query
        cypher_lists, tgql_cypher_lists = self._create()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        random.shuffle(write_lists)
        random.shuffle(TGQL_write_lists)
        # 2.3. prepare for delete query
        cypher_lists, tgql_cypher_lists = self._delete()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        return write_lists,TGQL_write_lists

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="sf1",
                        help="Dataset size")
    parser.add_argument("--num-op", type=int,
                        default=80000,
                        help="The number of graph operation queries")
    parser.add_argument("--update-ratio", type=float,
                        default=1,
                        help="The update ratio of graph operation queries")
    parser.add_argument("--delete-ratio", type=float,
                        default=0,
                        help="The delete ratio of graph operation queries")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of reults")
    parser.add_argument("--gmark-dataset-path",
                        default="/data/hjm/gMark/datasets/bibiographical/schema/test-a-graph.csv",
                        help="The path of ldbc csv dataset")
    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")

    gmark = gMark(size=args.size, max_op=args.num_op)
    ##### graph operatios generation #####
    write_lists, tgql_write_lists=gmark.get_all_queries(dataset_path=args.gmark_dataset_path, write_path=args.write_path)
    gmark.write_to_file(f"{args.write_path}graph_op/cypher.txt", write_lists)
    gmark.write_to_file(f"{args.write_path}graph_op/TGQL_cypher.txt", tgql_write_lists)
    print("=========done!========")
