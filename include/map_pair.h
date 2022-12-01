#ifndef MAP_PAIR_H
#define MAP_PAIR_H

#define MAX_VECTOR_SIZE 20
#include "node.h"
#include <set>
#include <algorithm>

class MapPair
{
    public:
        //Constructors
        MapPair();
        MapPair(Node,std::set<Node>);

        //Key-Value Functions
        Node& getKey();
        std::set<Node> getValues();
        int addValue(Node);
        int removeValue(Node);
        Node findValue(Node);
        bool hasValue(Node);

        int addIntValue(int);
        int removeIntValue(int);

        //Sudoku Functions
        bool checkDuplicate();
        bool checkDuplicate(int);

        //Overload Operators
        void operator=(const MapPair&);

        //Public Variables

    private:
        //Key-Value Variables
        Node key;
        std::set<Node> values;
        std::set<Node>::iterator it;

        std::set<int> intValues;

        //Sudoku Variables
};

#endif // MAP_PAIR_H
