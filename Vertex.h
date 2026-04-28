#ifndef VERTEX_H
#define VERTEX_H

class Vertex{
    private:
       int index;
       int degree;
       int distance;
       Vertex* previous;
       bool visited;
    public:
        Vertex();
        int getIndex();
        int getDegree();
        int getDistance();
        Vertex* getPrevious();
        bool isVisited();
        void setIndex(int);
        void setDegree(int);
        void setDistance(int);
        void setPrevious(Vertex*);
        void setVisited(bool);
};


#endif