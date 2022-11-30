#include "map_pair.h"

using namespace std;

MapPair::MapPair()
{
    this->key = Node();
    this->values = set<Node>();
}

MapPair::MapPair(int ID, Node key, set<Node> values)
{
    this->ID = ID;
    this->key = key;
    this->values = values;
}

Node MapPair::getKey()
{
    return this->key;
}

set<Node> MapPair::getValues()
{
    return this->values;
}

int MapPair::getID()
{
    return this->ID;
}

int MapPair::addValue(Node toAdd)
{
    values.insert(toAdd);
    return 1;
}

int MapPair::removeValue(Node toRemove)
{
    values.erase(toRemove);
    return 1;
}
Node MapPair::findValue(Node toSearch)
{
    it = find(values.begin(),values.end(),toSearch);
    if(it!=values.end())
    {
        return toSearch;
    }
    return Node();
}

bool MapPair::hasValue(Node toSearch)
{
    it = find(values.begin(),values.end(),toSearch);
    if(it!=values.end())
    {
        return true;
    }
    return false;
}

void MapPair::operator=(const MapPair& newMapPair)
{
    ID = newMapPair.ID;
    key = newMapPair.key;
    values = newMapPair.values;
}
