import random
import csv
import os
import re

#用于测试temporal query 的running time
class TPokec():
    def __init__(self,size="large",max_op_ratio=0.1,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100):
        SIZES = {
        "small": {"vertices": 10000, "edges": 121716},
        "medium": {"vertices": 100000, "edges": 1768515},
            "large": {"vertices": 1632803, "edges": 30622564},
         }

        Dataset = {
        "small": "/datasets/pokec/small/dataset.cypher",
        "medium": "/dataset/pokec/medium/pokec_medium_import.cypher",
        "large":"/datasets/pokec/large/dataset.cypher",
        }

        self._size=size
        self.max_op_ratio=max_op_ratio
        self.update_ratio=update_ratio
        self.delete_ratio=delete_ratio
        self.create_ratio=create_ratio
        self.avg_update_ratio=avg_update_ratio
        self._num_vertices=SIZES[size]["vertices"]
        self._num_edges=SIZES[size]["edges"]
        self._dataset_file_path=Dataset[size]
        self._max_graph_op=self.max_op_ratio#100000#int(self._num_vertices*self.max_op_ratio) #图操作的数量
        self._max_update_op=int(self._max_graph_op*update_ratio) #update操作的数量
        self._max_delete_op=int(self._max_graph_op*delete_ratio) #delete操作的数量
        self._max_create_op=self._max_graph_op-self._max_update_op-self._max_delete_op  #create操作的数量

        self._avg_update_ratio=avg_update_ratio #平均每个节点更新的次数
        self._update_vertices_lists=[] #更新的节点
        self._update_vertices_num=int(self._max_update_op/self._avg_update_ratio) #更新节点的数目
        self._count_update_num=0
        self._query_vertex_list=[]
        self._tgql_vertex_list=[]
        print("max_graph_op",self._max_graph_op)
        print("update_op",self._max_update_op)
        print("self._avg_update_ratio",self._avg_update_ratio)
    

    # help function
    def write_to_file(self,file_path,write_lists):
        f1 = open(file_path, "w",encoding='utf-8')
        for key in write_lists:
            f1.write(str(key)+"\n")
        f1.close()

    def write_to_file2(self,file_path,write_lists):
        f1 = open(file_path, "w",encoding='utf-8')
        for key in write_lists:
            vids=re.findall(r"\d+\.?\d*",key)
            write_key=""
            for vid in vids:
                write_key=write_key+" "+str(vid)
            f1.write(write_key+"\n")
        f1.close()
    
    def read_from_file(self,file_path):
        write_lists=[]
        with open(file_path) as f1:
            reader = csv.reader(f1, delimiter=',')
            for row in reader:
                write_lists.append(row[0])
        f1.close()
        return write_lists

    def exist_file(self,file_path):
        return os.path.exists(file_path)

    ######create graph operations#######
    def _get_vertex_lists(self,file_path,query_type,path2=None):
        # ===========一般情况下用来生成查询节点的=================
        special_types = ['hot', 'warm', 'cold']
        if query_type not in special_types:
            if len(self._query_vertex_list)==0 or len(self._query_vertex_list) < 100:
                all_vertex=self.read_from_file(file_path)
                one_third=int(len(all_vertex)/3)
                head=all_vertex[0:one_third]
                mid=all_vertex[one_third:one_third*2]
                tail=all_vertex[one_third*2:]
                target_vertex=[]
                target_vertex=target_vertex+random.sample(head,33)
                target_vertex=target_vertex+random.sample(mid,33)
                target_vertex=target_vertex+random.sample(tail,34)
                self._query_vertex_list=target_vertex
            if path2 is not None:
                all_vertex=self.read_from_file(path2)
                one_third=int(len(all_vertex)/3)
                head=all_vertex[0:one_third]
                mid=all_vertex[one_third:one_third*2]
                tail=all_vertex[one_third*2:]
                target_vertex=[]
                target_vertex=target_vertex+random.sample(head,33)
                target_vertex=target_vertex+random.sample(mid,33)
                target_vertex=target_vertex+random.sample(tail,34)
                self._tgql_vertex_list=target_vertex
            return self._query_vertex_list
        else:
            # =========== 针对hotwarmcold ==============
            if len(self._query_vertex_list)==0 or len(self._query_vertex_list) < 10:
                all_vertex=self.read_from_file(file_path)
                one_third=int(len(all_vertex)/3)
                vertexes=[]
                if query_type == "hot":
                    vertexes=all_vertex[0:one_third]
                elif query_type == "warm":
                    vertexes=all_vertex[one_third:one_third*2]
                elif query_type == "cold":
                    vertexes=all_vertex[one_third*2:]
                self._query_vertex_list=vertexes[0:10]
            return self._query_vertex_list

    
    def _get_random_time(self,min_t,max_t):
        return random.randint(min_t, max_t)

    def _get_random_time_pair(self,min_t,max_t):
        t_s = self._get_random_time(min_t,max_t)
        t_e = t_s+ self._get_random_time(min_t,max_t)
        while t_e < t_s :
            t_e = self._get_random_time(min_t,max_t)
        return (t_s, t_e)
    
    def _get_TGDB_tt(self,tgdb_min, tgdb_max):
        return self._get_random_time_pair(tgdb_min, tgdb_max)

    def _get_ClockG_tt(self,tgdb_min,tgdb_max,clock_min,clock_max,tt_t,tt_t1):
        ts= int((tt_t-tgdb_min)*(clock_max-clock_min)/(tgdb_max-tgdb_min))+clock_min#(max_t+min_t)*(tt_t/max_t2)
        te=int((tt_t1-tgdb_min)*(clock_max-clock_min)/(tgdb_max-tgdb_min))+clock_min#(max_t+min_t)*(tt_t1/max_t2)
        return (ts,te)
        
    def _get_TGQL_tt(self,tgdb_min,tgdb_max,tsql_min,tsql_max,tt_t,tt_t1):
        ts= int((tt_t-tgdb_min)*(tsql_max-tsql_min)/(tgdb_max-tgdb_min))+tsql_min#(max_t+min_t)*(tt_t/max_t2)
        te=int((tt_t1-tgdb_min)*(tsql_max-tsql_min)/(tgdb_max-tgdb_min))+tsql_min
        return (ts,te)

    #read 
    def _q1_(self,vid):
        return "MATCH (r:User{id : "+str(vid)+"}) "

    def _q2_(self,vid):
        return "MATCH (n:User{id : "+str(vid)+"})-[e]->(r) "

    def _q3_(self,vid):
        return "MATCH (n1:User {id :"+str(vid)+"})-[e1]->(n2)-[e2]->(n3)-[e3]->(n4)<-[e4]-(r) "
    
    def _as_of(self,t):
        return " TT AS " + str(t)
    
    def _from_to(self,t1,t2):
        return " TT FROM " + str(t1) +" TO "+str(t2)
    
    def _end_limit(self):
        return " LIMIT 1"

    def _return_(self):
        return " RETURN r;"

    def _tgql_q1(self,userid,ts,te):
        tq_head = "MATCH (n:Object {title:'User'})-[:OBJECT_ATTRIBUTE]-(:Attribute {title:'id'})-[:ATTRIBUTE_VALUE]-(:Value {title:"+userid+"}),"+\
                    " (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val:Value) "
        tq_condition = " where n.validTimeStart<=" + str(te) +" and n.validTimeEnd>"+str(ts)+" " \
                    +" and val.validTimeStart<=" + str(te) +" and val.validTimeEnd>"+str(ts)+" " 
        tq_return=" return n,e1,att,e2,val ;"
        return tq_head+tq_condition+tq_return

    def _tgql_q2(self,userid,ts,te):
        tq_head = "MATCH (n:Object {title:'User'})-[:OBJECT_ATTRIBUTE]-(:Attribute {title:'id'})-[:ATTRIBUTE_VALUE]-(val:Value {title:"+userid+"}),"+\
                    " (n)-[:Friend]->(p:Object), " +\
                    " (p)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val2:Value) "
        tq_condition = " where n.validTimeStart<=" + str(te) +" and n.validTimeEnd>"+str(ts)+" " \
                    +" and val.validTimeStart<=" + str(te) +" and val.validTimeEnd>"+str(ts)+" " \
                    + " and p.validTimeStart<=" + str(te) +" and p.validTimeEnd>"+str(ts)+" " \
                    + " and val2.validTimeStart<=" + str(te) +" and val2.validTimeEnd>"+str(ts)+" " 
        tq_return=" return p,e1,att,e2,val2 ;"
        return tq_head+tq_condition+tq_return
     
    def _tgql_q3(self,userid,ts,te):
        tq_head = "MATCH (n:Object {title:'User'})-[:OBJECT_ATTRIBUTE]-(:Attribute {title:'id'})-[:ATTRIBUTE_VALUE]-(val:Value {title:'User_"+userid+"'}),"+\
                    " (n)-[e1:Friend]->(n2:Object)-[e2:Friend]->(n3:Object)-[e3:Friend]->(n4:Object)<-[e4:Friend]-(n5:Object) " +\
                    " (n5)-[e5_1:OBJECT_ATTRIBUTE]-(att5_1:Attribute)-[e5_2:ATTRIBUTE_VALUE]-(val5_1:Value) "
        tq_condition = " where n.validTimeStart<=" + str(te) +" and n.validTimeEnd>"+str(ts)+" " \
                    +" and e1.validTimeStart<=" + str(te) +" and e1.validTimeEnd>"+str(ts)+" " \
                    +" and n2.validTimeStart<=" + str(te) +" and n2.validTimeEnd>"+str(ts)+" " \
                    +" and e2.validTimeStart<=" + str(te) +" and e2.validTimeEnd>"+str(ts)+" " \
                    +" and n3.validTimeStart<=" + str(te) +" and n3.validTimeEnd>"+str(ts)+" " \
                    +" and e3.validTimeStart<=" + str(te) +" and e3.validTimeEnd>"+str(ts)+" " \
                    +" and n4.validTimeStart<=" + str(te) +" and n4.validTimeEnd>"+str(ts)+" " \
                    +" and e4.validTimeStart<=" + str(te) +" and e4.validTimeEnd>"+str(ts)+" " \
                    +" and n5.validTimeStart<=" + str(te) +" and n5.validTimeEnd>"+str(ts)+" " \
                    +" and e5_1.validTimeStart<=" + str(te) +" and e5_1.validTimeEnd>"+str(ts)+" " \
                    +" and att5_1.validTimeStart<=" + str(te) +" and att5_1.validTimeEnd>"+str(ts)+" " \
                    +" and e5_2.validTimeStart<=" + str(te) +" and e5_2.validTimeEnd>"+str(ts)+" " \
                    +" and att5_2.validTimeStart<=" + str(te) +" and att5_2.validTimeEnd>"+str(ts)+" " \
                    +" and val5_1.validTimeStart<=" + str(te) +" and val5_1.validTimeEnd>"+str(ts)+" " 
                    
        tq_return=" return n5,e5_1,att5_1,e5_2,val5_1; "
        return tq_head+tq_condition+tq_return
        

    def _get_TGDB_query(self,type_name,vid,ts,te): #TGDB ClockG的query
        if(type_name=="q1"):
            q_TGDB_as_of=self._q1_(vid)+ self._as_of(ts) +self._return_()#+self._end_limit()
            q_TGDB_from_to=self._q1_(vid)+ self._from_to(ts,te) +self._return_()#+self._end_limit()
            return (q_TGDB_as_of,q_TGDB_from_to)
        if(type_name=="q2"):
            q_TGDB_as_of=self._q2_(vid)+ self._as_of(ts) +self._return_()#+self._end_limit()
            q_TGDB_from_to=self._q2_(vid)+ self._from_to(ts,te) +self._return_()#+self._end_limit()
            return (q_TGDB_as_of,q_TGDB_from_to)
        if(type_name=="q3"):
            q_TGDB_as_of=self._q3_(vid)+ self._as_of(ts) +self._return_()#+self._end_limit()
            q_TGDB_from_to=self._q3_(vid)+ self._from_to(ts,te) +self._return_()#+self._end_limit()
            return (q_TGDB_as_of,q_TGDB_from_to)
    
    def _get_TGQL_query(self,type_name,vid,ts,te): #TGDB ClockG的query
        if(type_name=="q1"):
            q_as_of=self._tgql_q1(vid,ts,ts)
            q_from_to=self._tgql_q1(vid,ts,te)
            return (q_as_of, q_from_to)
        if(type_name=="q2"):
            q_as_of=self._tgql_q2(vid,ts,ts)
            q_from_to=self._tgql_q2(vid,ts,te)
            return (q_as_of, q_from_to)
        if(type_name=="q3"):
            q_as_of=self._tgql_q3(vid,ts,ts)
            q_from_to=self._tgql_q3(vid,ts,te)
            return (q_as_of, q_from_to)

    def Q(self,file_path,type_name,tgdb_min,tgdb_max,clock_min,clock_max,tgql_min,tgql_max,query_type,path2=None):
        vid_lists=self._get_vertex_lists(file_path,query_type,path2=path2)
        tgql_lists=self._tgql_vertex_list
        num=0
        q_TGDB_as_of_lists=[]
        q_TGDB_from_to_lists=[]
        q_Clockg_as_of_lists=[]
        q_Clockg_from_to_lists=[]
        q_tgql_as_of_lists=[]
        q_tgql_from_to_lists=[]
        while (True):
            for vid in vid_lists:
                #时间
                ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
                clockg_ts,clockg_te=self._get_ClockG_tt(tgdb_min,tgdb_max,clock_min,clock_max,ts,te)
                tgql_ts,tgql_te=self._get_TGQL_tt(tgdb_min,tgdb_max,tgql_min,tgql_max,ts,te)
                #q1
                q_TGDB_as_of,q_TGDB_from_to=self._get_TGDB_query(type_name,vid,ts,te)
                q_TGDB_as_of_lists.append(q_TGDB_as_of)
                q_TGDB_from_to_lists.append(q_TGDB_from_to)

                q_Clockg_as_of,q_Clockg_from_to=self._get_TGDB_query(type_name,vid,clockg_ts,clockg_te)#self._q1_(vid)+ self._as_of(clockg_ts) +self._end_limit
                q_Clockg_as_of_lists.append(q_Clockg_as_of)
                q_Clockg_from_to_lists.append(q_Clockg_from_to)

                q_tgql_as_of,q_tgql_from_to=self._get_TGQL_query(type_name,vid,tgql_ts,tgql_te)
                q_tgql_as_of_lists.append(q_tgql_as_of)
                q_tgql_from_to_lists.append(q_tgql_from_to)

                num+=1
                if(num>=100):
                    break
            if(num>=100):
                    break
                
        return (q_TGDB_as_of_lists,q_TGDB_from_to_lists,q_Clockg_as_of_lists,q_Clockg_from_to_lists,q_tgql_as_of_lists,q_tgql_from_to_lists)