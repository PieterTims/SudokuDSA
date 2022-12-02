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

    //Sudoku Functions
    bool generateSolution();
    bool createUnsolved(Graph);
    bool updateGrid(int,int);

    //Graph Variables
    Node allNode[MAX_PAIR];
    MapPair adjList[MAX_PAIR];
private:


    //Print Helper Functions
    void printGraphHelper();
    void setcolor(unsigned short);

    //Sudoku Helper Functions
    bool generateSolutionHelper(int,std::unordered_set<int>);
    std::unordered_set<int> shufflingNine();

    //General Helper Functions
    int findUnassigned();
    bool checkDuplicate(int);
    bool checkDuplicate(int,int);
};

#endif // GRAPH_H
