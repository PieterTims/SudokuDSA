#include "map_pair.h"

using namespace std;

MapPair::MapPair()
{
    this->key = Node();
    this->values = vector<Node>();
}

MapPair::MapPair(int ID, Node key, vector<Node> values)
{
    this->ID = ID;
    this->key = key;
    this->values = values;
}

Node MapPair::getKey()
{
    return this->key;
}

vector<Node> MapPair::getValues()
{
    return this->values;
}

int MapPair::getID()
{
    return this->ID;
}

int MapPair::addValue(Node toAdd)
{
    values.push_back(toAdd);
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

void MapPair::operator=(const MapPair& newMapPair)
{
    ID = newMapPair.ID;
    key = newMapPair.key;
    values = newMapPair.values;
}
