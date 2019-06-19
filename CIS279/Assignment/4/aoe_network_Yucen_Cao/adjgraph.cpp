#include "adjgraph.hpp"


namespace adj_graph {

  Edge::Edge(const uint from, const uint to, const uint weight, const string name) 
  :from(from), to(to), weight(weight), name(name) {}

  AdjGraph::AdjGraph(const uint num_vertices) {
    vertices.resize(num_vertices);
    
  }

  DegreeVertex::DegreeVertex()
  :degree(0) {}

  void AdjGraph::add_edge(
      const uint from, const uint to, const uint weight, const string name) {

    // Edge arguments validation
    assert(from >= 0 && from < vertices.size());
    assert(to >= 0 && to < vertices.size());
    assert(weight >= 0);
    
    edges.insert(make_pair(name, Edge(from, to, weight, name)));

    vertices.at(from).to_edges.push_back(name);
    vertices.at(to).degree += 1;
  }

  AdjGraph::operator string() const {
    stringstream repr;
    repr << "AdjGraph(vertices=[";
    for (int i = 0; i != vertices.size(); i++) {
      repr << "node=" << i << "->";
      repr << "degree=" << vertices.at(i).degree;
      for (auto j = vertices.at(i).to_edges.begin(); 
          j != vertices.at(i).to_edges.end(); 
          j++) { 
        repr << *j;
      }
      repr << ",";
    }
    repr << "], edges=[";

    for (auto i = edges.begin(); i != edges.end(); i++) {
      auto edge = i -> second;
      repr << "(edge=" << edge.name;
      repr << ",from=" << edge.from << ",to=" << edge.to << ",weight=" << edge.weight;
    }
    return repr.str();
  }

} // endnamespace adj_graph
