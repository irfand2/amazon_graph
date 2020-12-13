#pragma once

#include <list>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

#include "vertex.h"

/**
* Represents a directed unweighted graph.
**/

class Graph {

  public:
  
  /**
  * Builds a graph given a list of nodes and edges
  * @param nodes_file a text file that contains the list of nodes
  * identified by its tag and formatted as one node per line.
  * @param connections_file a text file that contains the list of edges 
  * identified by the tag of the source and destination vertex and 
  * formatted as "sourcevertex  destinationvertex" with one edge per line.
  **/
  Graph(std::string nodes_file, std::string connections_file);

  // Getters
  std::vector<std::vector<bool>> & getAdjMatrix() {
    return adjMatrix;
  }

  std::unordered_map<Vertex, unsigned> & getVertexMap() {
    return vertexMap;
  }
  /**
  * returns the vertex that is uniquely identified by a given index.
  * @param index a non negative integer < number of nodes. 
  **/
  Vertex getVertexFromIndex(unsigned index);

  // Graph properties

  /**
  * counts the number of edges that have a particular vertex as the source vertex.
  * @param v source vertex.
  **/
  int out_degree(const Vertex & v) const;

  /**
  * counts the number of edges that have a particular vertex as the destination vertex.
  * @param v destination vertex.
  **/
  int in_degree(const Vertex & v) const;

  /**
  * returns the number of nodes in the graph.
  **/
  unsigned size() const;

  /**
  * return true if if there is path from v1 to v2, not other way around.
  * @param v1 source vertex.
  * @param v2 destination vertex
  **/
  bool is_outAdjacent(const Vertex & v1, const Vertex & v2) const;

  private:
  std::vector<std::vector<bool>> adjMatrix;
  std::unordered_map<Vertex, unsigned> vertexMap;
  std::vector<Vertex> vertexList;
};


