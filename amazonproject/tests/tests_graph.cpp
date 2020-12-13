#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../graph.h"

TEST_CASE("Constructor test 1", "[weight=1][part=1]") {
    Graph g("tests/dataset_mini_nodes.txt",
     "tests/dataset_mini_edges.txt");
    REQUIRE(g.getAdjMatrix()[0][0] == false);
    REQUIRE(g.getAdjMatrix()[0][1] == true);
    REQUIRE(g.getAdjMatrix()[0][2] == true);
    REQUIRE(g.getAdjMatrix()[1][0] == true);
    REQUIRE(g.getAdjMatrix()[1][1] == false);
    REQUIRE(g.getAdjMatrix()[1][2] == false);
    REQUIRE(g.getAdjMatrix()[2][0] == false);
    REQUIRE(g.getAdjMatrix()[2][1] == false);
    REQUIRE(g.getAdjMatrix()[2][2] == false);
}

TEST_CASE("out degree test", "[weight=1][part=1]") {
    Graph g("tests/dataset_mini_nodes.txt",
    "tests/dataset_mini_edges.txt");
    Vertex v1("Google");
    Vertex v2("FB");
    Vertex v3("Reddit");
    REQUIRE(g.out_degree(v1) == 2);
    REQUIRE(g.out_degree(v2) == 1);
    REQUIRE(g.out_degree(v3) == 0);
}

TEST_CASE("in degree test", "[weight=1][part=1]") {
    Graph g("tests/dataset_mini_nodes.txt",
    "tests/dataset_mini_edges.txt");
    Vertex v1("Google");
    Vertex v2("FB");
    Vertex v3("Reddit");
    REQUIRE(g.in_degree(v1) == 1);
    REQUIRE(g.in_degree(v2) == 1);
    REQUIRE(g.in_degree(v3) == 1);
}

TEST_CASE("is out adjacent test", "[weight=1][part=1]") {
    Graph g("tests/dataset_mini_nodes.txt",
    "tests/dataset_mini_edges.txt");
    Vertex v1("Google");
    Vertex v2("FB");
    Vertex v3("Reddit");
    REQUIRE(g.is_outAdjacent(v1, v2) == true);
    REQUIRE(g.is_outAdjacent(v2, v1) == true);
    REQUIRE(g.is_outAdjacent(v1, v3) == true);
    REQUIRE(g.is_outAdjacent(v3, v1) == false);
    REQUIRE(g.is_outAdjacent(v2, v3) == false);
    REQUIRE(g.is_outAdjacent(v3, v2) == false);
}

TEST_CASE("size test", "[weight=1][part=1]") {
    Graph g("tests/dataset_large_nodes.txt",
     "tests/dataset_large_edges.txt");
    REQUIRE(g.size() == 1000);
}


