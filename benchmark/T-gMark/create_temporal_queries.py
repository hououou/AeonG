import random
import csv
import os
import re

class gMark():
    def __init__(self,size="sf1",max_op_ratio=0.1,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100):
        SIZES = {
            "sf1": {"vertices": 100000, "edges": 239737}
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

    
    def _get_vertex_list(self,file_path,types):
        query_vertex_list=[]
        if len(query_vertex_list) < 100:
            hot_vertex_path=file_path.replace("count","count_hot")
            warm_vertex_path=file_path.replace("count","count_warm")
            cold_vertex_path=file_path.replace("count","count_cold")
            hot_vertex = self.read_from_file(hot_vertex_path)
            print(hot_vertex)
            warm_vertex=self.read_from_file(warm_vertex_path)
            cold_vertex=self.read_from_file(cold_vertex_path)
            hot_target_vertex=[]
            warm_target_vertex=[]
            cold_target_vertex=[]
            while(len(hot_target_vertex)<100):
                if len(hot_vertex) >= 100:
                    hot_target_vertex=hot_target_vertex+random.sample(hot_vertex,100)
                else:
                    hot_target_vertex=hot_target_vertex+hot_vertex
            while(len(warm_target_vertex)<100):
                if len(warm_vertex) >= 100:
                    warm_target_vertex=warm_target_vertex+random.sample(warm_vertex,100)
                else:
                    warm_target_vertex=warm_target_vertex+warm_vertex
            while(len(cold_target_vertex)<100):
                    if len(cold_vertex) >= 100:
                        cold_target_vertex=cold_target_vertex+random.sample(cold_vertex,100)
                    else:
                        cold_target_vertex=cold_target_vertex+cold_vertex
            if(types=="hot"):
                query_vertex_list=hot_target_vertex
            if(types=="warm"):
                query_vertex_list=warm_target_vertex
            if(types=="cold"):
                query_vertex_list=cold_target_vertex
            if(types=="mix"):
                query_vertex_list=hot_target_vertex[:33]+cold_target_vertex[:33]+cold_vertex[:33]
        return query_vertex_list

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
    def q0(self,tgdb_min,tgdb_max,tgql_min,tgql_max,clockg_min,clockg_max):
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        query1="MATCH (x0)-[:name*]->(x1), (x1)-[:name]->()<-[:locationIP]-()-[:worksAt]->(x2), (x2)-[:name*]->(x3), (x3)-[:name|name|name*]->(x4)"
        query_return=   " RETURN DISTINCT x0, x4  ;"
        tgdb_asof=query1+self._as_of(ts)+query_return

        ts,te=self._get_TGDB_tt(clockg_min,clockg_max)
        query1="MATCH (x0)-[:name*]->(x1), (x1)-[:name]->()<-[:locationIP]-()-[:worksAt]->(x2), (x2)-[:name*]->(x3), (x3)-[:name|name|name*]->(x4)"
        query_return=   " RETURN DISTINCT x0, x4  ;"
        clockg_asof=query1+self._as_of(ts)+query_return

        ts,te=self._get_TGDB_tt(tgql_min,tgql_max)
        tgql_as_of=f"""
        MATCH (x0:Object)-[:name*]->(x1:Object), (x1:Object)-[r0:name]->(t0:Object)<-[r1:locationIP]-(t1:Object)-[r2:worksAt]->(x2:Object), (x2:Object)-[:name*]->(x3:Object), (x3:Object)-[:name|name|name*]->(x4:Object) 
        where x0.validTimeStart<={ts} and x0.validTimeEnd>{ts} 
        and x1.validTimeStart<={ts} and x1.validTimeEnd>{ts} 
        and x2.validTimeStart<={ts} and x2.validTimeEnd>{ts} 
        and x3.validTimeStart<={ts} and x3.validTimeEnd>{ts} 
        and x4.validTimeStart<={ts} and x4.validTimeEnd>{ts}
        and r0.validTimeStart<={ts} and r0.validTimeEnd>{ts}
        and r1.validTimeStart<={ts} and r1.validTimeEnd>{ts}
        and r2.validTimeStart<={ts} and r2.validTimeEnd>{ts} 
        and t0.validTimeStart<={ts} and t0.validTimeEnd>{ts} 
        and t1.validTimeStart<={ts} and t1.validTimeEnd>{ts} 
        RETURN DISTINCT x0, x4;
        """
        
        return tgdb_asof,tgql_as_of.replace("\n",""),clockg_asof.replace("\n","")


        return tgdb_asof
    #TODO q2 q3 q4
    def q1(self,tgdb_min,tgdb_max,tgql_min,tgql_max):
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        query1="MATCH (x0)<-[:language]-()-[:content]->()<-[:content]-()<-[:containerOf]-(x1), (x0)<-[:language]-()-[:isSubclassOf]->()-[:browserUsed]->()<-[:length]-(x2), (x0)<-[:language]-()-[:isSubclassOf]->()-[:locationIP]->()<-[:length]-(x3), (x0)<-[:language]-()-[:isSubclassOf]->()-[:creationDate]->()<-[:creationDate]-(x4) "
        query_return=   "RETURN DISTINCT x0, x1;"
        tgdb_asof=query1+self._as_of(ts)+query_return

        ts,te=self._get_TGDB_tt(tgql_min,tgql_max)
        tgql_as_of="match (x0:Object)<-[:language]-(:Object)-[:content]->(:Object)<-[:content]-(:Object)<-[:containerOf]-(x1:Object), (x0:Object)<-[:language]-(:Object)-[:isSubclassOf]->(:Object)-[:browserUsed]->(:Object)<-[:length]-(x2:Object), (x0:Object)<-[:language]-(:Object)-[:isSubclassOf]->(:Object)-[:locationIP]->(:Object)<-[:length]-(x3:Object), (x0:Object)<-[:language]-(:Object)-[:isSubclassOf]->(:Object)-[:creationDate]->(:Object)<-[:creationDate]-(x4:Object) RETURN DISTINCT x0, x1;"
        return tgdb_asof,tgql_as_of

    def q2(self,tgdb_min,tgdb_max,tgql_min,tgql_max):
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        query1="MATCH (x0)-[:name|name*]->(x1), (x1)-[:name*]->(x2), (x2)-[:name|name*]->(x3), (x3)-[:name|name*]->(x4)"
        query_return=   " RETURN DISTINCT x0, x4;"
        tgdb_asof=query1+self._as_of(ts)+query_return

        ts,te=self._get_TGDB_tt(tgql_min,tgql_max)
        tgql_as_of=""
        return tgdb_asof,tgql_as_of

    def q3(self,tgdb_min,tgdb_max,tgql_min,tgql_max):
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        query1="MATCH (x0)-[:isLocatedIn]->()-[:name]->()<-[:email]-()-[:creationDate]->(x1), (x1)-[:birthday|creationDate*]->(x2), (x2)<-[:birthday]-()-[:gender]->()<-[:name]-(x3), (x3)-[:name|name|name*]->(x4) "
        query_return=   " RETURN DISTINCT x0;"
        tgdb_asof=query1+self._as_of(ts)+query_return
        
        ts,te=self._get_TGDB_tt(tgql_min,tgql_max)
        tgql_as_of=""
        return tgdb_asof,tgql_as_of

    def q4(self,tgdb_min,tgdb_max,tgql_min,tgql_max):
        ts,te=self._get_TGDB_tt(tgdb_min, tgdb_max)
        query1="MATCH (x0)-[:name*]->(x1), (x1)-[:browserUsed|locationIP*]->(x2), (x2)-[:gender|name|gender*]->(x3) "
        query_return=   " RETURN 'true' LIMIT 1;"
        tgdb_asof=query1+self._as_of(ts)+query_return
        
        ts,te=self._get_TGDB_tt(tgql_min,tgql_max)
        tgql_as_of=""
        return tgdb_asof,tgql_as_of
    
    def q(self,tgdb_min,tgdb_max,tgql_min,tgql_max,is_idx,clock_min,clock_max):
        query_num=1
        if(is_idx==0):
            tgql_as_of_lists=[]
            tgdb_as_of_lists=[]
            clockg_as_of_lists=[]
            for i in range(query_num):
                tgdb_asof,tgql_as_of,clockg_asof=self.q0(tgdb_min,tgdb_max,tgql_min,tgql_max,clock_min,clock_max)
                tgdb_as_of_lists.append(tgdb_asof)
                tgql_as_of_lists.append(tgql_as_of)
                clockg_as_of_lists.append(clockg_asof)
            return tgdb_as_of_lists,tgql_as_of_lists,clockg_as_of_lists

    def IS_queries(self,file_path,is_idx,tgdb_min,tgdb_max):
        query_type="mix"
        query_id_path=file_path.replace("count",f"{query_type}_ids")
        query_ts_path=file_path.replace("count",f"{query_type}_times")
        print(query_id_path)
        vid_lists=[]
        tgdb_ts=[]
        if self.exist_file(query_id_path):
            print("vid_lists",len(vid_lists))
            vid_lists=self.read_from_file(query_id_path)
        else:
            print("vid_lists",len(vid_lists))
            vid_lists=self._get_vertex_list(file_path,query_type)
            self.write_to_file(query_id_path,vid_lists)
        num=0
        q_TGDB_as_of_lists=[]
        while (True):
            for vid in vid_lists:
                tgdb_asof=self.q(vid,tgdb_min,tgdb_max)
                num+=1
                if(num>=1):
                    break
            if(num>=1):
                    break
        return (q_TGDB_as_of_lists)


def generate_IS(size,index,scale,update_num,max_op_ratio,avg_update_ratio,tgdb_min,tgdb_max,clock_min,clock_max,tgql_min,tgql_max,file_prefix):
    gmark=gMark(size=size,max_op_ratio=max_op_ratio,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=avg_update_ratio)
    path1=f"Num{gmark._max_graph_op}"
    peak_types={1:"person",3:"person",4:"comment",5:"comment",7:"comment"}
    write_path=f"{file_prefix}/{update_num}/{scale}/temporal_query/q"+str(index)+"_"
    #q1
    q_TGDB_as_of_lists,q_TGQL_as_of_lists,q_clockg_as_of_lists=gmark.q(tgdb_min,tgdb_max,tgql_min,tgql_max,index,clock_min,clock_max)
    gmark.write_to_file(write_path+"TGDB_asof_"+path1+".txt",q_TGDB_as_of_lists)
    gmark.write_to_file(write_path+"TGQL_asof_"+path1+".txt",q_TGQL_as_of_lists)
    gmark.write_to_file(write_path+"ClockG_asof_"+path1+".txt",q_clockg_as_of_lists)