#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Graph::Graph(int n, int m) {
    this->numVertices = n;
    this->numEdges = m;
    adjMatrix = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        adjMatrix[i] = new int[n + 1]();
    }
}

void Graph::addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;
}

void Graph::printAdjMatrix() {
    cout << "The adjacency matrix of G is:" << endl;
    for (int i = 1; i <= numVertices; i++) {
        for (int j = 1; j <= numVertices; j++) {
            cout << adjMatrix[i][j];
            if (j < numVertices) cout << " ";
        }
        cout << endl;
    }
}