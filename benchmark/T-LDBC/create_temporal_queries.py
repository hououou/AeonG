import random
import csv
import os
import re

class LDBC():
    def __init__(self,size="sf1",max_op_ratio=0.1,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100):
        SIZES = {
            "sf0.1": {"vertices": 327588, "edges": 1477965},
            "sf1": {"vertices": 3181724, "edges": 17256038},
            "sf3": {"vertices": 9281922, "edges": 52695735},
            "sf10": {"vertices": 1, "edges": 1},
        }

        self._size=size
        self.max_op_ratio=max_op_ratio
        self.update_ratio=update_ratio
        self.delete_ratio=delete_ratio
        self.create_ratio=create_ratio
        self.avg_update_ratio=avg_update_ratio
        self._num_vertices=SIZES[size]["vertices"]
        self._num_edges=SIZES[size]["edges"]
        self._max_graph_op=self.max_op_ratio#图操作的数量
        self._max_update_op=int(self._max_graph_op*update_ratio) #update操作的数量
        self._max_delete_op=int(self._max_graph_op*delete_ratio) #delete操作的数量
        self._max_create_op=self._max_graph_op-self._max_update_op-self._max_delete_op  #create操作的数量

        self._avg_update_ratio=avg_update_ratio #平均每个节点更新的次数
        self._update_vertices_lists=[] #更新的节点
        self._update_vertices_num=int(self._max_update_op/self._avg_update_ratio) #更新节点的数目
        self._count_update_num=0
        

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

    def _get_vertex_lists(self,file_path):
        return self.read_from_file(file_path)
    
    def _get_random_time(self,min_t,max_t):
        return random.randint(min_t, max_t)

    def _get_random_time_pair(self,min_t,max_t):
        t_s = self._get_random_time(min_t,max_t)
        t_e = self._get_random_time(min_t,max_t)
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

    def _get_all_time(self,tgdb_min,tgdb_max,clock_min,clock_max,tgql_min,tgql_max):
        #时间
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        clockg_ts,clockg_te=self._get_ClockG_tt(tgdb_min,tgdb_max,clock_min,clock_max,ts,te)
        tgql_ts,tgql_te=self._get_TGQL_tt(tgdb_min,tgdb_max,tgql_min,tgql_max,ts,te)
        return (ts,te,clockg_ts,clockg_te,tgql_ts,tgql_te)
    
    def _as_of(self,t):
        return " TT AS " + str(t)
    
    def _from_to(self,t1,t2):
        return " TT FROM " + str(t1) +" TO "+str(t2)
    
    #read 
    def IS1(self,person_id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max):
        #time info
        ts,te,clockg_ts,clockg_te,tgql_ts,tgql_te=self._get_all_time(tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        #### tgdb&clock-g #####
        query1=f"MATCH (n:Person {{id:{person_id}}})-[:IS_LOCATED_IN]->(p:Place)"
        query_return=" RETURN n.firstName AS firstName, n.lastName AS lastName, n.birthday AS birthday, n.locationIP AS locationIp,"\
            "n.browserUsed AS browserUsed,"\
            "n.gender AS gender,"\
            "n.creationDate AS creationDate,"\
            "p.id AS cityId;"
        tgdb_asof=query1+self._as_of(ts)+query_return
        tgdb_from_to=query1+self._from_to(ts,te)+query_return
        clockg_asof=query1+self._as_of(clockg_ts)+query_return
        clockg_from_to=query1+self._from_to(clockg_ts,clockg_te)+query_return
        #tgql info
        tq_head = f"MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:\"{person_id}'\"}}),"+\
                    " (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val2:Value) ,"+\
                    f" (n)-[r:isLocatedIn]->(p:Object{{title:'Place'}})-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute {{title:'id'}})-[pe2:ATTRIBUTE_VALUE]-(val3:Value)"
        tq_condition = f" where n.validTimeStart<={tgql_te} and n.validTimeEnd>{tgql_ts} " +\
                        f" and val.validTimeStart<={tgql_te} and val.validTimeEnd>{tgql_ts} " +\
                        f" and val2.validTimeStart<={tgql_te} and val2.validTimeEnd>{tgql_ts} " 
        tq_condition1 = f" where n.validTimeStart<={tgql_ts} and n.validTimeEnd>{tgql_ts} " +\
                        f" and val.validTimeStart<={tgql_ts} and val.validTimeEnd>{tgql_ts} " +\
                        f" and val2.validTimeStart<={tgql_ts} and val2.validTimeEnd>{tgql_ts} " 
        tq_return=" return n,e1,att,e2,val2,r,p,pe1,pa1,pe2,val3;"
        tgql_as_of=tq_head+tq_condition1+tq_return
        tgql_from_to=tq_head+tq_condition+tq_return
        return (tgdb_asof,tgdb_from_to,clockg_asof,clockg_from_to,tgql_as_of,tgql_from_to)                   

    def IS3(self,person_id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max):
        #time info
        ts,te,clockg_ts,clockg_te,tgql_ts,tgql_te=self._get_all_time(tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        #### tgdb&clock-g #####
        query1=f"MATCH (n:Person {{id:{person_id}}})-[r:KNOWS]-(friend)"
        query_return=" RETURN "\
                    "friend.id AS personId,"\
                    "friend.firstName AS firstName,"\
                    "friend.lastName AS lastName,"\
                    "r.creationDate AS friendshipCreationDate "\
                    "ORDER BY friendshipCreationDate DESC, toInteger(personId) ASC;"
        tgdb_asof=query1+self._as_of(ts)+query_return
        tgdb_from_to=query1+self._from_to(ts,te)+query_return
        clockg_asof=query1+self._as_of(clockg_ts)+query_return
        clockg_from_to=query1+self._from_to(clockg_ts,clockg_te)+query_return
       
        tgql_as_of = f"MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:\"{person_id}'\"}})"+\
                    " with n match (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute{title:'creationDate'})-[e2:ATTRIBUTE_VALUE]-(val2:Value) "+\
                    f" where  val2.validTimeStart<={tgql_ts} and val2.validTimeEnd>{tgql_ts}"+\
                    " with n,e1,att,e2,val2 "+\
                    f" match (n)-[r:knows]->(p:Object)-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute) "+\
                    f" where pa1.title='id' or pa1.title='firstName' or pa1.title='lastName' "+\
                    " with n,e1,att,e2,val2,r,p,pe1,pa1"+\
                    " match (pa1)-[pe2:ATTRIBUTE_VALUE]-(val3:Value) "+\
                    f" where val3.validTimeStart<={tgql_ts} and val3.validTimeEnd>{tgql_ts} " +\
                    "return n,e1,att,e2,val2,r,p,pe1,pa1,pe2,val3;"

        tgql_from_to=f"MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:\"{person_id}'\"}})"+\
                    " with n match (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute{title:'creationDate'})-[e2:ATTRIBUTE_VALUE]-(val2:Value) "+\
                    f" where  val2.validTimeStart<={tgql_te} and val2.validTimeEnd>{tgql_ts}"+\
                    " with n,e1,att,e2,val2 "+\
                    f" match (n)-[r:knows]->(p:Object)-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute) "+\
                    f" where pa1.title='id' or pa1.title='firstName' or pa1.title='lastName' "+\
                    " with n,e1,att,e2,val2,r,p,pe1,pa1"+\
                    " match (pa1)-[pe2:ATTRIBUTE_VALUE]-(val3:Value) "+\
                    f" where val3.validTimeStart<={tgql_te} and val3.validTimeEnd>{tgql_ts} " +\
                    "return n,e1,att,e2,val2,r,p,pe1,pa1,pe2,val3;"
        return (tgdb_asof,tgdb_from_to,clockg_asof,clockg_from_to,tgql_as_of,tgql_from_to)                   

    def IS4(self,v_id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max):
        #time info
        ts,te,clockg_ts,clockg_te,tgql_ts,tgql_te=self._get_all_time(tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        #### tgdb&clock-g #####
        query1=f"MATCH (m:Message {{id:{v_id}}}) "
        query_return=" RETURN "\
                    "CASE m.content IS NOT NULL "\
                    " WHEN true THEN m.content "\
                        "ELSE m.imageFile "\
                    "END AS messageContent,"\
                    "m.creationDate as messageCreationDate;"
        tgdb_asof=query1+self._as_of(ts)+query_return
        tgdb_from_to=query1+self._from_to(ts,te)+query_return
        clockg_asof=query1+self._as_of(clockg_ts)+query_return
        clockg_from_to=query1+self._from_to(clockg_ts,clockg_te)+query_return
        #tgql info
        tq_head = f"MATCH (n:Object {{title:'Comment'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:\"{v_id}'\"}})"+\
                    " with n match (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute) "+\
                    f" where att.title='content' or att.title='imageFile' or att.title='creationDate' "+\
                    " with n,e1,att match (att)-[e2:ATTRIBUTE_VALUE]-(val2:Value) "
                    
        tq_condition = f" where val2.validTimeStart<={tgql_te} and val2.validTimeEnd>{tgql_ts} " 
        tq_condition1 = f" where val2.validTimeStart<={tgql_ts} and val2.validTimeEnd>{tgql_ts} " 
        tq_return=" return n,e1,att,e2,val2;"
        tgql_as_of=tq_head+tq_condition1+tq_return
        tgql_from_to=tq_head+tq_condition+tq_return
        return (tgdb_asof,tgdb_from_to,clockg_asof,clockg_from_to,tgql_as_of,tgql_from_to)                   
    
    def IS5(self,v_id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max):
        #time info
        ts,te,clockg_ts,clockg_te,tgql_ts,tgql_te=self._get_all_time(tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        #### tgdb&clock-g #####
        query1=f"MATCH (m:Message {{id:{v_id}}})-[:HAS_CREATOR]->(p:Person)"
        query_return=" RETURN "\
                    " p.id,p.firstName,p.lastName; "
        tgdb_asof=query1+self._as_of(ts)+query_return
        tgdb_from_to=query1+self._from_to(ts,te)+query_return
        clockg_asof=query1+self._as_of(clockg_ts)+query_return
        clockg_from_to=query1+self._from_to(clockg_ts,clockg_te)+query_return
        #tgql info
        tq_head = f"MATCH (n:Object {{title:'Comment'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:\"{v_id}'\"}}),"+\
                    f" (n)-[r:hasCreator]->(p:Object{{title:'Person'}})-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute)" +\
                    f" where pa1.title='id' or pa1.title='firstName' or pa1.title='lastName'  "+\
                    " with n,p,pe1,pa1 match (pa1)-[pe2:ATTRIBUTE_VALUE]-(val3:Value) "
        tq_condition = f" where val3.validTimeStart<={tgql_te} and val3.validTimeEnd>{tgql_ts} " 
        tq_condition1 = f" where val3.validTimeStart<={tgql_ts} and val3.validTimeEnd>{tgql_ts} " 
        tq_return=" return p,pe1,pa1,pe2,val3;"
        tgql_as_of=tq_head+tq_condition1+tq_return
        tgql_from_to=tq_head+tq_condition+tq_return
        return (tgdb_asof,tgdb_from_to,clockg_asof,clockg_from_to,tgql_as_of,tgql_from_to)                   

    def IS(self,id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max,is_idx):
        if(is_idx==1):
            return self.IS1(id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        if(is_idx==3):
            return self.IS3(id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        if(is_idx==4):
            return self.IS4(id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        if(is_idx==5):
            return self.IS5(id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)
        if(is_idx==7):
            return self.IS7(id,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max)

    def IS_queries(self,file_path,is_idx,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max):
        vid_lists=self._get_vertex_lists(file_path)
        num=0
        q_TGDB_as_of_lists=[]
        q_TGDB_from_to_lists=[]
        q_Clockg_as_of_lists=[]
        q_Clockg_from_to_lists=[]
        q_tgql_as_of_lists=[]
        q_tgql_from_to_lists=[]
        while (True):
            for vid in vid_lists:
                tgdb_asof,tgdb_from_to,clockg_asof,clockg_from_to,tgql_asof,tgql_from_to=self.IS(vid,tgdb_min,tgdb_max,clock_min,clock_max,tsql_min,tsql_max,is_idx)
                q_TGDB_as_of_lists.append(tgdb_asof)
                q_TGDB_from_to_lists.append(tgdb_from_to)
                q_Clockg_as_of_lists.append(clockg_asof)
                q_Clockg_from_to_lists.append(clockg_from_to)
                q_tgql_as_of_lists.append(tgql_asof)
                q_tgql_from_to_lists.append(tgql_from_to)
                num+=1
                if(num>=100):
                    break
            if(num>=100):
                    break
        return (q_TGDB_as_of_lists,q_TGDB_from_to_lists,q_Clockg_as_of_lists,q_Clockg_from_to_lists,q_tgql_as_of_lists,q_tgql_from_to_lists)

