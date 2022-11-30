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
        Node getKey();
        std::set<Node> getValues();
        int addValue(Node);
        int removeValue(Node);
        Node findValue(Node);
        bool hasValue(Node);

        //Sudoku Functions
        void allDuplicate(int);
        int existsDuplicate();
        std::set<Node> getDuplicates();

        //Overload Operators
        void operator=(const MapPair&);

    private:
        //Key-Value Variables
        Node key;
        std::set<Node> values;
        std::set<Node>::iterator it;

        //Sudoku Variables
        std::set<Node> duplicates;
};

#endif // MAP_PAIR_H
