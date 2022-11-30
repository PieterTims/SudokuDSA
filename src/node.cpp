#include "node.h"
using namespace std;

//Constructors
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

//Node Functions
int Node::getID()
{
    return id;
}

int Node::getData()const
{
    return data;
}

int Node::setData(int data)
{
    this->data = data;
    return 1;
}

//Overload Operators
bool Node::operator<(const Node& otherNode)const
{
    return id < otherNode.id;
}

bool Node::operator==(const Node& otherNode)const
{
    return id == otherNode.id;
}

bool Node::operator==(const int data)const
{
    return this->data == data;
}

void Node::operator=(const Node& newNode)
{
    id = newNode.id;
    data = newNode.data;
}
