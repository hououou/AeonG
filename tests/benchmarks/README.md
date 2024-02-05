# Temporal workloads

We provide three temporal workloads to evaluate temporal performances: [T-mgBench](./T-Pokec/), [T-LDBC](./T-LDBC/), and [T-gMark](./T-gMark/). We extend [mgBench](https://github.com/memgraph/memgraph/blob/master/tests/mgbench/README.md), [LDBC](https://github.com/ldbc/ldbc_snb_interactive_v1_impls), and [g-Mark](https://github.com/gbagan/gmark) workloads to introduce temporal features. We first generate historical data on the originl non-temporal dataset by processing create/delete/update graph operations. Then, we provide temporal query statements to access temporal data.

## Original datasets
Our original datasets for each workload are as follows.
* mgBench:
  * [small](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/pokec_small_import.cypher) (AeonG's choice): vertices 10,000, edges 121,716
  * [medium](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/pokec_small_import.cypher) : vertices 100,000, edges 1,768,515
  * [large](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/pokec/benchmark/pokec_large.setup.cypher.gz): vertices 1,632,803, edges 30,622,564.
* [LDBC](https://github.com/ldbc/ldbc_snb_interactive_v1_impls):
  * [sf0.1](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/ldbc/benchmark/interactive/ldbc_interactive_sf0.1.cypher.gz): vertices 327,588 edges 1,477,965
  * [sf1](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/ldbc/benchmark/interactive/ldbc_interactive_sf1.cypher.gz) (AeonG's choice): vertices 3,181,724, edges 17,256,038
  * [sf3](https://s3.eu-west-1.amazonaws.com/deps.memgraph.io/dataset/ldbc/benchmark/interactive/ldbc_interactive_sf3.cypher.gz): vertices 9,281,922, edges 52,695,735
* gMark: For g-Mark, we use its [open-source codes](https://github.com/gbagan/gmark) to generate graph. In our experiments, we relied on four use cases: the default gMark use case, and three gMark encodings of the schemas of existing state-of-the-art benchmarks. For each graph, we generate a raw dataset of 100K nodes and perform 320K update operations on each graph.
  * **Bib**: is gMarks' default scenario, describing the bibliographical database.
  * **LSN**: is gMark encoding of the fixed schema provided with the LDBC Social Network Benchmark, which simulates user activity in a social network.
  * **SP**: is gMark encoding of the fixed DBLP-based schema provided with SP2Bench.
  * **WD**: is gMark encoding of the default schema provided with Waterloo SPARQL Diversity Test Suite (WatDiv).


## Generate temporal data
Upon on original datasets, we provide generation tools for each workload to automaticlly generate graph operation query statements. The generation tool can be found in create_graph_op_queries.py in [each workload directory](./). Those operation query statements can be used to generate temporal/historical data.

    cd $workloadname
    python create_graph_op_quries.py --arg $arg_value

You need to specify optional arguments to generate corresponding graph operation query statements. The common arguments are listed below. You can also check specific arguments in each workload.

    python create_graph_op_quries.py --help

| Flag | Description | 
|----------|----------|
|--size|Dataset size|
|--num-op|The number of graph operation queries|
|--update-ratio|The update ratio of graph operation queries|
|--delete-ratio|The delete ratio of graph operation queries|
|--write-path|The write path of results|

## Generate temporal query statements

Each temporal workload includes various temporal query types. We extend non-temporal queries with temporal dimension (TT AS OF $t$ or TT FROM $t_1$ and $t_2$ ).

* T-mgBench includes four temporal queries.

  | Query | Statements | 
  |----------|----------|
  |Q1| Match (n: User {id: $id}) TT AS OF $t$ RETURN n|
  |Q2|Match (n: User {id: $id}) TT From $t_1$ to $t_2$ RETURN n |
  |Q3|Match (n: User {id: $id})-[e]->(m)  TT AS OF $t$ RETURN n,e,m|
  |Q4|Match (n: User {id: $id})-[e]->(m) TT From $t_1$ to $t_2$ RETURN n,e,m|

* T-LDBC includes seven [interactive short (IS) temporal queries](https://github.com/ldbc/ldbc_snb_interactive_v1_impls/tree/main/cypher/queries). We incorporate “TT AS OF $t$” into the LDBC IS
  queries (IS1-IS7).
* T-gMark uses [gMark’s query generation tool](https://github.com/gbagan/gmark/tree/master) to create non-temporal queries,
  and then transform them into temporal queries by adding the time
  condition “FOR TT AS OF 𝑡”. T

The generation tool can be found in create_temporal_quries.py in [each workload directory](./). Those temporal query statements can be used to test temporal database performance. We can generate temporal query statements using following commonds.


    cd $workloadname
    python create_temporal_quries.py --arg $arg_value

You need to specify optional arguments to generate corresponding temporal query statements. The common arguments are listed below. You can also check specific arguments in each workload.

    python create_temporal_quries.py --help

| Flag | Description | 
|----------|----------|
|--size|Dataset size|
|--num-op|The number of graph operation queries|
|--min-time|Min time of temporal databas's life|
|--max-time|Max time of temporal databas's life|
|--write-path|The write path of results|
|--interval|Interval of time-slice queries|
|--frequency-type|Frequency type of temporal queries|
