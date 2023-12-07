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
    
    ###########generate queries##############
    def _get_queries(self):
        file_path="peak_vertices/update_frequency/update_Num"+str(tpokec._max_update_op)+"_Avg"+str(tpokec.avg_update_ratio)+"_R"+str(tpokec.update_ratio)+".csv"
        self._update_person_lists=self._get_type_lists(file_path,csv_path,update_type_num)

def split_into_approx_equal_parts(input_list, num_parts):
    avg_part_size = len(input_list) // num_parts  # 计算平均每部分的大小
    remainder = len(input_list) % num_parts  # 计算余数

    divided_parts = []  # 存储切分后的部分

    # 逐个创建每个部分
    start = 0
    for i in range(num_parts):
        part_size = avg_part_size
        # 如果还有余数，每部分多分一个元素
        if remainder > 0:
            part_size += 1
            remainder -= 1
        end = start + part_size
        divided_parts.append(input_list[start:end])
        start = end

    return divided_parts

def get_update_queries(size="sf1",max_op=100000,update_num="100k",update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100,scale="100k",file_prefix="Default",data_prefix="Default"):
    gmark=gMark(size,max_op,update_ratio,delete_ratio,create_ratio,avg_update_ratio)
    #####update content#####
    file_path=f"{file_prefix}/{update_num}/{scale}/peak_vertices/update_content_Num"+str(gmark._max_graph_op)
    csv_path=f"{data_prefix}/social/social-a-{scale}/social-a-graph.csv"
    update_id_lists=gmark._get_type_lists(file_path,csv_path)s
    tgdb_write_lists, tgql_write_lists=gmark._update(update_id_lists)

    update_file_path=f"{file_prefix}/{update_num}/{scale}/graph_op/update_Num"+str(gmark._max_graph_op)+f".txt"
    gmark.write_to_file(update_file_path,tgdb_write_lists)

    update_file_path=f"{file_prefix}/{update_num}/{scale}/graph_op/tgql_update_Num"+str(gmark._max_graph_op)+f".txt"
    gmark.write_to_file(update_file_path,tgql_write_lists)



