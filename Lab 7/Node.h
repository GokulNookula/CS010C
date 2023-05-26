#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

struct Node
{
    //constructor
    Node(string);

    //data
    int height;
    string key;

    //connected Nodes
    Node* left;
    Node* right;
    Node* parent;
};

#endif
