/**
 * Graph implementation with adjacency list
 */

#ifndef ADJ_GRAPH
#define ADJ_GRAPH

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <list>
#include <unistd.h>
#include <stdlib.h>
#include <string>
#include <sstream>

namespace adj_graph {

using std::vector;
using std::list;
using std::string;
using std::unordered_map;
using std::make_pair;
using std::stringstream;
using std::cout;
using std::endl;

class Edge {
 public:
   uint from;
   uint to;
   uint weight;
   string name;

   Edge(const uint from, const uint to, const uint weight, const string name);
};

class DegreeVertex {
 public:
   uint degree;  // in-degree of the vertex
   list<string> to_edges; // stores the name of the edge connecting vertices

   DegreeVertex();
};

class AdjGraph {
 public:
   vector<DegreeVertex> vertices;
   unordered_map<string, Edge> edges;

   AdjGraph(const uint num_vertices = 0);

   // add one edge, return true if edge is valid
   void add_edge(const uint from, const uint to, const uint weight, const string name);

   // class object serialization to string, for easy visualization and debugging
   operator string() const;
};

} // endnamespace adj_graph

#endif
