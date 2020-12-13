#include <iostream>
#include <vector>
#include <stack>
#include "DFS.h"
#include <fstream>
#include <stdio.h>

using std::cout;

void DFS(Graph g) {
    // Sets all the vertices to be unvisisted.
    std::vector<bool> visited(g.size());
    for (unsigned i = 0; i < g.size(); i++) {
        visited[i] = false;
    }
    // Deletes the output file if it already exists.
    remove("tests/DFS_traversal.txt");
    // Traverses the vertex map and runs a DFS from a vertex if it is unvisited
    for (auto& it: g.getVertexMap()) {
        if (!visited[it.second]) {
            DFS(it.first, visited, g);
        }
    }
}

void DFS(Vertex v, std::vector<bool>& visited, Graph& g) {
    std::stack<Vertex> stack; 
    stack.push(v); 
    while (!stack.empty()) {
        v = stack.top();
        stack.pop();
        // If the current vertex in the stack is not visited,
        // set it to be visited,
        // add the vertex to the path output file,
        // add all unvisited neighbors of the vertex to the stack
        if (!visited[g.getVertexMap().at(v)]) {
            visited[g.getVertexMap().at(v)] = true; 
            std::ofstream ofile ("tests/DFS_traversal.txt", std::ios_base::app);
            ofile << v << '\n';
            // get the neighbors list and add unvisited vertices to the stack.
			unsigned idx = g.getVertexMap().at(v);
			for (unsigned i = 0; i < g.size(); i++) {
				if (g.getAdjMatrix()[idx][i]) {
					if (!visited[i]) {
						stack.push(g.getVertexFromIndex(i));
					}
				}
			}           
        } 
    }
}

