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

## Code & benchmark
- all major codes are available in /src.
- all datasets and benchmark are available in /benchmark


## Documentation

TGDB is extended based on Memgraph. The internal information on Memgraph's architecture is available at
[internal](https://memgraph.notion.site/Memgraph-Internals-12b69132d67a417898972927d6870bd2) docs.
