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
    //Getters
    int getID();
    int getData();
    //Setters
    int setData(int);
    //Operators
    bool operator<(const Node&)const;
    bool operator==(const Node&)const;
    void operator=(const Node&);
private:
    int id;
    int data;
};

#endif // NODE_H
