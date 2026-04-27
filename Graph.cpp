#include "Graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

Graph::Graph(int n, int m) {
    this->numVertices = n;
    this->numEdges = m;
    this->oddCount = 0;                          //initiate oddCount = 0

    adjMatrix = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        adjMatrix[i] = new int[n + 1]();
    }

    for (int i = 0; i < n; i++) {               //initiate index and degree
        vertices[i].setIndex(i + 1);
        vertices[i].setDegree(0);
    }
}

void Graph::addEdge(int u, int v, int w) {
    adjMatrix[u][v] = w;
    adjMatrix[v][u] = w;

    vertices[u-1].setDegree(vertices[u-1].getDegree() + 1);    //update degree for u
    vertices[v-1].setDegree(vertices[v-1].getDegree() + 1);    //update degree for v
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

void Graph::printOddDegreeNodes() {
    oddCount = 0;

    //retrieve all the nodes and find the odd edges
    for (int i = 0; i < numVertices; i++) {
        if (vertices[i].getDegree() % 2 != 0) {
            oddNodes[oddCount] = vertices[i].getIndex();
            oddCount++;
        }
    }

    cout << "The nodes with odd degrees in G are:" << endl;
    cout << "O = { " ;
    for (int i = 0; i < oddCount; i++) {
        cout << oddNodes[i] << " ";
    }
    cout << "}" << endl;
}

void Graph::dijkstra(int source) {
    cout << "The shortest path lengths from Node " << source << " to all other nodes are:" << endl;
}