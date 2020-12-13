#include "../cs225/catch/catch.hpp"
#include "../graph.h"
#include "../pagerank.h"

TEST_CASE("pr test", "[part=4]") {
	Graph g("tests/dataset_small_nodes.txt",
		"tests/dataset_small_edges.txt");
	std::vector<double> result = pagerank(g, 10);
	// bing (last vertex) gets a link from discord (vertex with most link)
	// hence it must have the highest value
	for (unsigned i = 0; i < result.size() - 1; i++) {
		REQUIRE(result[i] < result[result.size() - 1]);
	}
	// both FB and Twitter get 0 links from others, hence they must have the same value
	// and that value must be the lower than all others
	REQUIRE(result[1] == result[4]);
	for (unsigned i = 0; i < result.size(); i++) {
		if (i != 1 && i != 4) {
			REQUIRE(result[1] < result[i]);
		}
	}
	// discord and reddit have the same number of incoming links but discord gets links from more linked vertexes
	// hence discord must have higher value
	REQUIRE(result[3] > result[2]);
	// since this is a probability distribution the sum of all values must be exactly 1.0
	REQUIRE(norm(result) == 1.0);
}
// add tests here
