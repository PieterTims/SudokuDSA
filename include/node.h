#ifndef NODE_H
#define NODE_H

//DO NOT FORGET TO IMPLEMENT DESTRUCTOR
//ALWAYS SET ID TO MAKE SURE NO DUPLICATE

class Node
{
public:
    //Constructors
    Node();
    Node(int,int);

    //Node Functions
    int getID()const;
    int getData();
    int setData(int);

    //Overload Operators
    void operator=(const Node&);

    //Sudoku Variables
    bool unchanged = true;

private:
    //Node Variables
    int id;
    int data;
};

#endif // NODE_H
