import argparse
import  csv
class create_Dataset():
    def write_to_file(self,file_path,write_lists):
        f1 = open(file_path, "w",encoding='utf-8')
        for key in write_lists:
            f1.write(str(key)+"\n")
        f1.close()

    def create_node(self,path,write_path):
        write_lists=[]
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            head=[]
            i=0
            for row in reader:
                if(i==0):
                    head=row
                    i+=1
                    continue
                i+=1
                node_id=row[0]
                node_info=f"Create (n:Object {{ title:'Node',id:{node_id},validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"#.format(node_types=node_type,node_id=id)
                id_info=f" Create (n)-[:OBJECT_ATTRIBUTE]->(att:Attribute {{title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                id_value_info=f" Create (att)-[:ATTRIBUTE_VALUE]->(:Value {{title:{node_id},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                name_info=f" Create (n)-[:OBJECT_ATTRIBUTE]->(att2:Attribute {{title:'name',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                name_value_info=f" Create (att2)-[:ATTRIBUTE_VALUE]->(:Value {{title:{node_id},validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                query_statement=node_info+id_info+id_value_info+name_info+name_value_info
                write_lists.append(query_statement+";")
        self.write_to_file(write_path+"tgql_node.txt",write_lists)

    def create_edge(self,path,write_path):#node_type_from,node_type_to,
        write_lists=[]
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            i=0
            for row in reader:
                if(i==0):
                    head=row
                    i+=1
                    continue
                i+=1
                # print(head,node_type_from,node_type_to)
                node_from=row[0]
                node_to=row[1]
                edge_type=row[2]
                query_state=f" Match (n:Object{{ id:{node_from}}}), (m:Object{{ id:{node_to}}}) "
                query_state1=f" Create (n)-[e:{edge_type}]->(m) set e.validTimeStart=timestamp(), e.validTimeEnd=9223372036854775000"
                query_statement=query_state+query_state1
                write_lists.append(query_statement+";")
            self.write_to_file(write_path+"tgql_edge.txt",write_lists)

    def _gen_index(self):
        query1 = "CREATE INDEX ON :Object (title);\n"
        query2 = "CREATE INDEX ON :Attribute(title);\n"
        query3 = "CREATE INDEX ON :Value(title);\n"
        tgql_paths = self._write_dataset_file_path.split(".cypher")
        index_path = tgql_paths[0] + "_index.cypher"
        f = open(index_path, "w", encoding='utf-8')
        f.write(query1)
        f.write(query2)
        f.write(query3)
        f.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="AeonG create t-gql dataset for gmark.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--cypher-file-path",
                        default="../datasets/T-mgBench/cypher.cypher",
                        help="Dataset Cypher query path")
    parser.add_argument("--TGQL-cypher-file-path",
                        default="../datasets/T-mgBench/TGQL.cypher",
                        help="Dataset Cypher query path")
    args = parser.parse_args()
    ds = create_Dataset()
    node_path=f"/data/hjm/gMark/datasets/social/social-a-100k/social-a-node.csv"
    relation=f"/data/hjm/gMark/datasets/social/social-a-100k/social-a-graph.csv"
    edge_tgql_path=f"/data/hjm/gMark/datasets/social/social-a-100k/"
    node_tgql_path=f"/data/hjm/gMark/datasets/social/social-a-100k/"
    ds.create_node(node_path,node_tgql_path)
    ds.create_edge(relation,edge_tgql_path)

