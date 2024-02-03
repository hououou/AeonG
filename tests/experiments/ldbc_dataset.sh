
function print_help () {
    echo "Usage: $0 [OPTION]"
    echo "Optional arguments:"
    echo -e "  -h|--help -> Prints help."
    echo -e "  --scale-factor Positive_Integer -> Defines the dataset size."
}

script_dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
base_dir="${script_dir}/../../.."
build_dir="${base_dir}/build"
cd build_dir/tools/src
make

 wget --no-check-certificate https://repository.surfsara.nl/datasets/cwi/snb/files/social_network-csv_basic/social_network-csv_basic-sf0.1.tar.zst
 zstd -d social_network-csv_basic-sf0.1.tar.zst
 tar -xf social_network-csv_basic-sf0.1.tar

dataset_dir="${script_dir}/datasets/scale_${scale_factor}"
csv_dataset="
--nodes ${dataset_dir}/dynamic/comment_0_0.csv \
--nodes ${dataset_dir}/dynamic/forum_0_0.csv \
--nodes ${dataset_dir}/static/organisation_0_0.csv \
--nodes ${dataset_dir}/dynamic/person_0_0.csv \
--nodes ${dataset_dir}/static/place_0_0.csv \
--nodes ${dataset_dir}/dynamic/post_0_0.csv \
--nodes ${dataset_dir}/static/tag_0_0.csv \
--nodes ${dataset_dir}/static/tagclass_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_hasCreator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_replyOf_comment_0_0.csv \
--relationships ${dataset_dir}/dynamic/comment_replyOf_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_containerOf_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasMember_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasModerator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/forum_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/static/organisation_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_hasInterest_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_knows_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_likes_comment_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_likes_post_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_studyAt_organisation_0_0.csv \
--relationships ${dataset_dir}/dynamic/person_workAt_organisation_0_0.csv \
--relationships ${dataset_dir}/static/place_isPartOf_place_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_hasCreator_person_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_hasTag_tag_0_0.csv \
--relationships ${dataset_dir}/dynamic/post_isLocatedIn_place_0_0.csv \
--relationships ${dataset_dir}/static/tag_hasType_tagclass_0_0.csv \
--relationships ${dataset_dir}/static/tagclass_isSubclassOf_tagclass_0_0.csv"

memgraph_snapshot_dir=${dataset_dir}/memgraph/snapshots
mkdir -p ${memgraph_snapshot_dir}
cd ${memgraph_snapshot_dir}
echo "Converting CSV dataset to '${memgraph_snapshot_dir}/snapshot'"
${build_dir}/tools/src/mg_import_csv --out snapshot ${csv_dataset} --csv-delimiter "|" --array-delimiter ";"
