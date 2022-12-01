#include "map_pair.h"

using namespace std;

//Constructors
MapPair::MapPair()
{
    MapPair(Node(),set<int>());
}

MapPair::MapPair(Node key, set<int> values)
{
    this->key = key;
    this->values = values;
}

//Key-Value Functions
Node& MapPair::getKey()
{
    return key;
}

int MapPair::removeValue(int toRemove)
{
    values.erase(toRemove);
    return 1;
}

int MapPair::addValue(int key)
{
    values.insert(key);
    return 1;
}

set<int> MapPair::getValues()
{
    return values;
}

//Overload Operators
void MapPair::operator=(const MapPair& newMapPair)
{
    key = newMapPair.key;
    values = newMapPair.values;
}
