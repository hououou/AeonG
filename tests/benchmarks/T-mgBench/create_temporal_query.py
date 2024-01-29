import random
import csv
import os
import argparse


class mgbench():
    def __init__(self, size="small", max_ops=80000):
        SIZES = {
            "small": {"vertices": 10000, "edges": 121716},
            "medium": {"vertices": 100000, "edges": 1768515},
            "large": {"vertices": 1632803, "edges": 30622564},
        }

        Dataset = {
            "small": "../../datasets/T-mgBench/small.cypher",
            "medium": "../../datasets/T-mgBench/medium.cypher",
            "large": "../../datasets/T-mgBench/large.cypher",
        }

        self._size = size
        self._num_vertices = SIZES[size]["vertices"]
        self._num_edges = SIZES[size]["edges"]
        self._dataset_file_path = Dataset[size]
        self._max_graph_op = max_ops  # 图操作的数量
        self._count_update_num = 0
        self._query_vertex_list = []

    # help function
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

    ######create graph operations#######
    def _get_vertex_list(self, file_path, types):
        if len(self._query_vertex_list) < 100:
            hot_vertex_path = file_path.replace("count", "count_hot")
            warm_vertex_path = file_path.replace("count", "count_warm")
            cold_vertex_path = file_path.replace("count", "count_cold")
            hot_vertex = self.read_from_file(hot_vertex_path)
            print(hot_vertex)
            warm_vertex = self.read_from_file(warm_vertex_path)
            cold_vertex = self.read_from_file(cold_vertex_path)
            hot_target_vertex = []
            warm_target_vertex = []
            cold_target_vertex = []
            while len(hot_target_vertex) < 100:
                if len(hot_vertex) >= 100:
                    hot_target_vertex = hot_target_vertex + random.sample(hot_vertex, 100)
                else:
                    hot_target_vertex = hot_target_vertex + hot_vertex
            while len(warm_target_vertex) < 100:
                if len(warm_vertex) >= 100:
                    warm_target_vertex = warm_target_vertex + random.sample(warm_vertex, 100)
                else:
                    warm_target_vertex = warm_target_vertex + warm_vertex
            while len(cold_target_vertex) < 100:
                if len(cold_vertex) >= 100:
                    cold_target_vertex = cold_target_vertex + random.sample(cold_vertex, 100)
                else:
                    cold_target_vertex = cold_target_vertex + cold_vertex
            if types == "hot":
                self._query_vertex_list = hot_target_vertex
            if types == "warm":
                self._query_vertex_list = warm_target_vertex
            if types == "cold":
                self._query_vertex_list = cold_target_vertex
            if types == "mix":
                self._query_vertex_list = hot_target_vertex[:33] + cold_target_vertex[:33] + cold_vertex[:33]
        return self._query_vertex_list

    def _get_random_time(self,min_t,max_t):
        return random.randint(min_t, max_t)

    def _get_random_time_pair(self, min_t, max_t, interval):
        t_s = self._get_random_time(min_t, max_t - interval)  # int(min_t + (max_t - min_t) / 2)#
        return t_s, t_s + interval

    # read
    def _q1_(self, vid):
        return "MATCH (r:User{id : " + str(vid) + "}) "

    def _q2_(self, vid):
        return "MATCH (n:User{id : " + str(vid) + "})-[e]->(r) "

    def _as_of(self, t):
        return " TT AS " + str(t)

    def _from_to(self, t1, t2):
        return " TT FROM " + str(t1) + " TO " + str(t2)

    def _return_q1(self):
        return " RETURN r;"

    def _return_q2(self):
        return " RETURN n,e,r;"

    def _tgql_q1(self, userid, ts, te):
        tq_head = "MATCH (n:Object {title:'User'})-[:OBJECT_ATTRIBUTE]-(:Attribute {title:'id'})-[:ATTRIBUTE_VALUE]-(:Value {title:" + userid + "})," + \
                  " (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val:Value) "
        tq_condition = " where n.validTimeStart<=" + str(te) + " and n.validTimeEnd>" + str(ts) + " " \
                       + " and val.validTimeStart<=" + str(te) + " and val.validTimeEnd>" + str(ts) + " "
        tq_return = " return n,e1,att,e2,val ;"
        return tq_head + tq_condition + tq_return

    def _tgql_q2(self, userid, ts, te):
        query = f"""MATCH (n:Object {{title:'User'}})-[ne:OBJECT_ATTRIBUTE]-(na:Attribute {{title:'id'}})-[ne2:ATTRIBUTE_VALUE]-(nval:Value) where nval.title={userid} 
        with n match (n)-[ne]-(na2:Attribute)-[ne2:ATTRIBUTE_VALUE]-(nval2:Value)  
        where nval2.validTimeStart<={te} and nval2.validTimeEnd>{ts}
        with n,ne,na2,ne2,nval2
        match (n)-[friend:Friend]->(p:Object)
        with n,friend, p,ne,na2,ne2,nval2
        match (p)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val2:Value)  
        where val2.validTimeStart<={te} and val2.validTimeEnd>{ts} 
        return n,friend,p,e1,att,e2,val2,ne,na2,ne2,nval2
        """
        return query.replace("\n", " ")

    def _get_cypher_query(self, vid, ts, te):
        q1_as_of = self._q1_(vid) + self._as_of(ts) + self._return_q1()
        q1_from_to = self._q1_(vid) + self._from_to(ts, te) + self._return_q1()
        q2_as_of = self._q2_(vid) + self._as_of(ts) + self._return_q2()
        q2_from_to = self._q2_(vid) + self._from_to(ts, te) + self._return_q2()
        return q1_as_of, q1_from_to, q2_as_of, q2_from_to

    def _get_TGQL_cypher_query(self, vid, ts, te):
        q1_as_of = self._tgql_q1(vid, ts, ts)
        q1_from_to = self._tgql_q1(vid, ts, te)
        q2_as_of = self._tgql_q2(vid, ts, ts)
        q2_from_to = self._tgql_q2(vid, ts, te)
        return q1_as_of, q1_from_to, q2_as_of, q2_from_to

    def Q(self, file_path, type_name, min, max, interval, frequent_type):
        query_id_path = file_path.replace("count", f"{frequent_type}_ids")
        vid_lists = []
        if self.exist_file(query_id_path):
            vid_lists = self.read_from_file(query_id_path)
        else:
            vid_lists = self._get_vertex_list(file_path, frequent_type)
            self.write_to_file(query_id_path, vid_lists)
        num = 0
        q1_lists = []
        q2_lists = []
        q3_lists = []
        q4_lists = []
        while (True):
            for vid in vid_lists:
                ts, te = self._get_random_time_pair(min, max, interval)
                if type_name == "Cypher":
                    q1_as_of, q1_from_to, q2_as_of, q2_from_to = self._get_cypher_query(vid, ts, te)
                    q1_lists.append(q1_as_of)
                    q2_lists.append(q1_from_to)
                    q3_lists.append(q2_as_of)
                    q4_lists.append(q2_from_to)
                if type_name == "T-GQL":
                    q1_as_of, q1_from_to, q2_as_of, q2_from_to = self._get_TGQL_cypher_query(vid, ts, te)
                    q1_lists.append(q1_as_of)
                    q2_lists.append(q1_from_to)
                    q3_lists.append(q2_as_of)
                    q4_lists.append(q2_from_to)
                num += 1
                if num >= 100:
                    break
            if num >= 100:
                break
        return q1_lists, q2_lists, q3_lists, q4_lists


