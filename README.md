# AeonG
## Description
AeonG is a temporal graph database that efficiently supports
temporal features based on [Memgraph](https://memgraph.com). We provide a formally defined temporal property graph model,
based on which we fundamentally design AeonG with a temporal-enhanced storage engine and query
engine. AeonG utilizes a hybrid storage engine, in which we introduce a current store for maintaining
current graphs and a historical store for storing historical graphs migrated from the current storage under
MVCC management. Furthermore, AeonG equips a native temporal query engine to process temporal
queries with efficient capability and data consistent guarantee.

## Contributions

- Fast querying capabilities over subgraphs at a past time point or range
- Small storage overhead of historical data
- Native support of transaction time
- ACID compliance


## Getting Started

### Build System Dependencies
You can follow the detailed information provided by [Memgraph](https://memgraph.notion.site/Quick-Start-82a99a85e62a4e3d89f6a9fb6d35626d) to build system dependencies. We also provide a docker image to simplify this step. We recommend using docker to build AeonG.

    docker pull hououou/aeong:v1

    docker run -it -p 7687:7687 -p 7444:7444 --mount type=bind source=$pwd,target=/home/ --entrypoint bash aeong

### Install libraries
Before compiling AeonG, you should activate the toolchain, which is  used our own custom toolchain.

    source /opt/toolchain-vXYZ/activate

Apart from the system-wide installed dependencies, AeonG needs some libraries to be built locally. The proper setup of these libraries should be checked by running the init script.

    cd aeong
     ./init

### Compile
With all of the dependencies installed and the build environment set-up, you need to configure the build system. To do that, execute the following:

    mkdir -p build
    cd build
    cmake ..

If everything went OK, you can now, finally, run build AeonG binary and client binary.

    make -j$(nproc) memgraph
    cd tests/mgbench
    make 

### Run

After the compliation, you can run AeonG

    ./memgraph


## Benchmarks
We support three temporal benchmarks to evaluate the performances. More details can be found in [tests/benchmarks/README.md](/tests/benchmarks/README.md)

* We can automatically generate graph operation query statements for generating temporal data.

        cd tests/benchmarks/$workloadname
        python create_graph_op_quries.py --arg $arg_value

* We can generate temporal query statements for evaluating temporal performance.

        cd tests/benchmarks/$workloadname
        python create_temporal_query.py --arg $arg_value

## Tools
We provide tools to create temporal database and evaluate temporal database. Those tools can be found in [srcipt directory](/tests/scripts/).

### Create temporal database
It will report the average graph operation query latency and the storage consumptions of generated temproal database.

    cd tests/scripts/
    python3 create_temporal_database.py

You can specify optional arguments to generate the desirable temporal database.  You can also check specific arguments in each workload.

    python create_temporal_database.py --help

| Flag | Description | 
|----------|----------|
|--aeong-binary|AeonG binary|
|--client-binary|client binary|
|--num-workers|number of workers |
|--data-directory|directory path where temporal data should be stored|
|--original-dataset-cypher-path|directory path where temporal data should be stored|
|--index-cypher-path|index query path|
|--graph-operation-cypher-path|directory path where temporal data should be stored|
|--no-properties-on-edges|disable properties on edges|

### Evaluate temporal query performance
It will report the average temproal query latency.

    cd tests/scripts/
    python3 evaluate_temporal_q.py

The arguments are almost same to the above create_temporal_database.p, except "--temporal-query-cypher-path" indicating temporal query path. You can specify optional arguments to generate the desirable temporal database.  You can also check specific arguments in each workload.

    python evaluate_temporal_q.py --help

## Experiments

### Reproduce
To reproduce our paper's results, please follow the steps outlined below. First, download the mgBench, LDBC, and gMark datasets. More detailed information about these datasets is available in our [benchmark](/tests/benchamrks/) directory. Additionally, our system and baseline systems can be obtained through the following Docker image. The binary of baseline systems can be found in our Docker image at /home/clockg[memgraph-master/aeong]/build/memgraph.

      docker pull hououou/aeong:v2

#### AeonG vs Baseline Systems
We provide scripts based on our benchmark generation tools and test tools to compare our system with baseline systems, Clock-G, and T-GQL. These scripts are available in the [srcipt directory](/tests/scripts/), and you can customize them based on your needs.

* For Figure 8(a), 8(b), 9(a), 9(b), 9(c), and 9(d), where `$num_op` indicates the number of graph operations, `$clockg_binary` indicates the binary path of Clock-G, and `$memgraph_binary` indicates the binary path of T-GQL.

        cd tests/experiments
        ./t_mgBench_test.sh $num_op $clockg_binary $memgraph_binary

* For Figure 8(c) and 9(e), use the following script to test the LDBC workload. Note that the LDBC workload is substantial and will take a considerable amount of time.

      cd tests/experiments
      ./t_LDBC_test.sh $clockg_binary $memgraph_binary

* For Figure 8(d) and 9(f), use the following script.

      cd tests/experiments
      ./t_gMark_test.sh $clockg_binary $memgraph_binary

#### Performance Analysis on AeonG
To assess the performance of AeonG, please follow the steps outlined below.

* Figure 10. This experiment does not require creating a temporal database. Evaluate queries inherited from the original [mgBench](https://github.com/memgraph/memgraph/blob/master/tests/mgbench/workloads/pokec.py), [LDBC](https://github.com/ldbc/ldbc_snb_interactive_v1_impls/tree/main/cypher/queries), and [gMark](https://github.com/gbagan/gmark/tree/master/demo)  benchmarks. First, load the original datasets into each database. Then, test AeonG compared to Memgraph by specifying the database path `--data-directory`, executor binary path (either AeonG or Memgraph) `--aeong-binary`, and evaluated query path `--temporal-query-cypher-path`.

      cd tests/tools/
      python3 evaluate_temporal_q.py --data-directory $database_path --aeong-binary $binary_path(aeong/memgraph) --temporal-query-cypher-path $query_cypher_path_value 

* Figure 11(a). Use the following command by specifying the database path `--data-directory`, the query path `--temporal-query-cypher-path`, and GC cycle seconds `--storage-gc-cycle-sec`.

      cd tests/tools/
      python3 evaluate_temporal_q.py --data-directory $database_path --temporal-query-cypher-path $query_cypher_path_value --storage-gc-cycle-sec $gc_interval_value


* Figure 11(b). Evaluate the effect of the anchor number. First, create a temporal database by varying `--anchor_num`. Then, evaluate temporal query latency.

      cd tests/tools/
      python3 create_temporal_database.py --anchor_num $anchor_num_value --data-directory $data_directory
      python3 evaluate_temporal_q.py --data-directory $data_directory

* Figure 11(c). Evaluate the retention period. Create a temporal database by varying the `--retention-period-sec` and then evaluate temporal query performance.

      cd tests/tools/
      python3 create_temporal_database.py --retention-period-sec $retention_period --data-directory $data_directory
      python3 evaluate_temporal_q.py --data-directory $data_directory

* Figure 11(d). Install TiKV first, then checkout the Aeon-G branch and rebuild the project. Vary temporal data by setting `--graph-operation-cypher-path` and set different cluster nodes of TiKV.

      git checkout Aeon-G
      cd build
      cmake ..
      make -j$(nproc)
      cd tests/tools/
      python3 create_temporal_database.py --data-directory $data_directory --graph-operation-cypher-path $graph_op_path 
      python3 evaluate_temporal_query.py --data-directory $data_directory 


### Run AeonG manually
You can also test AeonG performance according to your needs. We guide you with following steps:

* Download dataset
* Generate graph operation query statements. You can use generation tools in our benchmarks directory (`/benchmarks/$workload_name/create_graph_op_queries.py`).
* Create temporal database. You can use the tool in our script directory (`/tests/scripts/create_temporal_database.py`). It will report the graph operation query latency and storage consumption.
* Generate temporal query statements.  You can use generation tools in our benchmarks directory (`/benchmarks/$workload_name/create_temporal_query.py`).
* Evaluate temporal performance. You can use the tool in our script directory (`/tests/scripts/evaluate_temporal_q.py`). It will report the temporal query latency.


## AeonG Implementation
AeonG is extended based on Memgraph. The details of our idea can be found in our [paper](https://hououou.github.io/AeonG/docs/aeong-extended-version-vldb24.pdf). We also refer Memgraph [internal docs](https://memgraph.notion.site/Memgraph-Internals-12b69132d67a417898972927d6870bd2) to better understand our codes. We made following major changes to support temporal features.

* storage engine:
  * timestamps: import timestamps into [Vertex](./src/storage/v2/vertex.hpp), [Edge](./src/storage/v2/edge.hpp), and [Delta](./src/storage/v2/delta.hpp) strutures.
  * data migaration: add data migration in the [Storage::CollectGarbage()](.src/storage/v2/storage.cpp) to migrate unreclaiemd data to RocksDB
  * retain historical data in RocksDB: [historical_delta.cpp](./src/storage/v2/history_delta.cpp) is used to transfer deltas to key-value formats and store them to RocksDB.
* query engine:
  * add temporal syntax in [Cypher.g4](./src/query/frontend/opencypher/grammar/Cypher.g4).
  * extend scan operator:   In the
    [ScanAllCursor.Pull()](./src/query/plan/operator.cpp) function, we introduce a function AddHistoricalVertices() to capture both unreclaimed and reclaimed historical versions
  * extend scan operator:   In the
    [ ExpandCursor.Pull()](./src/query/plan/operator.cpp) function, we introduce a function AddHistoricalEdges() to capture both unreclaimed and reclaimed historical versions



## Configuration settings
We inherit the configuration from Memgraph. Thus we support all configuration described in Memgraph. We refer the details in this [link](https://memgraph.com/docs/configuration/configuration-settings). Additionally, AeonG supports two more configurations to provide temporal features.

### General Settings

| Flag | Description | 
|----------|----------|
| --bolt-port       | Port on which the Bolt server should listen.       |
|--data-directory|Path to directory in which to save all permanent data.|
| --data-recovery-on-startup | Facilitates recovery of one or more individual databases and their contents during startup. Replaces --storage-recover-on-startup|
| --storage-gc-cycle-sec       | Storage garbage collector interval (in seconds).       | 
|--storage-recover-on-startup| Deprecated and replaced with the data_recovery_on_startup flag. Controls whether the storage recovers persisted data on startup. |
|--storage-properties-on-edges| Controls whether edges have properties. |
|--storage-snapshot-interval-sec| Storage snapshot creation interval (in seconds). Set to 0 to disable periodic snapshot creation. |
|--storage-snapshot-retention-count| The number of snapshots that should always be kept.| 

### AeonG specification

| Flag | Description | Default |
|----------|----------|----------|
| --retention-period-sec       | Reclaim history period (in seconds). Set to 0 to disable reclaiming history from historical storage.       | 0       |
| --retention-cycle-sec       | Reclaim history interval (in seconds).       | 60       |
| --anchor-num       | Every anchor number between two deltas. Set to 0 to use our multiple anchor strategies.     | 0       |