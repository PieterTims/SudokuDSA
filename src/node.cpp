#include "node.h"
using namespace std;

//Constructors
Node::Node()
{
    Node(-1,0);
}

Node::Node(int id, int data)
{
    this->id = id;
    this->data = data;
}

//Node Functions
int Node::getData()
{
    return data;
}

int Node::setData(int data)
{
    this->data = data;
    return 1;
}

int Node::getID()const
{
    return id;
}

//Overload Operators
void Node::operator=(const Node& newNode)
{
    id = newNode.id;
    data = newNode.data;
}
