import random
import datetime
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

        self._id_to_be=SIZES[size]["vertices"]
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
        # 每一个类别节点create个数的上限
        self._create_person_num = int(self._max_create_op * 0.5 * 0.5)
        self._create_comment_num = int(self._max_create_op * 0.5 * 0.25)
        self._create_post_num = int(self._max_create_op/2)  - self._create_person_num - self._create_comment_num

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
            if "person" in file_path:
                self._update_person_lists = update_type_lists
            elif "comment" in file_path:
                self._update_comment_lists = update_type_lists
            elif "post" in file_path:
                self._update_post_lists = update_type_lists
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

    ###########generator###########
    def generate_random_timestamp(start_year, end_year):
        start_date = datetime.datetime(start_year, 1, 1)
        end_date = datetime.datetime(end_year, 12, 31)
        time_between_dates = end_date - start_date
        days_between_dates = time_between_dates.days
        random_number_of_days = random.randrange(days_between_dates)
        random_date = start_date + datetime.timedelta(days=random_number_of_days)
        random_timestamp = random_date.timestamp()
        # 生成随机的毫秒数
        random_ms = random.randint(0, 999)
        # 将毫秒数添加到时间戳中
        random_timestamp_with_ms = int(random_timestamp * 1000 + random_ms)
        return random_timestamp_with_ms

    def generate_random_string(min_length, max_length):
        length = random.randint(min_length, max_length)
        letters = string.ascii_letters
        random_string = ''.join(random.choices(letters, k=length))
        return random_string

    def generate_random_ip(self):
        ip = ".".join(str(random.randint(0, 255)) for _ in range(4))
        return ip

    ###########update query###########
    # update person
    def query_person_set_ip(self, v_id, gen_type):
        location_ip = self.generate_random_ip()
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

    ###########create query###########
    def query_add_person(self):
        self._id_to_be = self._id_to_be + 1
        tgql_query = ""
        query = ""
        head = ["id", "firstName", "lastName", "gender", "birthday", "creationDate", "locationIP", "browserUsed"]
        browser = self.browserUsed[random.randint(0, 3)]
        props = []
        pid = self._id_to_be
        props.append(str(pid))
        pFirst = self.generate_random_string(4, 8)
        props.append(pFirst)
        pLast = self.generate_random_string(4, 10)
        props.append(pLast)
        pGender = "male"
        if pid % 2 == 1:
            pGender = "female"
        props.append(pGender)
        pBirth = str(self.generate_random_timestamp(1970, 2000))
        props.append(pBirth)
        pCreate = str(self.generate_random_timestamp(2015, 2020))
        props.append(pCreate)
        pIP = self.generate_random_ip()
        props.append(pIP)
        props.append(browser)
        # tgdb
        query = f"CREATE (p:Person {{id: {pid},firstName:'{pFirst}',lastName:'{pLast}',gender:'{pGender}',birthday:{pBirth},creationDate:{pCreate},locationIP:'{pIP}',browserUsed:'{browser}'}});"
        # tgql
        node_id = f"Person{pid}"
        node_info = f"Create (n:Object {{ title:'Person',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
        # create id
        query_state = f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) " + \
                      f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{pid},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
        att_infos = " "
        for j in range(0, len(head)):
            attribute_name = head[j]
            attribute_value = props[j]
            if (attribute_name == "id"):
                continue
            if (attribute_value == ""):
                continue
            attribute_index = "a" + str(j)
            attribute_info = f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            value_info = f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            att_infos = att_infos + attribute_info + value_info
        tgql_query = node_info + query_state + att_infos
        return query, tgql_query

    def query_add_comment(self):
        self._id_to_be = self._id_to_be + 1
        tgql_query = ""
        query = ""
        head = ["id", "creationDate", "locationIP", "browserUsed", "content", "length"]
        props = []
        pid = self._id_to_be
        props.append(str(pid))
        pCreate = str(self.generate_random_timestamp(2015, 2020))
        props.append(pCreate)
        pIP = self.generate_random_ip()
        props.append(pIP)
        browser = self.browserUsed[random.randint(0, 3)]
        props.append(browser)
        pContent = self.generate_random_string(1, random.randint(1, 300))
        props.append(pContent)
        pLength = len(pContent)
        props.append(str(pLength))
        # tgdb
        query = f"CREATE (p:Comment {{id: {pid},creationDate:{pCreate},locationIP:'{pIP}',browserUsed:'{browser}',content:'{pContent}',length:'{pLength}'}});"
        # tgql
        node_id = f"Comment{pid}"
        node_info = f"Create (n:Object {{ title:'Comment',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
        # create id
        query_state = f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) " + \
                      f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{pid},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
        att_infos = " "
        for j in range(0, len(props)):
            attribute_name = head[j]
            attribute_value = props[j]
            if (attribute_name == "id"):
                continue
            if (attribute_value == ""):
                continue
            attribute_index = "a" + str(j)
            attribute_info = f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            value_info = f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            att_infos = att_infos + attribute_info + value_info
        tgql_query = node_info + query_state + att_infos
        return query, tgql_query

    def query_add_post(self):
        self._id_to_be = self._id_to_be + 1
        tgql_query = ""
        query = ""
        head = ["id", "creationDate", "locationIP", "browserUsed", "language", "content", "length"]
        props = []
        pid = self._id_to_be
        props.append(str(pid))
        pCreate = str(self.generate_random_timestamp(2015, 2020))
        props.append(pCreate)
        pIP = self.generate_random_ip()
        props.append(pIP)
        browser = self.browserUsed[random.randint(0, 3)]
        props.append(browser)
        pLanguage = self.generate_random_string(1, 4)
        props.append(pLanguage)
        pContent = self.generate_random_string(1, random.randint(1, 300))
        props.append(pContent)
        pLength = len(pContent)
        props.append(str(pLength))

        # tgdb
        query = f"CREATE (p:Post {{id: {pid},creationDate:{pCreate},locationIP:'{pIP}',browserUsed:'{browser}',language:'{pLanguage}',content:'{pContent}',length:'{pLength}'}});"
        # tgql
        node_id = f"Post{pid}"
        node_info = f"Create (n:Object {{ title:'Post',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
        # create id
        query_state = f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) " + \
                      f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{pid},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
        att_infos = " "
        for j in range(0, len(head)):
            attribute_name = head[j]
            attribute_value = props[j]
            if (attribute_name == "id"):
                continue
            if (attribute_value == ""):
                continue
            attribute_index = "a" + str(j)
            attribute_info = f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            value_info = f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            att_infos = att_infos + attribute_info + value_info
        tgql_query = node_info + query_state + att_infos
        return query, tgql_query

    def add_edge(from_node, edge_type, to_node):
        query = f"MATCH (n1 {{id:{from_node}}}),(n2 {{id:{to_node}}}) with n1, n2 Create (n1)-[:{edge_type}]-(n2);"
        tgql_query = f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 Create (o1)-[:{edge_type}]-(o2);"
        return query, tgql_query

    def _create(self):
        cypher_lists = []
        tgql_cypher_lists = []
        if (self._max_create_op == 0):
            return cypher_lists, tgql_cypher_lists
        person_edge_list = random.sample(self._update_person_lists, self._create_person_num)
        person_edge_list_2 = random.sample(self._update_person_lists, self._create_person_num)
        person_edge_list_3 = random.sample(self._update_person_lists, self._create_comment_num)
        person_edge_list_4 = random.sample(self._update_person_lists, self._create_post_num)
        comment_edge_list = random.sample(self._update_comment_lists, self._create_comment_num)
        post_edge_list = random.sample(self._update_post_lists, self._create_post_num)
        for i in range(self._create_person_num):
            create_query, tgql_create_query = self.query_add_person()
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
            create_query, tgql_create_query = self.add_edge(person_edge_list[i], "KNOWS", person_edge_list_2[i])
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
        for i in range(self._create_comment_num):
            create_query, tgql_create_query = self.query_add_comment()
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
            create_query, tgql_create_query = self.add_edge(person_edge_list_3[i], "LIKES", comment_edge_list[i])
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
        for i in range(self._create_post_num):
            create_query, tgql_create_query = self.query_add_post()
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
            create_query, tgql_create_query = self.add_edge(person_edge_list_4[i], "LIKES", post_edge_list[i])
            cypher_lists.append(create_query)
            tgql_cypher_lists.append(tgql_create_query)
        return cypher_lists, tgql_cypher_lists

    ######### delete query ############
    def delete_node(node_label, person_id):
        query = f"MATCH (p:Person {{id:{person_id}}})-[e]-() delete e, p;"
        tgql_query1 = f"MATCH (p:Object {{id:{node_label}{person_id}}})-[o:OBJECT_ATTRIBUTE]-(att)-[a:ATTRIBUTE_VALUE]-(v) delete o,a,att,v;"
        tgql_query2 = f"MATCH (p:Object {{id:{node_label}{person_id}}})-[e]-() delete e ,p;"
        return query, tgql_query1, tgql_query2

    def delete_edge(from_node, edge_type, to_node):
        query = f"MATCH (n1 {{id:{from_node}}})-[e:{edge_type}]-(n2 {{id:{to_node}}}) delete e;"
        tgql_query = f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 MATCH (o1)-[e:edge_type]-(o2) delete e;"
        return query, tgql_query

    def _delete(self):
        cypher_lists = []
        tgql_cypher_lists = []
        if (self._max_delete_op == 0):
            return cypher_lists, tgql_cypher_lists
        person_edge_list = random.sample(self._update_person_lists, self._create_person_num)
        comment_edge_list = random.sample(self._update_comment_lists, self._create_comment_num)
        post_edge_list = random.sample(self._update_post_lists, self._create_post_num)
        for i in range(self._create_person_num):
            delete_query, tgql_delete_query_1, tgql_delete_query_2 = self.delete_node("Person", person_edge_list[i])
            cypher_lists.append(delete_query)
            tgql_cypher_lists.append(tgql_delete_query_1)
            tgql_cypher_lists.append(tgql_delete_query_2)
        for i in range(self._create_comment_num):
            delete_query, tgql_delete_query_1, tgql_delete_query_2 = self.delete_node("Comment", comment_edge_list[i])
            cypher_lists.append(delete_query)
            tgql_cypher_lists.append(tgql_delete_query_1)
            tgql_cypher_lists.append(tgql_delete_query_2)
        for i in range(self._create_post_num):
            delete_query, tgql_delete_query_1, tgql_delete_query_2 = self.delete_node("Post", post_edge_list[i])
            cypher_lists.append(delete_query)
            tgql_cypher_lists.append(tgql_delete_query_1)
            tgql_cypher_lists.append(tgql_delete_query_2)
        return cypher_lists, tgql_cypher_lists

    def get_all_queries(self, ldbc_csv_path, write_path):
        peak_vertex_path = f"{write_path}peak_vertices"
        write_lists = []
        TGQL_write_lists = []
        # 1. get update vertex id lists 2.get queries
        self._update_person_lists=self._get_type_lists(f"{peak_vertex_path}/update_person_Num{self._max_graph_op}",
                             f"{ldbc_csv_path}/dynamic/person_0_0.csv", self._update_person_num)
        # 2.1 prepare for update query
        cypher_lists, tgql_cypher_lists = self._update_person()
        random.shuffle(cypher_lists)
        random.shuffle(tgql_cypher_lists)
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists

        self._update_comment_lists=self._get_type_lists(f"{peak_vertex_path}/update_comment_Num{self._max_graph_op}",
                             f"{ldbc_csv_path}/dynamic/comment_0_0.csv", self._update_comment_num)
        cypher_lists, tgql_cypher_lists = self._update_comment()
        random.shuffle(cypher_lists)
        random.shuffle(tgql_cypher_lists)
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists

        self._update_post_lists=self._get_type_lists(f"{peak_vertex_path}/update_post_Num{self._max_graph_op}",
                             f"{ldbc_csv_path}/dynamic/post_0_0.csv",
                             self._update_comment_num)
        cypher_lists, tgql_cypher_lists = self._update_post()
        random.shuffle(cypher_lists)
        random.shuffle(tgql_cypher_lists)
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        # 2.2. prepare for create query
        cypher_lists, tgql_cypher_lists = self._create()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        random.shuffle(write_lists)
        random.shuffle(TGQL_write_lists)
        # 2.3. prepare for delete query
        cypher_lists, tgql_cypher_lists = self._delete()
        write_lists += cypher_lists
        TGQL_write_lists += tgql_cypher_lists
        return write_lists, TGQL_write_lists


if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="sf0.1",
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
                        default="../../results/T-LDBC/",
                        help="The write path of reults")
    parser.add_argument("--ldbc-dataset-path",
                        default="../../datasets/T-LDBC/original_csv/",
                        help="The path of ldbc csv dataset")
    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")

    ldbc = LDBC(size=args.size, max_op=args.num_op, update_ratio=args.update_ratio, delete_ratio=args.delete_ratio)
    write_lists, tgql_write_lists = ldbc.get_all_queries(ldbc_csv_path=args.ldbc_dataset_path,
                                                         write_path=args.write_path)
    ldbc.write_to_file(f"{args.write_path}graph_op/cypher.txt", write_lists)
    ldbc.write_to_file(f"{args.write_path}graph_op/TGQL_cypher.txt", tgql_write_lists)
    print("=========done!========")
