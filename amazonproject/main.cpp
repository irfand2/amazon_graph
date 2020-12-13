#include <iostream>
#include <string>
#include "graph.h"
#include "dijalgorithm.h"
#include "pagerank.h"
#include "DFS.h"
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main(int argc, char** argv) {
  if (argc == 1) {
    return 0;
  }

  Graph g("tests/dataset_large_nodes.txt",
  "tests/dataset_large_edges.txt");
  bool default_file = true;

  // parsing cmd arguments
  // first and second arguments are file names, default is the Amazon Product Co-Purchasing Network.
  // third argument is chosen algortihm, fourth argument depends on the function.

  if (strncmp(argv[1],"d", 1) != 0) {
    g = Graph(argv[1], argv[2]);
    default_file = false;
  }
  
  if (strncmp(argv[3],"dfs", 3) == 0) {
    if (default_file) {
      cout << "Running DFS on Amazon Product Co-Purchasing Network" << endl;
    } else {
      cout << "Running DFS on " << argv[1] << endl;
    }
    
    cout << "See /tests/DFS_traversal.txt for results" << endl;
    DFS(g);
    return 0;
  }

  if (strncmp(argv[3],"dij", 3) == 0) {
	Vertex start = g.getVertexFromIndex(0);
    // fourth argument is index of chosen vertex, default is first vertex as stored in text file
    if (argc == 5) {
		start = g.getVertexFromIndex(std::stoi(argv[4]));
    } 

    if (default_file) {
      cout << "Running Dijkstra's algorithm on Amazon Product Co-Purchasing Network";
    } else {
      cout << "Running Dijkstra's algorithm on " << argv[1];
    }

    cout << " starting at " << start << endl;
    cout << "See console output for results" << endl;

    vector<unsigned> result = dijkstra(g, start);
    for (unsigned i = 0; i < result.size(); i++) {
      cout << "Vertex " << i << " = "<< result[i] << endl;
    }
    cout << endl;
    return 0;
  }

  if (strncmp(argv[3],"pr", 2) == 0) {
    unsigned iterations = 10;
    // fourth argument is number of iterations, default is 10
    if (argc == 5) {
      iterations = std::stoi(argv[4]);
    } 

    if (default_file) {
      cout << "Running pagerank algorithm on Amazon Product Co-Purchasing Network";
    } else {
      cout << "Running pagerank algorithm on " << argv[1];
    }

    cout << " with " << iterations << " iterations" << endl;
    cout << "See console output for results" << endl;
    vector<double> result = pagerank(g, iterations);
    for (unsigned i = 0; i < result.size(); i++) {
      cout << "Vertex " << i << " = " << result[i] << endl;
    }
    cout << endl;
    return 0;
  }
}