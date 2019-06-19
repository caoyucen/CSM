/*
 * To compile, use g++ -std=c++11 flag
 */
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

#include <iostream>
#include <fstream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <iterator>
#include <queue>
#include <set>
#include <unordered_set>
#include <algorithm>
#include "adjgraph.hpp"
#include "string_utils.cpp"

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::istream;
using std::stringstream;
using std::ostream;
using std::ios;
using std::stack;
using std::set;
using std::queue;
using std::unordered_set;
using std::minmax_element;
using namespace adj_graph;
using uint = unsigned int;

template <class T>
ostream& operator<< (ostream& out, const list<T>& l) {
  for (auto i = l.begin(); i != l.end(); i++) {
    out << *i;
    if (std::next(i) != l.end()) {
      out << " ";
    }
  } 
  return out;
}


/////////////////////////////////////////// REAL STUFF 

/**
 * flip values
 */
void op_flip(int& value) {
  value = 0 - value;
}


/** 
 * perform topological sorting and update earliest event time vector
 * returns false if network has cycles
 */
bool aoe_sort(AdjGraph& graph, vector<int>& ee) {
  stack<uint> source_vertices_idx; // vertices with 0 in-degree 
  // record unvisited vertices, so that we can detect cycles
  unordered_set<int> unvisited;
  for (uint i = 0; i < graph.vertices.size(); i++) {
    unvisited.insert(i);
    if (graph.vertices.at(i).degree == 0) {
      source_vertices_idx.push(i);
    }
  } 
  
  // invalid graph
  if (source_vertices_idx.size() == 0) {
    return false;
  }
  while (!source_vertices_idx.empty()) {
    uint src_idx = source_vertices_idx.top();
    source_vertices_idx.pop();
    unvisited.erase(src_idx);
    int ee_src = ee.at(src_idx);
    // loop through edges to update in-degree and add new source vertices to stack
    auto adj_list = graph.vertices.at(src_idx).to_edges;
//    cout << "current vertex: " << src_idx << endl;
    for (auto e = adj_list.begin(); e!= adj_list.end(); e++) {
      Edge edge = graph.edges.at(*e);
//      cout << "processing edge: " << edge.from << " " << edge.to << endl;
      int current_max = ee.at(edge.to);
//      cout << "current_max=" << current_max << ",weight=" << edge.weight << ",ee_src=" << ee_src << endl;
      // update ee[j]
      ee.at(edge.to) = (current_max < int(edge.weight) + ee_src) 
        ? int(edge.weight) + ee_src : current_max;
//      cout << "ee(" << edge.to << ")=" << ee.at(edge.to) << endl;
      // update degree, add to stack if it becomes a new source vertex
      int indegree = --graph.vertices.at(edge.to).degree;
      if (indegree == 0) {
        source_vertices_idx.push(edge.to);
      }
    }
  }
  if (!unvisited.empty()) {
    return false;
  }
  return true;
}

/**
 * compute critical activities
 */
void compute_criticals(
    AdjGraph& graph, 
    const vector<int>& ee, 
    const vector<int>& le, 
    set<string>& criticals, 
    vector<bool>& is_critical_event) {
  for (auto i = graph.edges.begin(); i != graph.edges.end(); i++) {
    // compute e, l, slack
    string name = i -> first;
    int from = (i -> second).from;
    int to = (i -> second).to;
    int weight = (i -> second).weight;
    int e = ee.at(from);
    int l = le.at(to) - int(weight);
    if (l == e) {
      criticals.insert(name);
      is_critical_event.at(from) = true;
      is_critical_event.at(to) = true;
    }
  }
}

/**
 * dfs to find path between two points
 */

/**
 * get critical paths, using edge DFS to find euler paths, criticals is mutable
 */
void find_critical_paths(AdjGraph& graph, unordered_set<int>& visited, int start, int end, list<list<string> >& results, list<string>& current_path) {
  list<string>& to_edges = graph.vertices.at(start).to_edges;
  if (visited.empty()) {
    return;
  }
  for (auto i = to_edges.begin(); i != to_edges.end(); i++) {
    auto edge_it = graph.edges.find(*i);
    if (visited.find((edge_it -> second).to) != visited.end() && edge_it != graph.edges.end()) {
      current_path.push_back(*i); // push current edge name
      visited.erase((edge_it -> second).to);  // remove edge name from criticals
      if ((edge_it -> second).to == end) {
        results.push_back(current_path);  // add current path to final results
        
      }
      find_critical_paths(graph, visited, (edge_it -> second).to, end, results, current_path);
      current_path.pop_back();
      visited.insert((edge_it -> second).to);
    } 
  }
}


void output_results(
    ostream& out, 
    const vector<int>& ee, 
    const vector<int>& le, 
    const vector<bool>& is_critical_event, 
    const set<string>& criticals, 
    const list<list<string> >& critical_paths,
    const int& longest_path_length) {

  out << "The earliest time that each event may occur is listed below:" << endl;
  for (int i = 0; i < ee.size(); i++) {
    out << "Event " << i << " : " << ee.at(i) << " unit time" << endl;
  }
  out << "The latest time that each event may occur is listed below:" << endl;
  for (int i = 0; i < le.size(); i++) {
    out << "Event " << i << " : " << le.at(i) << " unit time" << endl;
  }
  out << "Following are the critical events:" << endl;
  for (int i = 0; i < ee.size(); i++) {
    if (is_critical_event.at(i)) {
      out << "Event " << i << endl;
    }
  }
  out << "The following is the list of critical activities for each critical path:" << endl;
  for (auto i = critical_paths.begin(); i!= critical_paths.end(); i++) {
    out << *i << endl;
  }
  
  out << "The longest path in this activity network has a duration of:" << endl;
  out << longest_path_length << " unit time" << endl;
  out << "---------------------------------------------------------" << endl;
}

