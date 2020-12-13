#pragma once
#include "graph.h"

// pagerank returns a probability distrubution vector (all values are between 0 and 1)
// probability of vertex with index i is at index i in the returned vector
// vertexes with higher values are more "important"
std::vector<double> pagerank(Graph& g, unsigned iterations);

// returns the sum of all values in a vector, ie. l-1 norm
double norm(const std::vector<double>& vec);

// standard matrix-vector multiplication, where m = nxn and v = nx1
std::vector<double> matmul(const std::vector<std::vector<double>>& m, const std::vector<double>& v);