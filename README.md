# SudokuDSA
http://norvig.com/sudoku.html - Sudoku solving(Peter Norvig)
https://iq.opengenus.org/backtracking-sudoku/ - Backtracking

Building CMD UI using colors and extended ASCII
https://www.geeksforgeeks.org/setcolor-function-c/
https://theasciicode.com.ar/





unordered_set<int> randCells;
    int firstNine = 1;
    while(randCells.size() < 9)
        randCells.insert(rand()%81);

    for(auto it = randCells.begin(); it != randCells.end(); ++it)
        adjList[*it].getKey().setData(firstNine++);
