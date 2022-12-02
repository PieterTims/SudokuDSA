#include <iostream>
#include "graph.h"
using namespace std;

void printLineHelper()
{
    for(int i = 0; i < 30; i++)
        cout << (char)205;
}

void mainMenu()
{
    cout << (char)218 <<"    SUDOKU GAME & SOLVER      " << (char)191<< endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)179 << " Play Sudoku                P " << (char)179 << endl;
    cout << (char)179 << " Auto-solve a Sudoku        S " << (char)179 << endl;
    cout << (char)179 << " Quit                       Q " << (char)179 << endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)192 << " Please enter your choice:    " << (char)217 << endl;
}

void playMenu()
{
    cout << (char)218 <<"        PLAYING SUDOKU        " << (char)191<< endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)179 << " How to play: Choose square   " << (char)179 << endl;
    cout << (char)179 << " using x,y coordinates and a  " << (char)179 << endl;
    cout << (char)179 << " number from 1-9. Example:    " << (char)179 << endl;
    cout << (char)179 << "  0 1 5  or  2 3 9  or  8 8 1 " << (char)179 << endl;
    cout << (char)179 << " Enter: -1 -1 -1              " << (char)179 << endl;
    cout << (char)179 << " to stop play                 " << (char)179 << endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)192 << " Please enter your answer:    " << (char)217 << endl;
}

void solveMenu()
{
    cout << (char)218 <<"    INPUT SUDOKU TO SOLVE     " << (char)191<< endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)179 << " How to input: Choose square  " << (char)179 << endl;
    cout << (char)179 << " using x,y coordinates and a  " << (char)179 << endl;
    cout << (char)179 << " number from 1-9. Example:    " << (char)179 << endl;
    cout << (char)179 << "  0 1 5  or  2 3 9  or  8 8 1 " << (char)179 << endl;
    cout << (char)179 << " Enter: -1 -1 -1              " << (char)179 << endl;
    cout << (char)179 << " to start auto solve          " << (char)179 << endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)192 << " Please enter into grid:      " << (char)217 << endl;
}

void finishPlayMenu()
{
    cout << (char)218 << "       CONGRATULATIONS!!      "<< (char)191<< endl;
    cout << (char)179 << "     YOU SOLVED THE SUDOKU    " << (char)179<< endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)179 << " Would you like to play more? " << (char)179 << endl;
    cout << (char)179 << "                              " << (char)179 << endl;
    cout << (char)179 << " Yes one more game please   Y " << (char)179 << endl;
    cout << (char)179 << " No bring me back home      N " << (char)179 << endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)192 << " Please enter your choice:    " << (char)217 << endl;
}

void finishSolveMenu()
{
    cout << (char)218 << "      AUTO-SOLVED SUDOKU      "<< (char)191<< endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)179 << " Would you like to make more ?" << (char)179 << endl;
    cout << (char)179 << "                              " << (char)179 << endl;
    cout << (char)179 << " Yes one more sudoku        Y " << (char)179 << endl;
    cout << (char)179 << " No bring me back home      N " << (char)179 << endl;
    cout << (char)179;
    printLineHelper();
    cout << (char)179 << endl;
    cout << (char)192 << " Please enter your choice:    " << (char)217 << endl;
}

void playSudoku()
{
    //create a solution list and unsolve it to play
    Graph solution = Graph();
    solution.generateSolution();
    Graph unsolved = solution;
    unsolved.createUnsolved(solution);

    int x,y,ans;
    bool loop = true;
    int loop_check = 0;
    //main loop to play
    while(loop)
    {
        unsolved.printGraph(solution);
        playMenu();
        cin >> x >> y >> ans;
        cin.ignore();
        system("cls");
        if(x == -1 && y == -1 && ans == -1)
            return;
        if(x < 0 || x > 8 || y < 0 || y > 8 || ans < 1 || ans > 9)
            cout << "   Please enter a valid input.\n";
        else
            loop_check = unsolved.updateGrid(y*9+x, ans, solution);
        if(loop_check == 1)
            break;
    }
    system("cls");
    unsolved.printGraph(solution);
    finishPlayMenu();

    string menu_selection;
    cin >> menu_selection;
    cin.ignore();
    system("cls");
    switch (toupper(menu_selection.at(0)))
    {
    case 'Y': //Play a Sudoku
        cout << "\n";
        playSudoku();
        break;
    }
}

void solveSudoku()
{
    Graph problem = Graph();
    Graph solution = problem;

    int x,y,ans;
    bool loop = true;
    while(loop)
    {
        problem.printGraph(solution);
        solveMenu();
        cin >> x >> y >> ans;
        cin.ignore();
        system("cls");
        if(x == -1 && y == -1 && ans == -1)
            break;
        if(x < 0 || x > 8 || y < 0 || y > 8 || ans < 1 || ans > 9)
            cout << "   Please enter a valid input.\n";
        else{
            problem.adjList[y*9+x].getKey().unchanged = false;
            problem.updateGrid(y*9+x, ans, solution);
        }

    }
    system("cls");
    solution = problem;
    solution.generateSolution();
    solution.printGraph(problem);
    finishSolveMenu();

    string menu_selection;
    cin >> menu_selection;
    cin.ignore();
    system("cls");
    switch (toupper(menu_selection.at(0)))
    {
    case 'Y': //Solve a Sudoku
        cout << "\n";
        solveSudoku();
        break;
    }
}

int main()
{
    cout << "\n";
    string menu_selection;
    bool loop = true;
    // loops a menu selection for P, S and Q. reprints menu for any other input
    while (loop)
    {
        mainMenu();
        cin >> menu_selection;
        cin.ignore();
        system("cls");
        switch (toupper(menu_selection.at(0)))
        {
        case 'P': //Play a Sudoku
            cout << "\n";
            playSudoku();
            break;
        case 'S': //Solve a Sudoku
            cout << "\n";
            solveSudoku();
            break;
        case 'Q': //Quit
            loop = false;
            break;
        default:
            cout << "   Please enter a valid input.\n";
        }
    }
    return 0;
}