if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="small",
                        help="Dataset size")
    parser.add_argument("--num-op",type=int,
                        default=80000,
                        help="The number of graph operation queries")
    parser.add_argument("--max-time",type=int,
                        default=100,
                        help="Max time of the datasets life")
    parser.add_argument("--min-time", type=int,
                        default=0,
                        help="Min time of the datasets life")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of reults")
    parser.add_argument("--interval",
                        default=100,
                        help="Interval of time-slice queries")
    parser.add_argument("--frequency-type",
                        default="mix",
                        help="Frequency type of temporal queries")
    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")
    mgbench = mgbench(args.size, args.num_op)
    prefix = "num" + str(mgbench._max_graph_op)
    peak_vertices_path = args.write_path + "peak_vertices/" + prefix + "_update_count.csv"
    print("=========writing temporal queries========")
    q1_lists, q2_lists, q3_lists, q4_lists = mgbench.Q(peak_vertices_path, "Cypher", args.min_time, args.max_time, args.interval, args.frequency_type)
    mgbench.write_to_file(args.write_path + "temporal_query/cypher_Q1.txt", q1_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/cypher_Q2.txt", q2_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/cypher_Q3.txt", q3_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/cypher_Q4.txt", q4_lists)

    print("=========writing T-GQL temporal queries========")
    q1_lists, q2_lists, q3_lists, q4_lists = mgbench.Q(peak_vertices_path, "T-GQL", args.min_time, args.max_time, args.interval, args.frequency_type)
    mgbench.write_to_file(args.write_path + "temporal_query/TGQL_cypher_Q1.txt", q1_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/TGQL_cypher_Q2.txt", q2_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/TGQL_cypher_Q3.txt", q3_lists)
    mgbench.write_to_file(args.write_path + "temporal_query/TGQL_cypher_Q4.txt", q4_lists)
    print("=========done!========")
