import argparse
import re

class create_Dataset():
    def __init__(self, cypher_file_path, TGQL_cypher_file_path):
        self._dataset_file_path = cypher_file_path
        self._write_dataset_file_path = TGQL_cypher_file_path

    def replace_v(self, v_query):
        num_lists = re.findall(r"\d+\.?\d*", v_query)
        lens = len(num_lists)
        if len(num_lists) == 0:
            return ""
        vid = num_lists[0]
        percent = num_lists[1] if (lens >= 2) else 0
        age = num_lists[2] if (lens >= 3) else 0
        gender = "woman"
        if ("man" in v_query):
            gender = "man"
        query_state = " Create (n:Object{ title:'User',id:" + str(
            vid) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a1:Attribute {title:'id',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a2:Attribute {title:'completion_percentage',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a3:Attribute {title:'gender',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (n)-[:OBJECT_ATTRIBUTE]->(a4:Attribute {title:'age',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a1)-[:ATTRIBUTE_VALUE]->(:Value {title:" + str(
            vid) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a2)-[:ATTRIBUTE_VALUE]->(:Value {title:" + str(
            percent) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a3)-[:ATTRIBUTE_VALUE]->(:Value {title: '" + gender + "',validTimeStart:timestamp(),validTimeEnd:9223372036854775000}) " + \
                      " Create (a4)-[:ATTRIBUTE_VALUE]->(:Value {title:" + str(
            age) + ",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}); "
        return query_state

    def replace_e(self, e_query):
        num_lists = re.findall(r"\d+\.?\d*", e_query)
        if (len(num_lists) == 0):
            return ""
        from_v = num_lists[0]
        to_v = num_lists[1]
        query_state = " Match (n:Object{ id:" + str(from_v) + " }), (m:Object{ id:" + str(to_v) + "})" + \
                      " Create (n)-[e:Friend]->(m) set e.validTimeStart=timestamp(), e.validTimeEnd=9223372036854775000;"
        return query_state

    def _gen_dataset(self):
        f1 = open(self._write_dataset_file_path, "w", encoding='utf-8')
        with open(self._dataset_file_path, "r") as f:
            lines = f.readlines()
            query = ""
            for line in lines:
                if ("MATCH" not in line):  # create vertex
                    query = self.replace_v(line)
                else:
                    query = self.replace_e(line)
                if (query != ""):
                    f1.write(query + "\n")
        f1.close()

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


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="AeonG create t-gql dataset.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--cypher-file-path",
                        default="../datasets/T-mgBench/cypher.cypher",
                        help="Dataset Cypher query path")
    parser.add_argument("--TGQL-cypher-file-path",
                        default="../datasets/T-mgBench/TGQL.cypher",
                        help="Dataset Cypher query path")
    args = parser.parse_args()
    ds = create_Dataset(args.cypher_file_path, args.TGQL_cypher_file_path)
    ds._gen_dataset()
    ds._gen_index()
