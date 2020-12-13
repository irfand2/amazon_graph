#include "dijalgorithm.h"
#include <limits>

std::vector<unsigned> dijkstra(Graph& g, Vertex& start) {
	unsigned size_ = g.size();
	unsigned start_index = g.getVertexMap().at(start);
	// initalize contaniers to keep track of visited vertexes and current distances
	std::vector<unsigned> distances(size_);
	std::vector<bool> visited(size_);
	// loop through all vertexes by their unique unsigned int
	for (auto a : g.getVertexMap()) {
		distances[a.second] = UINT_MAX; // set all current distances to pseudo-infinity
		visited[a.second] = false; // all vertexes are unvisited at first
	}
	distances[start_index] = 0; // distance to starting vertex is 0 by default
	for (unsigned i = 0; i < size_; i++) {
		// visit the unvisited vertex with least distance to starting vertex
		unsigned curr = findUnvisitedMin(distances, visited);
		visited[curr] = true;
		// loop through the neighbors of the current vertex
		if (distances[curr] != UINT_MAX) {
			for (unsigned j = 0; j < size_; j++) {
				if (g.getAdjMatrix()[curr][j]) {
					// update the neighbor's distance if new distance is less than previous distance
					distances[j] = std::min(distances[j], (distances[curr] + 1)); // +1 is because weights are all 1
				}
			}
		}
	}
	return distances;
}

unsigned findUnvisitedMin(std::vector<unsigned>& distances, std::vector<bool>& visited) {
	unsigned dist = UINT_MAX;
	unsigned index;
	// loop through distances to find the minimum unvisited
	for (unsigned i = 0; i < distances.size(); i++) {
		if (!visited[i] && distances[i] <= dist) {
			// update variables if a match is found
			dist = distances[i];
			index = i;
		}
	}
	return index;
}