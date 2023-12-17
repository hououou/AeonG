import random
import csv
import os
import re
import string
import numpy as np
import copy
import pandas as pd
class gMark():
    def __init__(self,size="sf1",max_op=100000,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100):
        SIZES = {
            "sf1": {"vertices": 100000, "edges": 239737}
        }
        self.browserUsed=["Firefox","Internet Explorer","Chrome","Safari"]
        self._size=size
        self.update_ratio=update_ratio
        self.delete_ratio=delete_ratio
        self.create_ratio=create_ratio
        self.avg_update_ratio=avg_update_ratio
        self._num_vertices=SIZES[size]["vertices"]
        self._num_edges=SIZES[size]["edges"]
        # self._dataset_file_path=Dataset[size]
        self._max_graph_op=max_op
        self._id_to_be=SIZES[size]["vertices"]
        self._max_update_op=int(self._max_graph_op*update_ratio) #update操作的数量
        self._max_delete_op=int(self._max_graph_op*delete_ratio) #delete操作的数量
        self._max_create_op=self._max_graph_op-self._max_update_op-self._max_delete_op  #create操作的数量

        self._avg_update_ratio=avg_update_ratio #平均每个节点更新的次数
        self._count_update_num=0

        #update num 每一个类别总query的上限
        self._update_content_num=int(self._max_update_op/3)
        self._update_locationIP_num=int(self._max_update_op/3)
        self._update_browserUsed_num=int(self._max_update_op/3)
        
        #生成的数目
        self._count_content_op=0#int(self._max_graph_op*0.5)
        self._count_locationIP_op=0#int(self._max_graph_op*0.25)
        self._count_browserUsed_op=0#self._max_graph_op-self._max_person_op-self._max_comment_op
        
        #更新的节点id
        self._update_content_lists=[] 
        self._update_locationIP_lists=[] 
        self._update_browserUsed_lists=[] 

        print("max_graph_op",self._max_graph_op)
        print("update_op",self._max_update_op)
        
    ###########help function###########
    def ranstr(self,num):
        salt = ''.join(random.sample(string.ascii_letters + string.digits, num))
        return salt

    def write_to_file(self,file_path,write_lists):
        # print(file_path)
        # os.mknod(file_path)
        f1 = open(file_path, "w",encoding='utf-8')
        for key in write_lists:
            f1.write(str(key)+"\n")
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

        values = np.arange(min, max+1,dtype=np.uint64) # values to sample
        index = copy.deepcopy(values)
        np.random.shuffle(values)
        p = 1.0 / np.power(index - min + 1, a)  # probabilities
        p /= np.sum(p)            # normalized

        return np.random.choice(values, size=size, replace=True, p=p)

    def get_csv_nodes(self,file_path):
        write_lists=[]
        edge_types=set()
        with open(file_path) as f1:
            reader = csv.reader(f1, delimiter='|')
            for row in reader:
                write_lists.append(row[1])
                edge_type=row[2]
                # # if(edge_type==find_edge_type):
                # if(edge_type=="content" or edge_type=="locationIP" or edge_type=="browserUsed"):
                #     write_lists.append(row[1])
        f1.close()
        return write_lists


    #TODO 
    def _get_type_lists(self,file_path,csv_path):
        #update peak vertex
        file_path2=file_path.replace(".csv","")
        update_path=file_path2+"_update.csv"
        update_count_path=file_path2+"_update_count.csv"
        update_count_path_hot=file_path2+"_update_count_hot.csv"
        update_count_path_warm=file_path2+"_update_count_warm.csv"
        update_count_path_cold=file_path2+"_update_count_cold.csv"
        if(self.exist_file(update_path) == False):
            #write peak vertex
            update_type_lists=[]
            id_lists=self.get_csv_nodes(csv_path)
            lens=len(id_lists)
            print(lens)
            left = np.uint64(1)
            right = np.uint64(lens-1)#文件的行数
            selected_lists=self.Zipf(1.1, left, right,self._max_update_op)
            for i in selected_lists:
                update_id=id_lists[i]
                update_type_lists.append(update_id)

            self.write_to_file(file_path=update_path,write_lists=update_type_lists)
            #write vertex count
            data=pd.value_counts(update_type_lists)
            data.to_csv(update_count_path,header=False)
            # write hot, warm, cold
            total_count = data.sum()# 计算概率质量函数 (PMF)
            pmf = data / total_count
            cdf = np.cumsum(pmf)# 计算累积分布函数 (CDF)
            data_quantile1 = data[cdf <=0.3]
            data_quantile2 = data[(cdf > 0.3) & (cdf <= 0.6)]
            data_quantile3 = data[cdf > 0.6]
            data_quantile1.to_csv(update_count_path_hot,header=False)
            data_quantile2.to_csv(update_count_path_warm,header=False)
            data_quantile3.to_csv(update_count_path_cold,header=False)
            return update_type_lists
        else:
            return self.read_from_file(update_path)
    
   
    ###########update query###########
    def update_query(self,v_id):
        query=f"MATCH (c:Node {{id: '{v_id}'}}) SET c.name ={self._num_vertices};"
        tgql_query=f" MATCH (n :Object {{id:{v_id}}})-[:OBJECT_ATTRIBUTE]-(a:Attribute {{title:'name'}})-[:ATTRIBUTE_VALUE]-(v:Value) "+\
                    " where v.validTimeEnd=9223372036854775000 "+\
                    " set v.validTimeEnd=timestamp() "+\
                    f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title: '{self._num_vertices}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}});"
        
        self._num_vertices+=1
        return query,tgql_query

    def _update(self,update_id_lists): 
        tgdb_write_lists=[]
        tgql_write_lists=[]
        for update_id in update_id_lists:
            query,tgql_query=self.update_query(update_id)
            tgdb_write_lists.append(query)
            tgql_write_lists.append(tgql_query)
        return tgdb_write_lists,tgql_write_lists
    
    ######## add query #########
    def add_node():
        self._id_to_be = self._id_to_be + 1
        query=f"Create (n:Node {{id:{self._id_to_be}}})"
        tgql_query=f"Create (n:Object {{ title:'Node',id:{self._id_to_be},validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }}) Create (n)-[:OBJECT_ATTRIBUTE]->(att:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (att)-[:ATTRIBUTE_VALUE]->(:Value {{title:0,validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (n)-[:OBJECT_ATTRIBUTE]->(att2:Attribute {{title:'name',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})  Create (att2)-[:ATTRIBUTE_VALUE]->(:Value {{title:0,validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) ;"
        return query,tgql_query
    def add_edge(from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}}),(n2 {{id:{to_node}}}) with n1, n2 Create (n1)-[:edge_type]-(n2);"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 Create (o1)-[:edge_type]-(o2);"
        return query,tgql_query

    ######### delete query ############
    def delete_node(node_label,v_id):
        query=f"MATCH (c:Node {{id: '{v_id}'}})-[e]-() delete e, c;"
        tgql_query1=f"MATCH (p:Object {{id:{node_label}{v_id}}})-[o:OBJECT_ATTRIBUTE]-(att)-[a:ATTRIBUTE_VALUE]-(v) delete o,a,att,v;"
        tgql_query2=f"MATCH (p:Object {{id:{node_label}{v_id}}})-[e]-() delete e;"
        return query, tgql_query1,tgql_query2

    def delete_edge(from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}})-[e:{edge_type}]-(n2 {{id:{to_node}}}) delete e;"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 MATCH (o1)-[e:edge_type]-(o2) delete e;"
        return query,tgql_query

