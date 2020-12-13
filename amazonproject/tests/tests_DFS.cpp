#include "../cs225/catch/catch.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../graph.h"
#include "../DFS.h"
#include <fstream>

TEST_CASE("DFS Test 1", "[part=2]") {
    Graph g("tests/dataset_small_nodes.txt",
     "tests/dataset_small_edges.txt");

    std::vector<std::string> solution = {"Vertex(FB)", "Vertex(IG)", "Vertex(Discord)",
     "Vertex(Bing)", "Vertex(Google)", "Vertex(Reddit)", "Vertex(Yahoo)", "Vertex(Twitter)", ""};
    DFS(g);

    std::ifstream outputFile("tests/DFS_traversal.txt");
    string line;
    int count = 0;
    if (outputFile.is_open()) {
        while (getline(outputFile, line)) {
           REQUIRE(line == solution[count]);
           count++;
        }
    }
}