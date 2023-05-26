#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//constructor
Node::Node(string userKey)
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = 0;
    key = userKey;
}
