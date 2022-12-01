#include "graph.h"
using namespace std;

int main()
{
    Graph solution = Graph();
    solution.generateRandomSudoku();
    solution.printGraph();
//    Node testNode;
//    testNode = Node(90,1);
//    cout<<testNode.getData()<<endl;
    return 0;
}
