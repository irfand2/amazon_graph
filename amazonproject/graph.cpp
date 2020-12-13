#include "graph.h"
#include <fstream>

Graph::Graph(std::string nodes_file, std::string edges_file) {
    // Read from nodes_file.
    std::ifstream nodesFile(nodes_file);
    unsigned count = 0;
    string node_id;
    // Populate vertexMap and vertexList
    if (nodesFile.is_open()) {
        while (getline(nodesFile, node_id)) {
            Vertex v(node_id);
			vertexMap[v] = count;
			vertexList.push_back(v);
            count++;
        }
    }
    // Set adjMatrix size to be (number of nodes ^ 2).
    adjMatrix.resize(vertexMap.size());
    for (unsigned i = 0; i < adjMatrix.size(); i++) {
        adjMatrix[i].resize(vertexMap.size());
    }
    // Read from edges_file.
    std::ifstream edgesFile(edges_file);
    string node_fromid, node_toid;
    if (edgesFile.is_open()) {
        while (edgesFile >> node_fromid >> node_toid) {
            Vertex v_from(node_fromid); Vertex v_to(node_toid);
            // Populate adjMatrix.
            adjMatrix[vertexMap[v_from]][vertexMap[v_to]] = true;
        }
    }
}


int Graph::out_degree(const Vertex & v) const {
    int degree = 0;
    // Traverse all columns of a particular row of adjMatrix 
    // that has v as source vertex.
    for (unsigned i = 0; i < adjMatrix.size(); i++) {
        if (adjMatrix[vertexMap.at(v)][i]) {
            degree++;
        }
    }
    return degree;
}

int Graph::in_degree(const Vertex & v) const {
    int degree = 0;
    // Traverse all rows of a particular column of adjMatrix
    // that has v as destination vertex.
    for (unsigned i = 0; i < adjMatrix[vertexMap.at(v)].size(); i++) {
        if (adjMatrix[i][vertexMap.at(v)]) {
            degree++;
        }
    }
    return degree;
}

bool Graph::is_outAdjacent(const Vertex & v1, const Vertex & v2) const {
    if (adjMatrix[vertexMap.at(v1)][vertexMap.at(v2)]) {
        return true;
    }
    return false;
}

unsigned Graph::size() const {
    return vertexMap.size();
}

Vertex Graph::getVertexFromIndex(unsigned index) {
	return vertexList.at(index);
}


    
