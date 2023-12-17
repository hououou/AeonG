import random
import csv
import os
import re
import string

class LDBC():
    def __init__(self,size="sf1",max_op=100000,update_ratio=1,delete_ratio=0,create_ratio=0,avg_update_ratio=100):
        SIZES = {
            "sf0.1": {"vertices": 327588, "edges": 1477965},
            "sf1": {"vertices": 3181724, "edges": 17256038},
            "sf3": {"vertices": 9281922, "edges": 52695735},
            "sf10": {"vertices": 1, "edges": 1},
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
        
        #每一个类别节点个数的上限
        self._update_vertices_num=int(self._max_update_op/self._avg_update_ratio) #更新节点的数目
        self._update_personlists_num=int(self._update_vertices_num*0.5) #更新节点的数目
        self._update_commentlists_num=int(self._update_vertices_num*0.25)
        self._update_postlists_num=self._update_vertices_num-self._update_personlists_num-self._update_commentlists_num
        
        #每一个类别总query的上限
        self._update_person_num=int(self._max_update_op*0.5)
        self._update_comment_num=int(self._max_update_op*0.25)
        self._update_post_num=self._max_update_op-self._update_person_num-self._update_comment_num
        #生成的数目
        self._count_person_op=0#int(self._max_graph_op*0.5)
        self._count_comment_op=0#int(self._max_graph_op*0.25)
        self._count_post_op=0#self._max_graph_op-self._max_person_op-self._max_comment_op
        #更新的节点id
        self._update_person_lists=[] 
        self._update_comment_lists=[] 
        self._update_post_lists=[] 

        print("max_graph_op",self._max_graph_op)
        print("update_op",self._max_update_op)
        print("update_person_num",self._update_person_num)
        print("self._avg_update_ratio",self._avg_update_ratio)
    
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

    def _get_type_lists(self,file_path,csv_path,update_type_num):
        if(self.exist_file(file_path) == True):#如果节点有随机挑选，即有路径，则直接读取文件中被选择的节点
            # self._update_person_lists=self.read_from_file(file_path)
            return self.read_from_file(file_path)
        else:
            update_type_lists=[]
            lines=open(csv_path).readlines()
            lens=len(lines)
            b_list = range(0,lens)
            selected_lists=random.sample(b_list, update_type_num)
            for i in selected_lists:
                person_id=(lines[i].split("|"))[0]
                update_type_lists.append(person_id)
            #保存节点更新的list
            self.write_to_file(file_path=file_path,write_lists=update_type_lists)
            return update_type_lists
    
    def check_person_count_num(self):
        return self._count_person_op>=self._update_person_num
    
    def check_comment_count_num(self):
        return self._count_comment_op>=self._update_comment_num
    
    def check_post_count_num(self):
        return self._count_post_op>=self._update_post_num
    
    ###########update query###########
    #update person
    def query_person_set_ip(self,v_id,gen_type):
        location_ip=self.ip_generator()
        query=""
        if(gen_type=="TGDB"):
            query=f"MATCH (p:Person {{id: {v_id}}}) SET p.locationIP ='{location_ip}';"
        else:
            query=f"MATCH (o:Object {{id: 'Person{v_id}'}})-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'locationIP' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1=f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2=f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{location_ip}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state=query+query1+query2
            query=query_state
        return  query

    def query_person_set_browser(self,v_id,gen_type):
        browser = self.browserUsed[random.randint(0, 3)]
        query=""
        if(gen_type=="TGDB"):
            query=f"MATCH (p:Person {{id: {v_id}}}) SET p.browserUsed ='{browser}';"
        else:
            query=f"MATCH (o:Object {{id: 'Person{v_id}'}})-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'browserUsed' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1=f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2=f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{browser}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
            query_state=query+query1+query2
            query=query_state
        return  query

    #update comment
    def query_comment_set_content(self,comment_id,gen_type):
        content=self.ranstr(5)
        query=""
        if(gen_type=="TGDB"):
            query=f"MATCH (c:Comment {{id: {comment_id}}}) SET c.content ='{content}';"
        else:
            query=f"MATCH (o:Object {{id: 'Comment{comment_id}'}})-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'content' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1=f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2=f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{content}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state=query+query1+query2
            query=query_state
        return  query

    #update post
    def query_post_set_content(self,post_id,gen_type):
        content=self.ranstr(5)
        query=""
        if(gen_type=="TGDB"):
            query=f"MATCH (p:Post {{id: {post_id}}}) SET p.content ='{content}';"
        else:
            query=f"MATCH (o:Object {{id: 'Post{post_id}'}})-[:OBJECT_ATTRIBUTE]->(a:Attribute {{ title:'content' }})-[:ATTRIBUTE_VALUE]->(v:Value) "
            query1=f" where v.validTimeEnd=9223372036854775000  set v.validTimeEnd=timestamp() "
            query2=f" Create (a)-[:ATTRIBUTE_VALUE]->(v2:Value {{title:'{content}', validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}); "
            query_state=query+query1+query2
            query=query_state
        return  query
    
    ####### add query ##########
    def query_add_person():
        self._id_to_be = self._id_to_be + 1
        tgql_query=""
        query=""
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            line_id=random(1,len(reader))
            row=reader[line_id]
            head=reader[0]
            # tgdb
            query=f"CREATE (p:Person {{id: {self._id_to_be}},firstName:'{fn}',lastName:'{ln}',gender:'{gd}',birthday:{bd},creationDate:{cd},locationIP:'{ip}',browserUsed:'{bu}'});"
            # tgql
            node_id=f"Person{self._id_to_be}"
            node_info=f"Create (n:Object {{ title:'{node_type}',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
            #create id
            query_state=f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "+\
                        f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{self._id_to_be},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
            att_infos=" "
            for j in range(0,len(row)):
                attribute_name=head[j]
                attribute_value=row[j]
                if(attribute_name=="id"):
                    continue
                if(attribute_value==""):
                    continue
                attribute_index="a"+str(j)
                attribute_info=f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                value_info=f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                att_infos=att_infos+attribute_info+value_info           
            tgql_query=node_info+query_state+att_infos
        return query,tgql_query

    def query_add_comment():
        self._id_to_be = self._id_to_be + 1
        tgql_query=""
        query=""
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            line_id=random(1,len(reader))
            head=reader[0]
            row=reader[line_id]
            # tgdb
            query=f"CREATE (p:Comment {{id: {self._id_to_be}},creationDate:{cd},locationIP:'{ip}',browserUsed:'{bu}',content:'{con}',length:'{l}'});"
            # tgql
            node_id=f"Comment{self._id_to_be}"
            node_info=f"Create (n:Object {{ title:'{node_type}',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
            #create id
            query_state=f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "+\
                        f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{self._id_to_be},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
            att_infos=" "
            for j in range(0,len(row)):
                attribute_name=head[j]
                attribute_value=row[j]
                if(attribute_name=="id"):
                    continue
                if(attribute_value==""):
                    continue
                attribute_index="a"+str(j)
                attribute_info=f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                value_info=f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                att_infos=att_infos+attribute_info+value_info           
            tgql_query=node_info+query_state+att_infos
        return query,tgql_query

    def query_add_post():
        self._id_to_be = self._id_to_be + 1
        tgql_query=""
        query=""
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            line_id=random(1,len(reader))
            head=reader[0]
            row=reader[line_id]
            # tgdb
            query=f"CREATE (p:Post {{id: {self._id_to_be}},imageFile:'{if}',creationDate:{cd},locationIP:'{ip}',browserUsed:'{bu}',language:'{la}',content:'{con}',length:'{l}'});"
            # tgql
            node_id=f"Post{self._id_to_be}"
            node_info=f"Create (n:Object {{ title:'{node_type}',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"
            #create id
            query_state=f" Create (n)-[:OBJECT_ATTRIBUTE]->(a:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "+\
                        f" Create (a)-[:ATTRIBUTE_VALUE]->(v:Value {{title:{self._id_to_be},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}})"
            att_infos=" "
            for j in range(0,len(row)):
                attribute_name=head[j]
                attribute_value=row[j]
                if(attribute_name=="id"):
                    continue
                if(attribute_value==""):
                    continue
                attribute_index="a"+str(j)
                attribute_info=f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                value_info=f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                att_infos=att_infos+attribute_info+value_info           
            tgql_query=node_info+query_state+att_infos
        return query,tgql_query

    def add_edge(from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}}),(n2 {{id:{to_node}}}) with n1, n2 Create (n1)-[:edge_type]-(n2);"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 Create (o1)-[:edge_type]-(o2);"
        return query,tgql_query
    ######### delete query ############
    def delete_node(node_label,person_id):
        query=f"MATCH (p:Person {{id:{person_id}}})-[e]-() delete e, p;"
        tgql_query1=f"MATCH (p:Object {{id:{node_label}{person_id}}})-[o:OBJECT_ATTRIBUTE]-(att)-[a:ATTRIBUTE_VALUE]-(v) delete o,a,att,v;"
        tgql_query2=f"MATCH (p:Object {{id:{node_label}{person_id}}})-[e]-() delete e;"
        return query, tgql_query1,tgql_query2

    def delete_edge(from_node, edge_type, to_node):
        query=f"MATCH (n1 {{id:{from_node}}})-[e:{edge_type}]-(n2 {{id:{to_node}}}) delete e;"
        tgql_query=f"MATCH (o1:Object)-[o:OBJECT_ATTRIBUTE]-(att {{title:'id'}})-[a:ATTRIBUTE_VALUE]-(v {{title:{from_node}}}),(o2:Object)-[:OBJECT_ATTRIBUTE]-(att2 {{title:'id'}})-[a2:ATTRIBUTE_VALUE]-(v2 {{title:{to_node}}}) with o1, o2 MATCH (o1)-[e:edge_type]-(o2) delete e;"
        return query,tgql_query

    ###########update vertex property##############
    def _update_person(self): 
        tgdb_write_lists=[]
        tgql_write_lists=[]
        for i in range(0,self._avg_update_ratio):
            # print("update_person_lists",self._update_person_lists)
            for person_id in self._update_person_lists:
                tgdb_person_set_ip=self.query_person_set_ip(person_id,"TGDB")
                tgql_person_set_ip=self.query_person_set_ip(person_id,"TGQL")
                tgdb_write_lists.append(tgdb_person_set_ip)
                tgql_write_lists.append(tgql_person_set_ip)         
                tgdb_person_set_browser=self.query_person_set_browser(person_id,"TGDB")
                tgql_person_set_browser=self.query_person_set_browser(person_id,"TGQL")
                tgdb_write_lists.append(tgdb_person_set_browser)
                tgql_write_lists.append(tgql_person_set_browser)
                self._count_person_op+=2
                if(self.check_person_count_num()): 
                    break
            if(self.check_person_count_num()): 
                break
        if(self.check_person_count_num()==False):
            for person_id in self._update_person_lists:
                tgdb_person_set_ip=self.query_person_set_ip(person_id,"TGDB")
                tgql_person_set_ip=self.query_person_set_ip(person_id,"TGQL")
                tgdb_write_lists.append(tgdb_person_set_ip)
                tgql_write_lists.append(tgql_person_set_ip)
                
                tgdb_person_set_browser=self.query_person_set_browser(person_id,"TGDB")
                tgql_person_set_browser=self.query_person_set_browser(person_id,"TGQL")
                tgdb_write_lists.append(tgdb_person_set_browser)
                tgql_write_lists.append(tgql_person_set_browser)
                self._count_person_op+=2
                if(self.check_person_count_num()): 
                    break
        print("check_num",self._count_person_op)
        return tgdb_write_lists,tgql_write_lists
    
    def _update_comment(self): 
        tgdb_write_lists=[]
        tgql_write_lists=[]
        for i in range(0,self._avg_update_ratio):
            for comment_id in self._update_comment_lists:
                tgdb_comment=self.query_comment_set_content(comment_id,"TGDB")
                tgql_comment=self.query_comment_set_content(comment_id,"TGQL")
                tgdb_write_lists.append(tgdb_comment)
                tgql_write_lists.append(tgql_comment)         
                self._count_comment_op+=1
                if(self.check_comment_count_num()): 
                    break
            if(self.check_comment_count_num()): 
                break
        if(self.check_comment_count_num()==False):
            for comment_id in self._update_comment_lists:
                tgdb_comment=self.query_comment_set_content(comment_id,"TGDB")
                tgql_comment=self.query_comment_set_content(comment_id,"TGQL")
                tgdb_write_lists.append(tgdb_comment)
                tgql_write_lists.append(tgql_comment)         
                self._count_comment_op+=1
                if(self.check_comment_count_num()): 
                    break
        print("comment_check_num",self._count_comment_op)
        return tgdb_write_lists,tgql_write_lists
    
    def _update_post(self): 
        tgdb_write_lists=[]
        tgql_write_lists=[]
        for i in range(0,self._avg_update_ratio):
            for post_id in self._update_post_lists:
                tgdb_post=self.query_post_set_content(post_id,"TGDB")
                tgql_post=self.query_post_set_content(post_id,"TGQL")
                tgdb_write_lists.append(tgdb_post)
                tgql_write_lists.append(tgql_post)         
                self._count_post_op+=1
                if(self.check_post_count_num()): 
                    break
            if(self.check_post_count_num()): 
                break
        if(self.check_comment_count_num()==False):
            for post_id in self._update_post_lists:
                tgdb_post=self.query_post_set_content(post_id,"TGDB")
                tgql_post=self.query_post_set_content(post_id,"TGQL")
                tgdb_write_lists.append(tgdb_post)
                tgql_write_lists.append(tgql_post)         
                self._count_post_op+=1
                if(self.check_post_count_num()): 
                    break
        print("post_check_num",self._count_post_op)
        return tgdb_write_lists,tgql_write_lists

       
