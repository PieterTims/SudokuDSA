#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    //Build adjacency list
    for(int i = 0; i < MAX_PAIR; i++)
    {
        adjList[i] = MapPair(i,Node(i,-1),vector<Node>());
    }
    cout<<"Created Adjacency List"<<endl;

    //Add neighbors
    int row = 0;
    int column = 0;
    for(int i = 0; i < MAX_PAIR; i++)
    {
        if(i%9 == 0 && i !=0)
            row++;
        for (int j = 0; j < 9; j++)
        {
            if(i != j+(row*9) && i!=(column*9)+(i%9))
            {
                adjList[i].addValue(adjList[j+(row*9)].getKey());

                adjList[i].addValue(adjList[(column*9)+(i%9)].getKey());
            }
            column++;
        }
        column = 0;
    }
    cout <<"DONE" <<endl;
}
//Add neighbor in 3x3 grid


void Graph::printGraph()
{
//    REDO THIS
}
