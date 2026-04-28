#include "Vertex.h"

Vertex::Vertex(){
    this->index = -1;
    this->degree = -1;
    this->distance = 1000;
    this->previous = nullptr;
}

int Vertex::getIndex(){
    return this->index;
}

int Vertex::getDegree(){
    return this->degree;
}

int Vertex::getDistance(){
    return this->distance;
}

Vertex* Vertex::getPrevious(){
    return this->previous;
}

bool Vertex::isVisited() {
    return this->visited;
}

void Vertex::setIndex(int index){
    this->index = index;
}

void Vertex::setDegree(int deg){
    this->degree = deg;
}

void Vertex::setDistance(int dist){
    this->distance = dist;
}

void Vertex::setPrevious(Vertex* prev){
    this->previous = prev;
}

void Vertex::setVisited(bool visited) {
    this->visited = visited;
}