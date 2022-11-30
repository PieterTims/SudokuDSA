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
    cout<<"Created List"<<endl;

    //Add neighbors
    int row = 0;
    int column = 0;
    for(int i = 0; i < MAX_PAIR; i++)
    {
        if(i%9 == 0 && i !=0)
            row++;
        for (int j = 0; j < 9; j++)
        {
            if(i != j+(row*9))
            {
                adjList[i].addValue(adjList[j+(row*9)].getKey());
                cout << adjList[i].getValues().back().getID() << " ";
            }
//            cout<<(column++*9)+(i%9)<<" ";
//            if(i!= (column++*9)+(i%9))
//            {
//                adjList[i].addValue(adjList[(column*9)+(i%9)].getKey());
//                cout << adjList[i].getValues().back().getID() << " ";
//            }
        }

        for (int j = 0; j < 9; j++)
        {
            if(i!=(column*9)+(i%9))
            {
                adjList[i].addValue(adjList[(column*9)+(i%9)].getKey());
                cout << adjList[i].getValues().back().getID() << " ";
            }
            column++;
        }
        column = 0;
        cout << endl;
    }
}
//Add neighbor in row
//int row = 0
//for loop
//head[j+(row*9)]

//Add neighbor in column
//int column = 0
//for loop
//head[(column*9+i%9)]
//column++
//end for loop
//column reset to 0

//Add neighbor in 3x3 grid


void Graph::printGraph()
{
//    for(int i = 0; i < SIZE; i++)
//    {
//        Node *temp = head[i];
//        while (temp->next != nullptr){
//            cout << temp->getID() << " -> ";
//            temp = temp->next;
//        }
//        cout << endl;
//    }
}
