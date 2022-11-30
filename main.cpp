#include <iostream>
#include <windows.h>
#include "graph.h"
#include <vector>
using namespace std;

void setcolor(unsigned short color)                 //The function that you'll use to
{
    //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}

void printSudoku()
{
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            setcolor(12);
            cout << 1 << " ";
            if(j%3 == 2)
                cout << "| ";
        }
        cout << endl;
        if(i%3 == 2)
            cout << "------+-------+---------" << endl;
    }
}

int main()
{
    Graph adjList = Graph();

    return 0;
}
