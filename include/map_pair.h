#ifndef MAP_PAIR_H
#define MAP_PAIR_H

#define MAX_VECTOR_SIZE 20
#include "node.h"

class map_pair
{
    public:
        map_pair();
    private:
        Node key;
        std::vector<Node> values;
};

#endif // MAP_PAIR_H
