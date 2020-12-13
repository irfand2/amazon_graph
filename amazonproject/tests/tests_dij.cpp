#include "../cs225/catch/catch.hpp"
#include "../graph.h"
#include "../dijalgorithm.h"

using namespace std;


TEST_CASE("dij test small", "[part=3]") {
    Graph g("tests/dataset_small_nodes.txt",
     "tests/dataset_small_edges.txt");

    unordered_map<Vertex, unsigned> vertexMap = g.getVertexMap();
    auto it = vertexMap.begin();
    Vertex start = (*it).first;
    unsigned i = UINT_MAX;
    // Create the solution using the dijkstra alg;
    vector<unsigned> result = dijkstra(g, start);
    vector<unsigned> solution;

    // Manually enter all the distances with manual computation
    solution.push_back(1);
    solution.push_back(0);
    solution.push_back(2);
    solution.push_back(1);
    solution.push_back(i);
    solution.push_back(1);
    solution.push_back(i);
    solution.push_back(2);
    REQUIRE(result == solution);
}

TEST_CASE("dij test mini", "[part=3]") {
    Graph g("tests/dataset_mini_nodes.txt",
     "tests/dataset_mini_edges.txt");

    unordered_map<Vertex, unsigned> vertexMap = g.getVertexMap();
    auto it = vertexMap.begin();
    Vertex start = (*it).first;
    unsigned i = UINT_MAX;
    // Create the solution using the dijkstra alg;
    vector<unsigned> result = dijkstra(g, start);
    vector<unsigned> solution;

    // Manually enter all the distances with manual computation
    solution.push_back(0);
    solution.push_back(1);
    solution.push_back(1);
    REQUIRE(result == solution);
}


