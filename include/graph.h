#ifndef GRAPH_H
#define GRAPH_H

#define MAX_PAIR 81
#include "map_pair.h"
//DO NOT FORGET TO IMPLEMENT DESTRUCTOR

class Graph
{
public:
    Graph(); //array of linked list size
    void printGraph();
    int findID(int);
private:
    MapPair adjList[MAX_PAIR];
    void printLineHelper();
    void setcolor(unsigned short);
};

#endif // GRAPH_H
