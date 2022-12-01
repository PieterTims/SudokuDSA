#include <iostream>
#include <windows.h>
#include <unordered_set>
#include "graph.h"
#include "time.h"

using namespace std;

//Constructors
Graph::Graph()
{
    //Create all node
    for(int i = 0; i < MAX_PAIR; i++)
        allNode[i] = Node(i,0);

    //Build adjacency list
    for(int i = 0; i < MAX_PAIR; i++)
        adjList[i] = MapPair(allNode[i],set<Node>());

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
            adjList[i].addIntValue(adjList[j+(row*9)].getKey().getID()); //all in row
            adjList[i].addIntValue(adjList[(column++*9)+(i%9)].getKey().getID()); // all in column
        }
        column = 0;

        for(int j = 0; j < 3; j++) //iterate grid
            for(int k = 0; k < 3; k++)
                adjList[i].addIntValue(adjList[grid[j]+k].getKey().getID());

        adjList[i].removeIntValue(adjList[i].getKey().getID());
    }

}

//Graph Functions
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
                printGraphHelper();
                cout << (char)194;
                printGraphHelper();
                cout << (char)194;
                printGraphHelper();
                cout << (char)191 << endl;
                break;
            case 1:
            case 2://mid
                cout << (char)195;
                printGraphHelper();
                cout << (char)197;
                printGraphHelper();
                cout << (char)197;
                printGraphHelper();
                cout << (char)180 << endl;
                break;
            }
        }
        if(i%3 == 0)
            cout << (char)179 <<" ";
        if(adjList[i].checkDuplicate(2))
            setcolor(12);
        if(adjList[i].getKey().getData() == 0)
            setcolor(14);
        cout << adjList[i].getKey().getData() << " ";
        setcolor(15);
    }
    //bottom
    cout << (char)179 << endl;
    cout << (char)192;
    printGraphHelper();
    cout << (char)193;
    printGraphHelper();
    cout << (char)193;
    printGraphHelper();
    cout << (char)217 << endl;
}

//Sudoku Functions
bool Graph::generateRandomSudoku()
{
    srand(time(0));//GENERATE RANDOM ACCORDING TO TIME WHEN FUNCTION CALLED
    unordered_set<int> randCells;
    int firstNine = 1;
    while(randCells.size() < 9)
        randCells.insert(rand()%81);

    for(auto it = randCells.begin(); it != randCells.end(); ++it)
        adjList[*it].getKey().setData(firstNine++);
//    return generateRandomSudokuHelper(findUnassigned());
}

//Helper Functions
void Graph::printGraphHelper()
{
    for(int i = 0; i < 7; i++)
        cout << (char)196;
}

void Graph::setcolor(unsigned short color)
{
    //set the color
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

bool Graph::generateRandomSudokuHelper(int pos)
{
    if(pos == -1)
        return true;
    for(int num = 1; num < 10; num++)
    {
        adjList[pos].getKey().setData(num);
        if(!adjList[pos].checkDuplicate())
        {
            if(generateRandomSudokuHelper(findUnassigned()))
                return true;
            adjList[pos].getKey().setData(0);
        }
    }
    return false;
}

int Graph::findUnassigned()
{
    for(int i = 0; i < MAX_PAIR; i++)
        if(adjList[i].getKey().getData() == 0)
            return i;
    return -1;
}
