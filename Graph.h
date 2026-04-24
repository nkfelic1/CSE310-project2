#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"
#include <iostream>

class Graph {
    private:
        int numVertices;
        int numEdges;
        int** adjMatrix;
        Vertex vertices[1000];
        int oddNodes[1000];
        int oddCount;

    public:
        Graph(int n, int m);
        void addEdge(int u, int v, int w);     // add edge
        void printAdjMatrix();                 // print matrix
        void printOddDegreeNodes();            // print odd degree nodes
        void dijkstra(int source);             // dijkstra
};

#endif