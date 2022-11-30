#include <iostream>
#include "graph.h"

using namespace std;

Graph::Graph()
{
    //Build adjacency list
    for(int i = 0; i < MAX_PAIR; i++)
    {
        adjList[i] = MapPair(i,Node(i,-1),set<Node>());
    }
    cout<<"Created Adjacency List"<<endl;

    //Add neighbors
    int row = 0;
    int column = 0;
    int grid[] = {0,0,0}; //id of topleft
    for(int i = 0; i < MAX_PAIR; i++)
    {
        if(i%9 == 0 && i != 0)
            row++;
        grid[0] = i - (row%3)*9;
        grid[0] = grid[0] - grid[0]%3;
        grid[1] = grid[0] + 9;
        grid[2] = grid[1] + 9;
        for (int j = 0; j < 9; j++)
        {
            adjList[i].addValue(adjList[j+(row*9)].getKey()); //all in row
            adjList[i].addValue(adjList[(column++*9)+(i%9)].getKey()); // all in column
        }
        column = 0;

        for(int j = 0; j < 3; j++) //iterate grid
            for(int k = 0; k < 3; k++)
                adjList[i].addValue(adjList[grid[j]+k].getKey());

        adjList[i].removeValue(adjList[i].getKey());
    }
    cout <<"DONE" <<endl;
}
//Add neighbor in 3x3 grid


void Graph::printGraph()
{
    for(int i = 0; i < MAX_PAIR; i++)
    {
        cout << adjList[i].getKey().getID() << " ";
        if(adjList[i].getKey().getID()<10)
            cout<<" ";
        for(Node value : adjList[i].getValues())
        {
            cout<<value.getID() << " ";
            if(value.getID()<10)
                cout<<" ";
        }
        cout << endl;
    }
}
