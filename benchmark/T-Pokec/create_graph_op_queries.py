import random
import csv
import os
import re
import numpy as np
from collections import Counter
import copy
import pandas as pd

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
        self._max_graph_op=self.max_op_ratio#int(self._num_vertices*self.max_op_ratio) #图操作的数量
        self._max_update_op=int(self._max_graph_op*update_ratio) #update操作的数量
        self._max_delete_op=int(self._max_graph_op*delete_ratio) #delete操作的数量
        self._max_create_op=self._max_graph_op-self._max_update_op-self._max_delete_op  #create操作的数量

        self._avg_update_ratio=avg_update_ratio #平均每个节点更新的次数
        self._update_vertices_lists=[] #更新的节点
        self._update_vertices_num=int(self._max_update_op/self._avg_update_ratio) #更新节点的数目
        self._count_update_num=0

    
    #####help function#####
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

    def _get_random_vertex_u(self):
        # All vertices in the Pokec dataset have an ID in the range
        # [1, _num_vertices].
        # print("here")
        return random.randint(1, self._num_vertices)
    
    def _get_random_num(self):
        return random.randint(1, 100)

    def write_to_file(self,file_path,write_lists):
        # print(file_path)
        # os.mknod(file_path)
        f1 = open(file_path, "w",encoding='utf-8')
        for key in write_lists:
            f1.write(str(key)+"\n")
        f1.close()
    
    def write_to_bigfile(self,file_path,write_lists):
        f1 = open(file_path+"0.json","w",encoding='utf-8')
        current = 0
        for i, query in enumerate(write_lists):
            if int(i / 1000000) == current:
                f1.write(str(query)+"\n")
            else:
                f1.close()
                current = int(i / 1000000)
                f1 = open(file_path+str(current)+".json","w",encoding='utf-8')
                f1.write(str(query)+"\n")
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

    ######update graph operations#######
    def _get_update_vertices_lists(self,file_path,file_name): 
        if(self.exist_file(file_path+file_name) == True and self.exist_file(file_path+"counts_"+file_name) == True):#如果节点有随机挑选，即有路径，则直接读取文件中被选择的节点
            self._update_vertices_lists=self.read_from_file(file_path+file_name)
        else:
            left = np.uint64(1)
            right = np.uint64(self._num_vertices)
            update_vertices_lists=self.Zipf(1.1, left, right,self._max_update_op)
            self._update_vertices_lists=update_vertices_lists.tolist()
            #保存节点更新的list
            self.write_to_file(file_path=file_path+file_name,write_lists=self._update_vertices_lists)
            status=pd.value_counts(self._update_vertices_lists)
            status.to_csv(file_path+"counts_"+file_name,header=False)
        # print(self._update_vertices_lists)
    
    def check_count_num(self):
        return self._count_update_num>=self._max_update_op   
    
    def _update__vertex_on_property(self): #更新completion_percentage
        write_lists=[]
        for v_id in self._update_vertices_lists:
            query_statement=  " [ \" MATCH (n:User {id:"+str(v_id)+"}) SET n.completion_percentage = "+str(self._get_random_num())+"\",{}]" 
            write_lists.append(query_statement)
            self._count_update_num+=1
            if(self.check_count_num()): 
                break
        if(self.check_count_num()==False):
            for v_id in self._update_vertices_lists:
                query_statement=  " [ \" MATCH (n:User {id:"+str(v_id)+"}) SET n.completion_percentage = "+str(self._get_random_num())+"\",{}]" 
                write_lists.append(query_statement)
                self._count_update_num+=1
                if(self.check_count_num()):
                    break
        print("check_num",self._count_update_num)
        return write_lists
    
    ######create graph operations#######
    def _get_random_vertex(self):
        max_vertex=int(self._max_create_op/2)
        return random.randint(self._num_vertices, self._num_vertices+max_vertex)

    def _get_random_from_to(self):
        vertex_from = self._get_random_vertex()
        vertex_to = vertex_from
        while vertex_to == vertex_from:
            vertex_to = self._get_random_vertex()
        return (vertex_from, vertex_to)

    def _create_vertex(self):
        write_lists=[]
        vid_sets=set()
        max_vertex=int(self._max_create_op/2)
        for i in range(1,max_vertex+1):
            vid_sets.add(self._num_vertices+i)    
            create_q="[ \" CREATE (n:User {id : "+str(self._num_vertices+i)+"}) set n.completion_percentage = "+str(self._get_random_num())+" RETURN n "+"\",{}]" 
            write_lists.append(create_q)
        return (write_lists,vid_sets)
        
    def _create_edge(self):
        write_lists=[]
        vid_sets=set()
        max_edge=int(self._max_create_op/2)
        for i in range(0,max_edge):
            vertex_from, vertex_to = self._get_random_from_to()
            create_q= "[ \" MATCH (a:User {id:"+ str(vertex_from)+"}), (b:User {id: "+str(vertex_to)+"}) CREATE (a)-[:Friend]->(b)"+"\",{}]" 
            write_lists.append(create_q)
            vid_sets.add(vertex_from)
            vid_sets.add(vertex_to)
        return (write_lists,vid_sets)

    ######delete graph operations#######
    def _delete_edges(self):
        with open(self._dataset_file_path,"r") as f:
            write_lists=[]
            vid_sets=set()
            lines=f.readlines()
            resultlists=random.sample(range(self._num_vertices+1,self._num_vertices+self._num_edges),self._max_delete_op)
            for i in resultlists:
                query=str(lines[i])#.replace("CREATE","DELETE")
                # query=query.replace("\n","")
                vids=re.findall(r"\d+\.?\d*",query)
                vid_sets.add(int(vids[0]))
                vid_sets.add(int(vids[1]))
                del_query="[ \" MATCH (n:User {id:"+str(vids[0])+"})-[e]->(m:User {id:"+str(vids[1])+"}) DELETE e  "+"\",{}]" 
                write_lists.append(del_query)
        return (write_lists,vid_sets)
    
    #TGQL query生成 update 
    def TGQL_update__vertex_on_property(self):#更新completion_percentage
        write_lists=[]
        for v_id in self._update_vertices_lists:
            query_statement=  " [ \" MATCH (n :Value{title:"+str(v_id)+"})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o) "+\
                            " Match (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute { title:'completion_percentage' })-[:ATTRIBUTE_VALUE]->(v:Value) "+\
                            " where v.validTimeEnd=9223372036854775000 "+\
                            " set v.validTimeEnd=timestamp() "+\
                            " Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {title:"+str(self._get_random_num())+\
                            ", validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
                            "\",{}]" 
            write_lists.append(query_statement)
            self._count_update_num+=1
            if(self.check_count_num()): 
                break
        if(self.check_count_num()==False):
            for v_id in self._update_vertices_lists:
                query_statement=  " [ \" MATCH (n :Value{title:"+str(v_id)+"})-[:ATTRIBUTE_VALUE]-(:Attribute{title: 'id'})-[:OBJECT_ATTRIBUTE]-(o) "+\
                                " Match (o)-[:OBJECT_ATTRIBUTE]->(a:Attribute { title:'completion_percentage' })-[:ATTRIBUTE_VALUE]->(v:Value) "+\
                                " where v.validTimeEnd=9223372036854775000 "+\
                                " set v.validTimeEnd=timestamp() "+\
                                " Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {title:"+str(self._get_random_num())+\
                                ", validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
                                "\",{}]" 
                # query_statement=  " [ \" MATCH (n {id:"+str(v_id)+"}) SET n.property = "+str(self._get_random_vertex())+"\",{}]" 
                write_lists.append(query_statement)
                self._count_update_num+=1
                if(self.check_count_num()):
                    break
        print("check_num",self._count_update_num)
        return write_lists
    
    def TGQL_create_vertex(self):
        write_lists=[]
        vid_sets=set()
        max_vertex=int(self._max_create_op/2)
        for i in range(1,max_vertex+1):
            vid_sets.add(self._num_vertices+i)  
            query_state=" Create (n:Object{ title:'User',id:"+str(self._num_vertices+i)+",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
        " Create (n)-[:OBJECT_ATTRIBUTE]->(a1:Attribute {title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
        " Create (n)-[:OBJECT_ATTRIBUTE]->(a2:Attribute {title:'completion_percentage',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
        " Create (a1)-[:ATTRIBUTE_VALUE]->(:Value {title:"+str(self._num_vertices+i)+",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "+\
        " Create (a2)-[:ATTRIBUTE_VALUE]->(:Value {title:"+str(self._get_random_num())+",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) "
            write_lists.append("[ \""+query_state+"\",{}]" )
        return (write_lists,vid_sets)
        
    def TGQL_create_edge(self):
        write_lists=[]
        vid_sets=set()
        max_edge=int(self._max_create_op/2)
        for i in range(0,max_edge):
            vertex_from, vertex_to = self._get_random_from_to()
            create_q=" Match (n:Object{ id:"+str(vertex_from)+" }), (m:Object{ id:"+str(vertex_to)+"})"+\
                    " Create (n)-[e:Friend]->(m) set e.validTimeStart=timestamp(), e.validTimeEnd=9223372036854775000"
            write_lists.append("[ \""+create_q+"\",{}]" )
            vid_sets.add(vertex_from)
            vid_sets.add(vertex_to)
        return (write_lists,vid_sets)
    
    def TGQL_delete_edges(self):
        with open(self._dataset_file_path,"r") as f:
            write_lists=[]
            vid_sets=set()
            lines=f.readlines()
            resultlists=random.sample(range(self._num_vertices+1,self._num_vertices+self._num_edges),self._max_delete_op)
            for i in resultlists:
                query=str(lines[i]) # .replace("CREATE","DELETE")
                vids=re.findall(r"\d+\.?\d*",query)
                vid_sets.add(int(vids[0]))
                vid_sets.add(int(vids[1]))
                delete_q=" Match (n:Object{ id:"+str(vids[0])+" })-[e]->(m:Object{ id:"+str(vids[1])+"})"+\
                    " where e.validTimeEnd=9223372036854775000 set e.validTimeEnd=timestamp();"      
                write_lists.append("[ \""+delete_q+"\",{}]" )
        return (write_lists,vid_sets)
    