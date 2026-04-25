#include "Edge.h"
#include "Graph.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!(std::cin >> numOfVertices >> numOfEdges)) {
        std::cout << "Input not found!" << std::endl;
        return 1;
    }

    Graph* g = new Graph(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);
        // Here is where you load up the Graph object   
        g->addEdge(startVertice, endVertice, weight);
    }

    // And here is where you start working on the three tasks
    g->printAdjMatrix();
    std::cout << std::endl;
    g->printOddDegreeNodes();

    return 0;
}