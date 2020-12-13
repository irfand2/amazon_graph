#pragma once
#include "graph.h"
#include "vertex.h"
#include <vector>

/**
* Runs a depth first traversal on a directed graph and stores the path
* as the sequence of nodes visited in text file /tests/DFS_traversal.txt.
* @param graph to run the traversal on.
**/
void DFS(Graph g);

/**
* Helper function for DFS(Graph g).
* Runs a depth first traversal on a graph starting from a particular vertex.
**/
void DFS(Vertex v, std::vector<bool>& visited, Graph& g);