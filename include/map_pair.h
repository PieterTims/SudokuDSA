#ifndef MAP_PAIR_H
#define MAP_PAIR_H

#define MAX_VECTOR_SIZE 20
#include "node.h"
#include <vector>
#include <algorithm>

class MapPair
{
    public:
        //Constructors
        MapPair();
        MapPair(int,Node,std::vector<Node>);
        //Getters
        Node getKey();
        std::vector<Node> getValues();
        int getID();
        //Functions
        int addValue(Node);
        Node findValue(Node);
        //Operators
        void operator=(const MapPair&);
    private:
        int ID;
        Node key;
        std::vector<Node> values;
        std::vector<Node>::iterator it;
};

#endif // MAP_PAIR_H
