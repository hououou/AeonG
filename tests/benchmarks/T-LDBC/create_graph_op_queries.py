import random
import csv
import os
import string
import numpy as np
import copy
import pandas as pd
import argparse

class LDBC():
    def __init__(self, size="sf1", max_op=100000, update_ratio=0.8, delete_ratio=0.1):
        SIZES = {
            "sf0.1": {"vertices": 327588, "edges": 1477965},
            "sf1": {"vertices": 3181724, "edges": 17256038},
            "sf3": {"vertices": 9281922, "edges": 52695735}
        }
        self.browserUsed = ["Firefox", "Internet Explorer", "Chrome", "Safari"]
        self._size = size
        self._num_vertices = SIZES[size]["vertices"]
        self._num_edges = SIZES[size]["edges"]
        self._max_graph_op = max_op
        self._max_update_op = int(self._max_graph_op * update_ratio)  # update操作的数量
        self._max_delete_op = int(self._max_graph_op * delete_ratio)  # delete操作的数量
        self._max_create_op = self._max_graph_op - self._max_update_op - self._max_delete_op  # create操作的数量

        self._count_update_num = 0
        # 每一个类别节点个数的上限
        self._update_person_num = int(self._max_update_op * 0.5)
        self._update_comment_num = int(self._max_update_op * 0.25)
        self._update_post_num = self._max_update_op - self._update_person_num - self._update_comment_num
        # 更新的节点id
        self._update_person_lists = []
        self._update_comment_lists = []
        self._update_post_lists = []

        ###########help function###########

    def ranstr(self, num):
        salt = ''.join(random.sample(string.ascii_letters + string.digits, num))
        return salt

    def write_to_file(self, file_path, write_lists):
        # print(file_path)
        # os.mknod(file_path)
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

    def ip_generator(self):
        ip = ""
        for i in range(4):
            temp = random.randrange(255)
            ip = ip + str(temp) + "."
        ip = ip[:-1]
        return ip

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

    def _get_type_lists(self, file_path, csv_path, update_type_num):
        # update peak vertex
        update_path = file_path + "_update.csv"
        update_count_path = file_path + "_update_count.csv"
        update_count_path_hot = file_path + "_update_count_hot.csv"
        update_count_path_warm = file_path + "_update_count_warm.csv"
        update_count_path_cold = file_path + "_update_count_cold.csv"
        if not self.exist_file(update_path):
            update_type_lists = []
            lines = open(csv_path).readlines()
            lens = len(lines)
            left = np.uint64(1)
            right = np.uint64(lens - 1)
            selected_lists = self.Zipf(1.1, left, right, update_type_num)
            for i in selected_lists:
                person_id = (lines[i].split("|"))[0]
                update_type_lists.append(person_id)
            self.write_to_file(file_path=update_path, write_lists=update_type_lists)
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

    ###########update query###########
    # update person
    def query_person_set_ip(self, v_id, gen_type):
        location_ip = self.ip_generator()
        query = ""
        if (gen_type == "Cypher"):
            query = f"MATCH (p:Person {{id: '{v_id}'}}) SET p.locationIP ='{location_ip}';"
        else:
            query_statement1 = " MATCH (n :Value{title:" + str(
                v_id) + "})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o{title: 'Person'}) "
            query = f" MATCH (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'locationIP' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1 = f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2 = f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{location_ip}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state = query_statement1 + query + query1 + query2
            query = query_state
        return query

    def query_person_set_browser(self, v_id, gen_type):
        browser = self.browserUsed[random.randint(0, 3)]
        query = ""
        if (gen_type == "Cypher"):
            query = f"MATCH (p:Person {{id: '{v_id}'}}) SET p.browserUsed ='{browser}';"
        else:
            query_statement1 = " MATCH (n :Value{title:" + str(
                v_id) + "})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o{title: 'Person'}) "
            query = f" MATCH (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'browserUsed' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1 = f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2 = f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{browser}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            query_state = query_statement1 + query + query1 + query2
            query = query_state
        return query

    # update comment
    def query_comment_set_content(self, comment_id, gen_type):
        content = self.ranstr(5)
        query = ""
        if (gen_type == "Cypher"):
            query = f"MATCH (c:Comment {{id: '{comment_id}'}}) SET c.content ='{content}';"
        else:
            query_statement1 = " MATCH (n :Value{title:" + str(
                comment_id) + "})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o{title: 'Comment'}) "
            query = f" MATCH (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'content' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1 = f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2 = f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{content}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state = query_statement1 + query + query1 + query2
            query = query_state
        return query

    # update post
    def query_post_set_content(self, post_id, gen_type):
        content = self.ranstr(5)
        query = ""
        if (gen_type == "Cypher"):
            query = f"MATCH (p:Post {{id: '{post_id}'}}) SET p.content ='{content}';"
        else:
            query_statement1 = " MATCH (n :Value{title:" + str(
                post_id) + "})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o{title: 'Post'}) "
            query = f" MATCH (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'content' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1 = f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2 = f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{content}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state = query_statement1 + query + query1 + query2
            query = query_state
        return query

    # TODO(Zhouyu): create query
    ###########create query###########
    def create_vertx(self):
        cypher_lists = []
        tgql_cypher_lists = []
        return cypher_lists, tgql_cypher_lists

    # TODO(Zhouyu): delete query
    ###########delete query###########
    def delete_edges(self):
        cypher_lists = []
        tgql_cypher_lists = []
        return cypher_lists, tgql_cypher_lists

    ###########update vertex property##############
    def _update_person(self):
        cypher_lists = []
        tgql_cypher_lists = []
        for person_id in self._update_person_lists:
            person_set_ip = self.query_person_set_ip(person_id, "Cypher")
            tgql_person_set_ip = self.query_person_set_ip(person_id, "TGQL")
            cypher_lists.append(person_set_ip)
            tgql_cypher_lists.append(tgql_person_set_ip)
            person_set_browser = self.query_person_set_browser(person_id, "Cypher")
            tgql_person_set_browser = self.query_person_set_browser(person_id, "TGQL")
            cypher_lists.append(person_set_browser)
            tgql_cypher_lists.append(tgql_person_set_browser)
        return cypher_lists, tgql_cypher_lists

    def _update_comment(self):
        cypher_lists = []
        tgql_cypher_lists = []
        for comment_id in self._update_comment_lists:
            cypher_comment = self.query_comment_set_content(comment_id, "Cypher")
            tgql_comment = self.query_comment_set_content(comment_id, "TGQL")
            cypher_lists.append(cypher_comment)
            tgql_cypher_lists.append(tgql_comment)
        return cypher_lists, tgql_cypher_lists

    def _update_post(self):
        cypher_lists = []
        tgql_cypher_lists = []
        for post_id in self._update_post_lists:
            cypher_post = self.query_post_set_content(post_id, "Cypher")
            tgql_post = self.query_post_set_content(post_id, "TGQL")
            cypher_lists.append(cypher_post)
            tgql_cypher_lists.append(tgql_post)
        return cypher_lists, tgql_cypher_lists

    def get_all_queries(self, ldbc_csv_path, write_path):
        peak_vertex_path = f"{write_path}peak_vertices"
        write_lists = []
        TGQL_write_lists = []
        # 1. get update vertex id lists 2.get queries
        self._get_type_lists(f"{peak_vertex_path}/update_person_Num{self._max_graph_op}",
                             f"{ldbc_csv_path}/person_0_0.csv", self._update_person_num)
        cypher_lists, tgql_cypher_lists = self._update_person()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists

        self._get_type_lists(f"{peak_vertex_path}/update_comment_Num{self._max_graph_op}",
                             f"{ldbc_csv_path}/comment_0_0.csv", self._update_comment_num)
        cypher_lists, tgql_cypher_lists = self._update_comment()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists

        self._get_type_lists(f"{peak_vertex_path}/update_post_Num{self._max_graph_op}", f"{ldbc_csv_path}/post_0_0.csv",
                             self._update_comment_num)
        cypher_lists, tgql_cypher_lists = self._update_post()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists

        random.shuffle(write_lists)
        random.shuffle(TGQL_write_lists)
        return write_lists,TGQL_write_lists



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
    parser.add_argument("--update-ratio",
                        default=0.8,
                        help="The update ratio of graph operation queries")
    parser.add_argument("--delete-ratio",
                        default=0.1,
                        help="The delete ratio of graph operation queries")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of reults")
    parser.add_argument("--ldbc-dataset-path",
                        default="/data/hjm/social_network-csv_basic-sf1/csv/standard/",
                        help="The path of ldbc csv dataset")
    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")

    ldbc = LDBC(size=args.size, max_op=args.num_op, update_ratio=args.update_retio, delete_ratio=args.delete_retio)
    write_lists, tgql_write_lists=ldbc.get_all_queries(ldbc_csv_path=args.ldbc_dataset_path, write_path=args.write_path)
    ldbc.write_to_file(f"{args.write_path}graph_op/cypher.txt", write_lists)
    ldbc.write_to_file(f"{args.write_path}graph_op/TGQL_cypher.txt", tgql_write_lists)
    print("=========done!========")
