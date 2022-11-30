#include "node.h"
using namespace std;

Node::Node()
{
    Node(-1,-1);
}
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

bool Node::operator<(const Node& otherNode)const
{
    return id < otherNode.id;
}

bool Node::operator==(const Node& otherNode)const
{
    return id == otherNode.id;
}

void Node::operator=(const Node& newNode)
{
    id = newNode.id;
    data = newNode.data;
}
