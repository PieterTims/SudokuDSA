#include "node.h"
using namespace std;

Node::Node(int id)
{
    Node(id,0);
}

Node::Node(int id, int data)
{
    this->id = id;
    this->data = data;
}

int Node::getID()
{
    return id;
}

int Node::getData()
{
    return data;
}

int Node::setData(int data)
{
    this->data = data;
    return 1;
}
