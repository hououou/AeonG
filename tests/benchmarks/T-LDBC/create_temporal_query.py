import random
import csv
import os
import argparse

class LDBC():
    def __init__(self,size="sf1",max_ops=8000):
        SIZES = {
            "sf0.1": {"vertices": 327588, "edges": 1477965},
            "sf1": {"vertices": 3181724, "edges": 17256038},
            "sf3": {"vertices": 9281922, "edges": 52695735},
            "sf10": {"vertices": 1, "edges": 1},
        }

        self._size=size
        self._max_graph_op=max_ops
        self._num_vertices=SIZES[size]["vertices"]
        self._num_edges=SIZES[size]["edges"]
        self._update_vertices_lists=[]
        self._count_update_num=0


    # help function
    def write_to_file(self,file_path,write_lists):
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
            while len(hot_target_vertex)<100:
                if len(hot_vertex) >= 100:
                    hot_target_vertex=hot_target_vertex+random.sample(hot_vertex,100)
                else:
                    hot_target_vertex=hot_target_vertex+hot_vertex
            while len(warm_target_vertex)<100:
                if len(warm_vertex) >= 100:
                    warm_target_vertex=warm_target_vertex+random.sample(warm_vertex,100)
                else:
                    warm_target_vertex=warm_target_vertex+warm_vertex
            while len(cold_target_vertex)<100:
                if len(cold_vertex) >= 100:
                    cold_target_vertex=cold_target_vertex+random.sample(cold_vertex,100)
                else:
                    cold_target_vertex=cold_target_vertex+cold_vertex
            if types== "hot":
                query_vertex_list=hot_target_vertex
            if types== "warm":
                query_vertex_list=warm_target_vertex
            if types== "cold":
                query_vertex_list=cold_target_vertex
            if types== "mix":
                query_vertex_list=hot_target_vertex[:33]+cold_target_vertex[:33]+cold_vertex[:33]
        return query_vertex_list

    def _get_random_time(self,min_t,max_t):
        return random.randint(min_t, max_t)

    #read
    def IS1(self,person_id,min,max):
        ts=self._get_random_time(min,max)
        cypher_query=f"MATCH (n:Person {{id:{person_id}}})-[:IS_LOCATED_IN]->(p:Place) TT AS {ts}"+" RETURN n.firstName AS firstName, n.lastName AS lastName, n.birthday AS birthday, n.locationIP AS locationIp," \
                                                                                                   "n.browserUsed AS browserUsed," \
                                                                                                   "n.gender AS gender," \
                                                                                                   "n.creationDate AS creationDate," \
                                                                                                   "p.id AS cityId;"
        tq_head = f"MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:{person_id}}}),"+ \
                  " (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute)-[e2:ATTRIBUTE_VALUE]-(val2:Value) ,"+ \
                  f" (n)-[r:isLocatedIn]->(p:Object{{title:'Place'}})-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute {{title:'id'}})-[pe2:ATTRIBUTE_VALUE]-(val3:Value)"
        tq_condition1 = f" where n.validTimeStart<={ts} and n.validTimeEnd>{ts} " + \
                        f" and val.validTimeStart<={ts} and val.validTimeEnd>{ts} " + \
                        f" and val2.validTimeStart<={ts} and val2.validTimeEnd>{ts} "
        tq_return=" return n,e1,att,e2,val2,r,p,pe1,pa1,pe2,val3;"
        tgql_cypher=tq_head+tq_condition1+tq_condition1
        return cypher_query,tgql_cypher

    def IS2(self,person_id,min,max):
        ts=self._get_random_time(min,max)
        cypher_query=f"""MATCH (:Person {{id:{person_id}}})<-[:HAS_CREATOR]-(m)-[:REPLY_OF*0..]->(p:Post)
                    MATCH (p)-[:HAS_CREATOR]->(c) 
                    TT AS {ts}
                    RETURN
                    m.id as messageId,
                    CASE m.content is not null
                        WHEN true THEN m.content
                        ELSE m.imageFile
                    END AS messageContent,
                    m.creationDate AS messageCreationDate,
                    p.id AS originalPostId,
                    c.id AS originalPostAuthorId,
                    c.firstName as originalPostAuthorFirstName,
                    c.lastName as originalPostAuthorLastName
                    ORDER BY messageCreationDate DESC
                    LIMIT 10;
                    """
        cypher_query=cypher_query.replace("\n"," ")
        tgql_cypher=f"""
        MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(att:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:{person_id}}})
        ,(n)<-[:hasCreator]-(m:Object)-[:replyOf*0..]->(p:Object)
        , (p)-[:hasCreator]->(c:Object)
        with  m,p,c
        match (m)-[:OBJECT_ATTRIBUTE]-(m_id:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(m_id_val:Value),
        (m)-[:OBJECT_ATTRIBUTE]-(m_content:Attribute {{title:'content'}})-[:ATTRIBUTE_VALUE]-(m_content_val:Value),
        (m)-[:OBJECT_ATTRIBUTE]-(m_creationDate:Attribute {{title:'creationDate'}})-[:ATTRIBUTE_VALUE]-(m_creationDate_val:Value),
        (p)-[:OBJECT_ATTRIBUTE]-(p_id:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(p_id_val:Value),
        (c)-[:OBJECT_ATTRIBUTE]-(c_id:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(c_id_val:Value),
        (c)-[:OBJECT_ATTRIBUTE]-(c_firstName:Attribute {{title:'firstName'}})-[:ATTRIBUTE_VALUE]-(c_firstName_val:Value),
        (c)-[:OBJECT_ATTRIBUTE]-(c_lastName:Attribute {{title:'lastName'}})-[:ATTRIBUTE_VALUE]-(c_lastName_val:Value)
        where m_id_val.validTimeStart<={ts} and m_id_val.validTimeEnd>{ts}
        and m_content_val.validTimeStart<={ts} and m_content_val.validTimeEnd>{ts}
        and m_creationDate_val.validTimeStart<={ts} and m_creationDate_val.validTimeEnd>{ts}
        and p_id_val.validTimeStart<={ts} and p_id_val.validTimeEnd>{ts}
        and c_id_val.validTimeStart<={ts} and c_id_val.validTimeEnd>{ts}
        and c_firstName_val.validTimeStart<={ts} and c_lastName_val.validTimeEnd>{ts}
        and c_lastName_val.validTimeStart<={ts} and c_lastName_val.validTimeEnd>{ts}
        RETURN
        m_id_val.title as messageId,
        m_content_val.title as messageContent,
        m_creationDate_val.title AS messageCreationDate,
        p_id_val.title AS originalPostId,
        c_id_val.title AS originalPostAuthorId,
        c_firstName_val.title as originalPostAuthorFirstName,
        c_lastName_val.title as originalPostAuthorLastName
        """
        tgql_cypher=tgql_cypher.replace("\n"," ")
        return cypher_query,tgql_cypher

    def IS3(self,person_id,min,max):
        ts=self._get_random_time(min,max)
        cypher_query=f"""MATCH (n:Person {{id:{person_id}}})-[r:KNOWS]-(friend)
                        TT AS {ts}
                        RETURN 
                        friend.id AS personId,
                        friend.firstName AS firstName,
                        friend.lastName AS lastName,
                        r.creationDate AS friendshipCreationDate 
                        ORDER BY friendshipCreationDate DESC, toInteger(personId) ASC;"""
        tgql_cypher = f"MATCH (n:Object {{title:'Person'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:{person_id}}})"+ \
                      " with n match (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute{title:'creationDate'})-[e2:ATTRIBUTE_VALUE]-(val2:Value) "+ \
                      f" where  val2.validTimeStart<={ts} and val2.validTimeEnd>{ts}"+ \
                      " with n,e1,att,e2,val2 "+ \
                      f" match (n)-[r:knows]->(p:Object)-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute) "+ \
                      f" where pa1.title='id' or pa1.title='firstName' or pa1.title='lastName'"+ \
                      " with n,e1,att,e2,val2,r,p,pe1,pa1"+ \
                      " match (pa1)-[pe2:ATTRIBUTE_VALUE]-(val3:Value) "+ \
                      f" where val3.validTimeStart<={ts} and val3.validTimeEnd>{ts} " + \
                      "return n,e1,att,e2,val2,r,p,pe1,pa1,pe2,val3;"
        return cypher_query,tgql_cypher

    def IS4(self,v_id,min,max):
        ts=self._get_random_time(min,max)
        query1=f"MATCH (m:Message {{id:{v_id}}}) TT AS {ts}"
        query_return=" RETURN " \
                     "CASE m.content IS NOT NULL " \
                     " WHEN true THEN m.content " \
                     "ELSE m.imageFile " \
                     "END AS messageContent," \
                     "m.creationDate as messageCreationDate;"
        cypher_query=query1+query_return
        tq_head = f"MATCH (n:Object {{title:'Comment'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:{v_id}}})"+ \
                  " with n match (n)-[e1:OBJECT_ATTRIBUTE]-(att:Attribute) "+ \
                  f" where att.title='content' or att.title='imageFile' or att.title='creationDate' "+ \
                  " with n,e1,att match (att)-[e2:ATTRIBUTE_VALUE]-(val2:Value) "
        tq_condition = f" where val2.validTimeStart<={ts} and val2.validTimeEnd>{ts} "
        tq_return=" return n,e1,att,e2,val2;"
        tgql_cypher=tq_head+tq_condition+tq_return
        return cypher_query,tgql_cypher

    def IS5(self,v_id,min,max):
        ts=self._get_random_time(min,max)
        query1=f"MATCH (m:Message {{id:{v_id}}})-[:HAS_CREATOR]->(p:Person) TT AS {ts}"
        query_return=" RETURN " \
                     " p.id,p.firstName,p.lastName; "
        cypher_query=query1+query_return

        tq_head = f"MATCH (n:Object {{title:'Comment'}})-[:OBJECT_ATTRIBUTE]-(:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(val:Value {{title:{v_id}}}),"+ \
                  f" (n)-[r:hasCreator]->(p:Object{{title:'Person'}})-[pe1:OBJECT_ATTRIBUTE]-(pa1:Attribute)" + \
                  f" where pa1.title='id' or pa1.title='firstName' or pa1.title='lastName' "+ \
                  " with n,p,pe1,pa1 match (pa1)-[pe2:ATTRIBUTE_VALUE]-(val3:Value) "
        tq_condition = f" where val3.validTimeStart<={ts} and val3.validTimeEnd>{ts} "
        tq_return=" return p,pe1,pa1,pe2,val3;"
        tgql_cypher=tq_head+tq_condition+tq_return
        return cypher_query,tgql_cypher
    def IS6(self,v_id,min,max):
        ts=self._get_random_time(min,max)
        query1=f"""MATCH (m:Message {{id:{v_id}}})<-[:REPLY_OF]-(c:Comment)-[:HAS_CREATOR]->(p:Person)
                OPTIONAL MATCH (m)-[:HAS_CREATOR]->(a:Person)-[r:KNOWS]-(p)
                TT AS {ts}
                RETURN
                c.id AS commentId,
                c.content AS commentContent,
                c.creationDate AS commentCreationDate,
                p.id AS replyAuthorId,
                p.firstName AS replyAuthorFirstName,
                p.lastName AS replyAuthorLastName,
                CASE r
                    WHEN null THEN false
                    ELSE true
                END AS replyAuthorKnowsOriginalMessageAuthor
                ORDER BY commentCreationDate DESC, toInteger(replyAuthorId) ASC;
                    """
        cypher_query=query1.replace("\n"," ")

        tgql_cypher=f"""
        MATCH (val:Value{{title:{v_id}}})-[:ATTRIBUTE_VALUE]-(:Attribute {{title:'id'}})-[:OBJECT_ATTRIBUTE]-(m:Object {{title:'Comment'}})
        with m,val
        match (m)-[:replyOf*0..]->(p:Object{{title:'Post'}})<-[:containerOf]-(f:Object{{title:'Forum'}})-[:hasModerator]->(mod:Object{{title:'Person'}})
        with m,p,mod,f
        match (f)-[:OBJECT_ATTRIBUTE]-(f_id:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(f_id_val:Value),
        (f)-[:OBJECT_ATTRIBUTE]-(f_title:Attribute {{title:'title'}})-[:ATTRIBUTE_VALUE]-(f_title_val:Value),
        (mod)-[:OBJECT_ATTRIBUTE]-(mod_id:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(mod_id_val:Value),
        (mod)-[:OBJECT_ATTRIBUTE]-(mod_firstName:Attribute {{title:'firstName'}})-[:ATTRIBUTE_VALUE]-(mod_firstName_val:Value),
        (mod)-[:OBJECT_ATTRIBUTE]-(mod_lastName:Attribute {{title:'lastName'}})-[:ATTRIBUTE_VALUE]-(mod_lastName_val:Value)
        where f_id_val.validTimeStart<={ts} and f_id_val.validTimeEnd>{ts}
        and f_title_val.validTimeStart<={ts} and f_title_val.validTimeEnd>{ts}
        and mod_id_val.validTimeStart<={ts} and mod_id_val.validTimeEnd>{ts}
        and mod_firstName_val.validTimeStart<={ts} and mod_firstName_val.validTimeEnd>{ts}
        and mod_lastName_val.validTimeStart<={ts} and mod_lastName_val.validTimeEnd>{ts}
        RETURN
        f_id_val.title AS forumId,
        f_title_val.title AS forumTitle,
        mod_id_val.title AS moderatorId,
        mod_firstName_val.title AS moderatorFirstName,
        mod_lastName_val.title AS moderatorLastName;
        """
        tgql_cypher= tgql_cypher.replace("\n"," ")
        return cypher_query,tgql_cypher

    def IS7(self,v_id,min,max):
        ts=self._get_random_time(min,max)
        cypher_query=f"""MATCH (m:Comment {{id:{v_id}}})<-[:REPLY_OF]-(c:Comment)-[:HAS_CREATOR]->(p:Person)
                OPTIONAL MATCH (m)-[:HAS_CREATOR]->(a:Person)-[r:KNOWS]-(p) TT AS {ts}
                RETURN
                c.id AS commentId,
                c.content AS commentContent,
                c.creationDate AS commentCreationDate,
                p.id AS replyAuthorId,
                p.firstName AS replyAuthorFirstName,
                p.lastName AS replyAuthorLastName,
                CASE r
                    WHEN null THEN false
                    ELSE true
                END AS replyAuthorKnowsOriginalMessageAuthor
                ORDER BY commentCreationDate DESC, toInteger(replyAuthorId) ASC;
                """
        cypher_query=cypher_query.replace("\n"," ")
        tgql_cypher = f"""
            MATCH (val:Value{{title:{v_id}}})-[:ATTRIBUTE_VALUE]-(:Attribute {{title:'id'}})-[:OBJECT_ATTRIBUTE]-(m:Object {{title:'Comment'}})
            with m,val
            match (m)-[:replyOf]-(c:Object {{title:'Comment'}})-[:hasCreator]-(p:Object {{title:'Person'}})
            with m,c,p,val
            MATCH (c)-[:OBJECT_ATTRIBUTE]-(a1:Attribute {{title:'content'}})-[:ATTRIBUTE_VALUE]-(v1),
            (p)-[:OBJECT_ATTRIBUTE]-(a3:Attribute {{title:'firstName'}})-[:ATTRIBUTE_VALUE]-(v3),
            (p)-[:OBJECT_ATTRIBUTE]-(a4:Attribute {{title:'lastName'}})-[:ATTRIBUTE_VALUE]-(v4),
            (p)-[:OBJECT_ATTRIBUTE]-(a5:Attribute {{title:'id'}})-[:ATTRIBUTE_VALUE]-(v5)
            where v1.validTimeStart<={ts} and v1.validTimeEnd>{ts}
            and v3.validTimeStart<={ts} and v3.validTimeEnd>{ts}
            and v4.validTimeStart<={ts} and v4.validTimeEnd>{ts}
            and v5.validTimeStart<={ts} and v5.validTimeEnd>{ts}
            with  m,c,p,v1,v3,v4,v5,val
            OPTIONAL MATCH (m)-[:HAS_CREATOR]->(a:Object{{title:'Person'}})-[r:KNOWS]-(p)
            RETURN
                val.title AS commentId,
                v1.title AS commentContent,
                v1.title AS commentCreationDate,
                v5.title AS replyAuthorId,
                v3.title AS replyAuthorFirstName,
                v4.title AS replyAuthorLastName,
                CASE r
                    WHEN null THEN false
                    ELSE true
                END AS replyAuthorKnowsOriginalMessageAuthor
                ORDER BY commentCreationDate DESC, toInteger(id(p)) ASC;
        """
        tgql_cypher=tgql_cypher.replace("\n"," ")
        return cypher_query,tgql_cypher

    def IS(self,id,min,max,is_idx):
        is_functions = {
            1: self.IS1,
            2: self.IS2,
            3: self.IS3,
            4: self.IS4,
            5: self.IS5,
            6: self.IS6,
            7: self.IS7,
        }
        is_function = is_functions.get(is_idx)
        return is_function(id, min, max)

    def IS_queries(self,file_path,is_idx,min,max):
        query_type="mix"
        query_id_path=file_path.replace("count",f"{query_type}_ids")
        vid_lists=[]
        if self.exist_file(query_id_path):
            print("vid_lists",len(vid_lists))
            vid_lists=self.read_from_file(query_id_path)
        else:
            print("vid_lists",len(vid_lists))
            vid_lists=self._get_vertex_list(file_path,query_type)
            self.write_to_file(query_id_path,vid_lists)
        num=0
        cypher_lists=[]
        tgql_cypher_lists=[]
        while (True):
            for vid in vid_lists:
                cypher_query,tgql_cypher_query=self.IS(vid,min,max,is_idx)
                cypher_lists.append(cypher_query)
                tgql_cypher_lists.append(tgql_cypher_lists)
                num+=1
                if(num>=100):
                    break
            if(num>=100):
                break
        return cypher_lists,tgql_cypher_lists

