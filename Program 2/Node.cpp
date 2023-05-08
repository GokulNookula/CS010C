#include <iostream>
#include <string>
#include "Node.h"

Node::Node(const string dataValue)
{
    count = 1;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    data = dataValue;
}

string Node::getString() const
{
    return data;
}