/**
 * perform topo-sort and compute ee, le, e, l on forward/backward graph
 */
void run_aoe_network(AdjGraph& fgraph, AdjGraph& bgraph, ostream& out) {
//  out << string(fgraph) << endl;
//  out << string(bgraph) << endl;

  vector<int> ee(fgraph.vertices.size(), 0);
  if (!aoe_sort(fgraph, ee)) {
    out << string_utils::HAS_CYCLE_MESSAGE << endl;
    return;
  }
  // initialize le using le(i) = 0 - ee(i)
  int longest_path_length = *std::max_element(ee.begin(), ee.end());
  vector<int> le(ee.size(), 0 - longest_path_length);
  // compute le
  aoe_sort(bgraph, le);
  std::for_each(le.begin(), le.end(), op_flip);

  // use le/ee to computee/l
  set<string> criticals;
  vector<bool> is_critical_event(ee.size(), false);
  compute_criticals(fgraph, ee, le, criticals, is_critical_event);

  // critical paths
  auto start_end = std::minmax_element(ee.begin(), ee.end());
  auto start = start_end.first - ee.begin();
  auto end = start_end.second - ee.begin(); 
  list<list<string> > paths;
  list<string> current_path;
  unordered_set<int> unvisited_criticals;  // create a copy of criticals
  for (int i = 0; i != is_critical_event.size(); i++) {
    if (is_critical_event.at(i)) {
      unvisited_criticals.insert(i);
    }
  }
  find_critical_paths(fgraph, unvisited_criticals, start, end, paths, current_path);
  
  output_results(out, ee, le, is_critical_event, criticals, paths, longest_path_length);
}

/**
 * run test cases and show results
 * @param filename, the input testcase file
 */
void run_tests(istream& in, ostream& out) {
    cout << "Successfully opened file" << endl;
    uint test_count = 0;
    while (in.good()) {
      if (&in == &cin) {
        cout << "Please input test case:" << endl;
      } else if (in.peek() == EOF) {
        cout << "All test cases processed, exiting now" << endl;
        return;
      }
    // process input line and build graph
      cout << "Processing test case #" << test_count << endl;
      uint num_vertices = 0; 
      uint num_edges = 0;
      in >> num_vertices;
      in >> num_edges;
      // initialize 2 graphs
      in.ignore(); //skip newline
      AdjGraph forward_graph(num_vertices);
      AdjGraph backward_graph(num_vertices);
      vector<string> edge_args;
      for (int i = 0; i < num_edges; i++) {
        string current_line;
        getline(in, current_line);
        string_utils::split_string(current_line, ',', edge_args);
        // adding edges
        forward_graph.add_edge(
            std::stoi(edge_args.at(0)), 
            std::stoi(edge_args.at(1)), 
            std::stoi(edge_args.at(2)), 
            edge_args.at(3)); 
        // add reverse edges
        backward_graph.add_edge(
            std::stoi(edge_args.at(1)), 
            std::stoi(edge_args.at(0)), 
            std::stoi(edge_args.at(2)), 
            edge_args.at(3)); 
        edge_args.clear();
      }
      // run aoe network and output results to specified stream 
      run_aoe_network(forward_graph, backward_graph, out);
      test_count++;
    }
}


int main(int argc, char* argv[]) {
  int flags = 0;
  int opt = 0;
  if (argc == 1) {
    // no args: read from screen input and output to stdout
    run_tests(cin, cout);
  } else {
    string input_file = argv[1];
    ifstream fin;
    fin.open(input_file, ios::in);
    if (!fin.is_open()) {
      cerr << "Error opening input file: " << input_file << endl;
      exit(EXIT_FAILURE);
    }
    if (argc == 3) {
      // 2 args: read from file and output to file
      string output_file = argv[2];
      ofstream fout;
      fout.open(output_file, ios::out);
      if (!fout.is_open()) {
        cerr << "Error opening output file: " << output_file << endl;
        exit(EXIT_FAILURE);
      }
      run_tests(fin, fout);
      fout.close();
    } else if (argc == 2) {
      // 1 args: read from file and output to stdout
      run_tests(fin, cout);
    } else {
      cerr << "Invalid number of arguments!" << endl;
      cerr << "usage: " << endl;
      cerr << argv[0] << ": read from stdin, write to stdout" << endl;
      cerr << argv[0] << " [input_file]: read from file, write to stdout" << endl; 
      cerr << argv[0] << 
        " [input_file] [output_file]: read from file, write to file" << endl;
      fin.close();
      exit(EXIT_FAILURE);
    }
    fin.close();
  }

  if (optind >= argc) {
    cerr << "Expected argument after options" << endl;
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
