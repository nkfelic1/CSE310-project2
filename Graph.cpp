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
    cout << "}\n" << endl;
}

int* Graph::getOddNodes() {
    return oddNodes;
}

int Graph::getOddCount() {
    return oddCount;
}

void Graph::dijkstra(int source) {
    int dist[numVertices + 1];
    int prev[numVertices + 1];
    int visited[numVertices + 1];

    for (int i = 1; i <= numVertices; i++) {
        if (i == source) {
            dist[i] = 0;
        } else {
            dist[i] = INT_MAX;
        }
        prev[i] = -1;
        visited[i] = 0;
    }

    for (int i = 0; i < numVertices; i++) {
        int u = -1;
        for (int j = 1; j <= numVertices; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }

        if (u == -1 || dist[u] == INT_MAX) {
            break;
        }

        visited[u] = 1;

        for (int v = 1; v <= numVertices; v++) {
            if (adjMatrix[u][v] != 0 && !visited[v]) {
                int newDist = dist[u] + adjMatrix[u][v];
                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    prev[v] = u;
                }
            }
        }
    }

    for (int i = 1; i <= numVertices; i++) {
        vertices[i - 1].setDistance(dist[i]);
        if (prev[i] != -1) {
            vertices[i - 1].setPrevious(&vertices[prev[i] - 1]);
        }
    }

    cout << "The shortest path lengths from Node " << source << " to all other nodes are:" << endl;
    for (int i = 1; i <= numVertices; i++) {
        cout << i << ": " << dist[i] << endl;
    }
    cout << "\n";
}