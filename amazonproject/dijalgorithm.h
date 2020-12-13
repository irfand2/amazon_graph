#pragma once
#include "graph.h"

// returns the shortest distance between start vertex and every other vertex
// the graph implementation is unweighted, hence weights are taken as 1
// this implementation uses a vector instead of a priority queue, hence time complexity is O(n*n)
std::vector<unsigned> dijkstra(Graph& g, Vertex& start);

// returns the index that is not visitied and has the minimum distance value
unsigned findUnvisitedMin(std::vector<unsigned>& distances, std::vector<bool>& visited);