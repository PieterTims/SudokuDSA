#ifndef GRAPH_H
#define GRAPH_H

#define MAX_PAIR 81
#include "map_pair.h"
//DO NOT FORGET TO IMPLEMENT DESTRUCTOR

class Graph
{
public:
    //Constructors
    Graph();
//    Graph(); //read from file

    //Graph Functions
    void printGraph();
    int findID(int);

    //Sudoku Functions
    bool generateRandomSudoku();

private:
    //Graph Variables
    MapPair adjList[MAX_PAIR];
    Node allNode[MAX_PAIR];
    //Sudoku Variables

    //Helper Functions
    void printGraphHelper();
    void setcolor(unsigned short);
    bool generateRandomSudokuHelper(int);
    int findUnassigned();
};

#endif // GRAPH_H
