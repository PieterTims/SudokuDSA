#ifndef NODE_H
#define NODE_H

//DO NOT FORGET TO IMPLEMENT DESTRUCTOR
//ALWAYS SET ID TO MAKE SURE NO DUPLICATE

class Node
{
public:
    //Constructors
    Node();
    Node(int); //no data
    Node(int,int);

    //Node Functions
    int getID();
    int getData()const;
    int setData(int);

    //Operators
    bool operator<(const Node&)const;
    bool operator==(const Node&)const;
    bool operator==(const int)const;
    void operator=(const Node&);

private:
    //Node Variables
    int id;
    int data;
};

#endif // NODE_H