if __name__ == "__main__":
    # Parse options.
    parser = argparse.ArgumentParser(
        description="AeonG create graph operation queries.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--size",
                        default="sf0.1",
                        help="Dataset size")
    parser.add_argument("--num-op",type=int,
                        default=80000,
                        help="The number of graph operation queries")
    parser.add_argument("--write-path",
                        default="../../results/",
                        help="The write path of reults")
    parser.add_argument("--max-time", type=int,
                        default=100,
                        help="Max time of the datasets life")
    parser.add_argument("--min-time", type=int,
                        default=0,
                        help="Min time of the datasets life")

    args = parser.parse_args()
    parsed_args = vars(args)
    print("=========check your configuration========")
    for key, value in parsed_args.items():
        print(f"  {key}: {value}")

    ldbc=LDBC(size=args.size,max_ops=args.num_op)
    peak_types={1:"person",2:"person",3:"person",4:"comment",5:"comment",6:"comment",7:"comment"}
    for index in range(1,7):
        peak_vertices_path=f"{args.write_path}/peak_vertices/update_{peak_types[index]}_Num{ldbc._max_graph_op}_update_count.csv"
        write_path=f"{args.write_path}/temporal_query/IS"+str(index)+"/"
        #q1
        cypher_lists,tgql_cypher_lists=ldbc.IS_queries(peak_vertices_path,index,args.min_time,args.max_time)
        ldbc.write_to_file(f"{args.write_path}/temporal_query/IS{index}_cypher.txt",cypher_lists)
        ldbc.write_to_file(f"{args.write_path}/temporal_query/IS{index}_TGQL_cypher.txt",tgql_cypher_lists)
    print("=========done!========")