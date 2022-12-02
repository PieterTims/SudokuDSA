#ifndef MAP_PAIR_H
#define MAP_PAIR_H

#define MAX_VECTOR_SIZE 20
#include "node.h"
#include <set>

class MapPair
{
    public:
        //Constructors
        MapPair();
        MapPair(Node,std::set<int>);

        //Map Functions
        Node& getKey();
        int addValue(int);
        int removeValue(int);
        std::set<int> getValues();

        //Overload Operators
        void operator=(const MapPair&);

    private:
        //Map Variables
        Node key;
        std::set<int> values;
        std::set<int>::iterator it;
};

#endif // MAP_PAIR_H
