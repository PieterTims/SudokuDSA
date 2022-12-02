#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Graph solution = Graph();
    solution.generateSolution();
    Graph unsolved = solution;
    unsolved.createUnsolved(solution);
    solution.printGraph();
    unsolved.printGraph();

    return 0;
}
