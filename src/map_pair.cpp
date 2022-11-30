#include "map_pair.h"

using namespace std;

//Constructors
MapPair::MapPair()
{
    MapPair(Node(),set<Node>());
}

MapPair::MapPair(Node key, set<Node> values)
{
    this->key = key;
    this->values = values;
}

//Key-Value Functions
Node MapPair::getKey()
{
    return key;
}

set<Node> MapPair::getValues()
{
    return values;
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

//Sudoku Functions
void MapPair::allDuplicate(int data)
{
    set<Node> newDupeList = set<Node>();
    for(it = values.begin(); it != values.end(); ++it)
    {
        if((*it).getData() == data)
        {
            Node n = *it;
            newDupeList.insert(n);
        }
    }
    duplicates = newDupeList;
}

int MapPair::existsDuplicate()
{
    return duplicates.size();
}

set<Node> MapPair::getDuplicates()
{
    return duplicates;
}

//Overload Operators
void MapPair::operator=(const MapPair& newMapPair)
{
    key = newMapPair.key;
    values = newMapPair.values;
}
