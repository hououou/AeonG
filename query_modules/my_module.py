# Build Memgraph with Python 3.5+ support and run Memgraph so that it loads
# this file as a Query Module. The procedure implemented in this module is just
# a rewrite of the `example.c` procedure.
import mgp

import copy

#edges: mgp.List[mgp.Edge],
@mgp.update_vertices
def update_vertices(context: mgp.ProcCtx,
                     vertex: Vertex,
                     property_name: str,
                     property_value: mgp.Nullable[mgp.Any])-> mgp.Record(created_vertex=mgp.Vertex):
  # Create the new vertex and set its property
  new_vertex = context.graph.create_vertex()
  for label in vertex.label.items():
    new_vertex.add_label(label)
  for prop in vertex.properties:
    new_vertex.properties.set(prop.key,prop.value)
  new_vertex.properties.set(property_name, property_value)
  return mgp.Record(created_vertex=new_vertex)