#ifndef __NODE_H
#define __NODE_H

#include <iostream>
#include <string>

using namespace std;

class Node 
{

  friend class Tree;

private:
  string small;
  string large;

  Node *left;
  Node *middle;
  Node *right;
  Node *parent;

  // Node class constructor
  Node();

  // Check if the node has two strings
  bool hasTwoStrings() const;
  // Check if the node has three children
  bool hasTwoChildren() const;

  //Copy Constructor
  Node(const Node&) = delete;
  
  //Copy Assignment
  Node& operator=(const Node& ) = delete;

};

#endif
