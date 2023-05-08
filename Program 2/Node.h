#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string.h>

using namespace std;

class Node
{
    public:
        string data;
        int count;
        Node* left;
        Node* right;
        Node* parent;
        Node(const string);
        string getString() const;
        void add();
        void sub();
};


#endif
