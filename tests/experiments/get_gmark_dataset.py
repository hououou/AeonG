import os
import argparse
import  csv
import pandas as pd

class create_Dataset():
    def label_id_process(self, str_id):
        str_id=str_id.split("_")[1]
        return str_id

    def process_rdf_file(self, file_path):
        data = []  # 用于存储处理后的数据
        nodes_set = set()
        nodes = []
        max_num = 0
        with open(file_path, 'r') as file:
            for line in file:
                line = line.strip()
                if line:
                    elements = line.split()
                    nodes_set.add(elements[0])
                    nodes_set.add(elements[2])
                    mmax_num = max(int(elements[0].split("_")[1]), int(elements[2].split("_")[1]))
                    max_num = max(max_num, mmax_num)
                    data.append(elements)
        for node_id in range(max_num + 1):
            node = [node_id, 'Node']
            nodes.append(node)
        df = pd.DataFrame(data, columns=[':START_ID(NODE_ID)', ':TYPE', ':END_ID(NODE_ID)'])
        columns = df.columns.tolist()
        columns[1], columns[2] = columns[2], columns[1]
        df = df[columns]
        df[':START_ID(NODE_ID)'] = df[':START_ID(NODE_ID)'].apply(self.label_id_process)
        df[':END_ID(NODE_ID)'] = df[':END_ID(NODE_ID)'].apply(self.label_id_process)
        df_node = pd.DataFrame(nodes, columns=['id:ID(NODE_ID)', ':LABEL'])
        df_node['id:ID(NODE_ID)'] = df_node['id:ID(NODE_ID)'].astype(int)
        sorted_df = df_node.sort_values('id:ID(NODE_ID)')
        return df, sorted_df
    
    def read_files_in_dir(self, directory):
        processed_dir = os.path.join(directory, "processed")
        if not os.path.exists(processed_dir):
            os.makedirs(processed_dir)
        for filename in os.listdir(directory):
            file_path = os.path.join(directory, filename)
            processed_file = os.path.join(processed_dir, filename)
            if os.path.isfile(file_path):
                with open(file_path, 'r') as file:
                    content = file.read()
                    processed_content = content.replace(':p', ':')
                    processed_content = processed_content.replace('|p', '|')
                    processed_content = processed_content.replace('UNION', '')
                    with open(processed_file, 'w') as new_file:
                        new_file.write(processed_content)
                        new_file.flush()
                        new_file.close()
                    file.close()

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
        self.write_to_file(write_path+"/tgql_node.txt",write_lists)

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
            self.write_to_file(write_path+"/tgql_edge.txt",write_lists)

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
                        default="../datasets/T-gMark/cypher.cypher",
                        help="Dataset Cypher query path")
    parser.add_argument("--TGQL-cypher-file-path",
                        default="../datasets/T-gMark/TGQL.cypher",
                        help="Dataset Cypher query path")
    parser.add_argument('-d', '--directory', type=str, help='path for the processed gmark directory')
    parser.add_argument('-t', '--dbtype', type=str, help='gmark schema')
    parser.add_argument('-n', '--number', type=int, default=100, help='nodes nums(k)')
    
    args = parser.parse_args()
    sf = str(args.number) # scale factor for the schema
    ds = create_Dataset()
    raw_path=args.directory + f"/{args.dbtype}-a-graph.txt"
    node_path=args.directory + f"/{args.dbtype}-a-nodes.csv"
    edge_path=args.directory + f"/{args.dbtype}-a-graph.csv"
    query_path=args.directory +"/query"
    edge_tgql_path=args.directory + "/tgql"
    node_tgql_path=args.directory + "/tgql"
    # generate the original gmark dataset for property graph
    df, nodes= ds.process_rdf_file(args.directory + f"/{args.dbtype}-a-graph.txt")
    df.to_csv(args.directory + f"/{args.dbtype}-a-graph.csv", index=False, sep='|')
    nodes.to_csv(args.directory + f"/{args.dbtype}-a-nodes.csv", index=False, sep='|')
    # generate the tgql-v gmark dataset
    ds.create_node(node_path,node_tgql_path)
    ds.create_edge(edge_path,edge_tgql_path)

    # generate the original gMark workload
    ds.read_files_in_dir(query_path)

