#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//Default Constructor
Node::Node()
{
    left = nullptr;
    middle = nullptr;
    right = nullptr;
    parent = nullptr;
}

bool Node::hasTwoStrings() const
{
    // Check if the node has two strings by checking if the 'large' string is not empty
    return !large.empty();
}

bool Node::hasTwoChildren() const
{
    // Check if the node has three children by checking if 'left', 'middle', and 'right' pointers are not nullptr
    return left && middle && right;
}
