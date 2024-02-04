from pathlib import Path
import csv
import argparse

# node
class create_Dataset():
    def __init__(self, ldbc_csv_path, TGQL_cypher_file_path):
        self.t_gql_directory = TGQL_cypher_file_path
        self.organisation = f"{ldbc_csv_path}/static/organisation_0_0.csv"
        self.place = f"{ldbc_csv_path}/static/place_0_0.csv"
        self.tag = f"{ldbc_csv_path}/static/tag_0_0.csv"
        self.tagclass = f"{ldbc_csv_path}/static/tagclass_0_0.csv"
        self.comment = f"{ldbc_csv_path}/dynamic/comment_0_0.csv"
        self.forum = f"{ldbc_csv_path}/dynamic/forum_0_0.csv"
        self.person = f"{ldbc_csv_path}/dynamic/person_0_0.csv"
        self.post = f"{ldbc_csv_path}/dynamic/post_0_0.csv"

        # relationship
        self.organisation_islocatedin_place = f"{ldbc_csv_path}/static/organisation_isLocatedIn_place_0_0.csv"
        self.place_isPartOf_place = f"{ldbc_csv_path}/static/place_isPartOf_place_0_0.csv"
        self.tag_hasType_tagclass = f"{ldbc_csv_path}/static/tag_hasType_tagclass_0_0.csv"
        self.tagclass_isSubclassOf_tagclass = f"{ldbc_csv_path}/static/tagclass_isSubclassOf_tagclass_0_0.csv"
        self.comment_hasCreator_person = f"{ldbc_csv_path}/dynamic/comment_hasCreator_person_0_0.csv"
        self.comment_hasTag_tag = f"{ldbc_csv_path}/dynamic/comment_hasTag_tag_0_0.csv"
        self.comment_isLocatedIn_place = f"{ldbc_csv_path}/dynamic/comment_isLocatedIn_place_0_0.csv"
        self.comment_replyOf_comment = f"{ldbc_csv_path}/dynamic/comment_replyOf_comment_0_0.csv"
        self.comment_replyOf_post = f"{ldbc_csv_path}/dynamic/comment_replyOf_post_0_0.csv"
        self.forum_containerOf_post = f"{ldbc_csv_path}/dynamic/forum_containerOf_post_0_0.csv"
        self.forum_hasMember_person = f"{ldbc_csv_path}/dynamic/forum_hasMember_person_0_0.csv"
        self.forum_hasModerator_person = f"{ldbc_csv_path}/dynamic/forum_hasModerator_person_0_0.csv"
        self.forum_hasTag_tag = f"{ldbc_csv_path}/dynamic/forum_hasTag_tag_0_0.csv"
        self.person_email_emailaddress = f"{ldbc_csv_path}/dynamic/person_email_emailaddress_0_0.csv"
        self.person_hasInterest_tag = f"{ldbc_csv_path}/dynamic/person_hasInterest_tag_0_0.csv"
        self.person_isLocatedIn_place = f"{ldbc_csv_path}/dynamic/person_isLocatedIn_place_0_0.csv"
        self.person_knows_person = f"{ldbc_csv_path}/dynamic/person_knows_person_0_0.csv"
        self.person_likes_comment = f"{ldbc_csv_path}/dynamic/person_likes_comment_0_0.csv"
        self.person_likes_post = f"{ldbc_csv_path}/dynamic/person_likes_post_0_0.csv"
        self.person_speaks_language = f"{ldbc_csv_path}/dynamic/person_speaks_language_0_0.csv"
        self.person_studyAt_organisation = f"{ldbc_csv_path}/dynamic/person_studyAt_organisation_0_0.csv"
        self.person_workAt_organisation = f"{ldbc_csv_path}/dynamic/person_workAt_organisation_0_0.csv"
        self.post_hasCreator_person = f"{ldbc_csv_path}/dynamic/post_hasCreator_person_0_0.csv"
        self.post_hasTag_tag = f"{ldbc_csv_path}/dynamic/post_hasTag_tag_0_0.csv"
        self.post_isLocatedIn_place = f"{ldbc_csv_path}/dynamic/post_isLocatedIn_place_0_0.csv"

    def write_to_file(self,file_path, write_lists):
        f1 = open(file_path, "w", encoding='utf-8')
        for key in write_lists:
            f1.write(str(key) + "\n")
        f1.close()


    def create_node(self,node_type, path):
        write_lists = []
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            head = []
            i = 0
            for row in reader:
                if (i == 0):
                    head = row
                    i += 1
                    continue
                i += 1
                node_id = node_type + str(row[0])
                node_info = f"Create (n:Object {{ title:'{node_type}',id:'{node_id}',validTimeStart:timestamp(),validTimeEnd:9223372036854775000 }})"  # .format(node_types=node_type,node_id=id)
                att_infos = " "
                for j in range(0, len(row)):
                    attribute_name = head[j]
                    attribute_value = row[j]
                    if attribute_value == "":
                        # print(i,attribute_name,attribute_value)
                        continue
                    attribute_index = "a" + str(j)
                    attribute_info = f" Create (n)-[:OBJECT_ATTRIBUTE]->({attribute_index}:Attribute {{title:\"{attribute_name}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                    value_info = f" Create ({attribute_index})-[:ATTRIBUTE_VALUE]->(:Value {{title:\"{attribute_value}\",validTimeStart:timestamp(),validTimeEnd:9223372036854775000}}) "
                    att_infos = att_infos + attribute_info + value_info
                query_statement = node_info + att_infos
                write_lists.append(query_statement + ";")
        self.write_to_file(self.t_gql_directory + node_type + ".txt", write_lists)


    def create_edge(self,path, edge_type):  # node_type_from,node_type_to,
        write_lists = []
        with open(path) as f1:
            reader = csv.reader(f1, delimiter='|')
            head = []
            node_type_from = ""
            node_type_to = ""
            i = 0
            for row in reader:
                # if(i>=1000):
                #     break
                if (i == 0):
                    head = row
                    node_type_from = head[0][:-3]
                    node_type_to = head[1][:-3]
                    i += 1
                    continue
                i += 1
                node_id = node_type_from + str(row[0])
                node_from = node_type_from + str(row[0])
                node_to = node_type_to + str(row[1])
                query_state = f" Match (n:Object{{ id:'{node_from}'}}), (m:Object{{ id:'{node_to}'}}) "
                query_state1 = f" Create (n)-[e:{edge_type}]->(m) set e.validTimeStart=timestamp(), e.validTimeEnd=9223372036854775000"
                query_statement = query_state + query_state1
                write_lists.append(query_statement + ";")
            self.write_to_file(self.t_gql_directory + "edges/" + node_type_from + "_" + edge_type + "_" + node_type_to + ".txt",
                          write_lists)


    def create_nodes(self):
        self.create_node("Person", self.person)
        self.create_node("Organisation", self.organisation)
        self.create_node("Place", self.place)
        self.create_node("Tag", self.tag)
        self.create_node("TagClass", self.tagclass)
        self.create_node("Comment", self.comment)
        self.create_node("Forum", self.forum)
        self.create_node("Person", self.person)
        self.create_node("Post", self.post)


    def create_edges(self):
        self.create_edge(self.organisation_islocatedin_place, "isLocatedIn")
        self.create_edge(self.place_isPartOf_place, "isPartOf")
        self.create_edge(self.tag_hasType_tagclass, "hasType")
        self.create_edge(self.tagclass_isSubclassOf_tagclass, "isSubclassOf")
        self.create_edge(self.comment_hasCreator_person, "hasCreator")
        self.create_edge(self.comment_hasTag_tag, "hasTag")
        self.create_edge(self.comment_isLocatedIn_place, "isLocatedIn")
        self.create_edge(self.comment_replyOf_comment, "replyOf")
        self.create_edge(self.comment_replyOf_post, "replyOf")
        self.create_edge(self.forum_containerOf_post, "containerOf")
        self.create_edge(self.forum_hasMember_person, "hasMember")
        self.create_edge(self.forum_hasModerator_person, "hasModerator")
        self.create_edge(self.forum_hasTag_tag, "hasTag")
        self.create_edge(self.person_email_emailaddress, "email")
        self.create_edge(self.person_hasInterest_tag, "hasInterest")
        self.create_edge(self.person_isLocatedIn_place, "isLocatedIn")
        self.create_edge(self.person_knows_person, "knows")
        self.create_edge(self.person_likes_comment, "likes")
        self.create_edge(self.person_likes_post, "likes")
        self.create_edge(self.person_speaks_language, "speaks")
        self.create_edge(self.person_studyAt_organisation, "studyAt")
        self.create_edge(self.person_workAt_organisation, "workAt")
        self.create_edge(self.post_hasCreator_person, "hasCreator")
        self.create_edge(self.post_hasTag_tag, "hasTag")
        self.create_edge(self.post_isLocatedIn_place, "isLocatedIn")

    def get_index(self,write_path):
        query1 = "CREATE INDEX ON :Object (title);\n"
        query2 = "CREATE INDEX ON :Attribute(title);\n"
        query3 = "CREATE INDEX ON :Value(title);\n"
        index_path = write_path + "/../ldbc_tgql_index.cypher"
        f = open(index_path, "w", encoding='utf-8')
        f.write(query1)
        f.write(query2)
        f.write(query3)
        f.close()
        tgql_cypher=f"""CREATE INDEX ON :City(id);
            CREATE INDEX ON :Comment(id);
            CREATE INDEX ON :Country(id);
            CREATE INDEX ON :Forum(id);
            CREATE INDEX ON :Message(id);
            CREATE INDEX ON :Organisation(id);
            CREATE INDEX ON :Person(id);
            CREATE INDEX ON :Post(id);
            CREATE INDEX ON :Tag(id);
            CREATE INDEX ON :TagClass(id);
            CREATE INDEX ON :Place(id);
            CREATE INDEX ON :Country(name);
            CREATE INDEX ON :Message(creationDate);
            CREATE INDEX ON :Person(firstName);
            CREATE INDEX ON :Post(creationDate);
            CREATE INDEX ON :Tag(name);
            CREATE INDEX ON :TagClass(name);
            CREATE INDEX ON :Person;
            CREATE INDEX ON :City;
            CREATE INDEX ON :Continent;
            CREATE INDEX ON :Country;
            CREATE INDEX ON :Place;
            CREATE INDEX ON :Forum;
            CREATE INDEX ON :Comment;
            CREATE INDEX ON :Message;
            CREATE INDEX ON :Organisation;
            CREATE INDEX ON :University;
            CREATE INDEX ON :Company;
            CREATE INDEX ON :Person;
            CREATE INDEX ON :Post;
            CREATE INDEX ON :Tag;
            CREATE INDEX ON :TagClass;
            """
        index_path = write_path + "/../ldbc_index.cypher"
        f = open(index_path, "w", encoding='utf-8')
        f.write(tgql_cypher)
        f.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="AeonG create t-gql dataset for ldbc.",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter)
    parser.add_argument("--ldbc-csv-path",
                        default="../datasets/T-LDBC/original_csv",
                        help="Dataset Cypher query path")
    parser.add_argument("--TGQL-cypher-file-path",
                        default="../datasets/T-LDBC/tgql",
                        help="Dataset tqgl query path")
    # self.t_gql_directory = "/data/hjm/social_network-csv_basic-sf0.1/t-gql/"
    # ldbc_csv_path = "/data/hjm/social_network-csv_basic-sf0.1"
    args = parser.parse_args()
    ds = create_Dataset(args.ldbc_csv_path, args.TGQL_cypher_file_path)
    ds.create_edges()
    ds.create_nodes()
    ds.get_index(args.TGQL_cypher_file_path)

