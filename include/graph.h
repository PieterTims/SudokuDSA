#ifndef GRAPH_H
#define GRAPH_H

#define MAX_PAIR 81
#include <unordered_set>
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

    //Helper Functions
    void printGraphHelper();
    void setcolor(unsigned short);
    bool generateRandomSudokuHelper(int,std::unordered_set<int>);
    int findUnassigned();
    bool checkDuplicate(int);
    bool checkDuplicate(int,int);
    std::unordered_set<int> shufflingNine();
};

#endif // GRAPH_H
