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
        MapPair(int,Node,std::set<Node>);
        //Getters
        Node getKey();
        std::set<Node> getValues();
        int getID();
        //Functions
        int addValue(Node);
        int removeValue(Node);
        Node findValue(Node);
        bool hasValue(Node);
        //Operators
        void operator=(const MapPair&);
    private:
        int ID;
        Node key;
        std::set<Node> values;
        std::set<Node>::iterator it;
};

#endif // MAP_PAIR_H
