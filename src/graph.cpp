#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "graph.h"
#include "time.h"

using namespace std;

Graph::Graph()
{
    //Build adjacency list
    srand(time(0));
    for(int i = 0; i < MAX_PAIR; i++)
        adjList[i] = MapPair(Node(i,rand()%9+1),set<Node>());

    //Add neighbors
    int row = 0;
    int column = 0;
    int grid[] = {0,0,0};
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
    for(int i = 0; i < MAX_PAIR; i++){
        adjList[i].allDuplicate(adjList[i].getKey().getData());
    }
}

void Graph::printGraph()
{
    for(int i = 0; i < MAX_PAIR; i++)
    {
        if(i%9 == 0 && i != 0)
            cout << (char)179 << endl;
        if(i%27 == 0)
        {
            switch(i/27)
            {
            case 0: //top
                cout << (char)218;
                printLineHelper();
                cout << (char)194;
                printLineHelper();
                cout << (char)194;
                printLineHelper();
                cout << (char)191 << endl;
                break;
            case 1:
            case 2://mid
                cout << (char)195;
                printLineHelper();
                cout << (char)197;
                printLineHelper();
                cout << (char)197;
                printLineHelper();
                cout << (char)180 << endl;
                break;
            }
        }
        if(i%3 == 0)
            cout << (char)179 <<" ";
        if(adjList[i].existsDuplicate() > 0)
            setcolor(12);
        cout << adjList[i].getKey().getData() << " ";
        setcolor(15);
    }
    cout << (char)179 << endl;
    cout << (char)192;
    printLineHelper();
    cout << (char)193;
    printLineHelper();
    cout << (char)193;
    printLineHelper();
    cout << (char)217 << endl;
}

//Private Functions
void Graph::printLineHelper()
{
    for(int i = 0; i < 7; i++)
        cout << (char)196;
}

void Graph::setcolor(unsigned short color)                 //The function that you'll use to
{
    //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
