#ifndef __TREE_H
#define __TREE_H

#include "Node.h"

class Tree 
{
private:
  Node *root; // Pointer to the root node of the tree

public:
  Tree( ); // Constructor for the Tree class
  ~Tree( ); // Destructor for the Tree class
  void insert(const string &); // Function to insert a new node into the tree
  virtual void preOrder( ) const; // Function to perform a pre-order traversal of the tree
  virtual void inOrder( ) const; // Function to perform an in-order traversal of the tree
  virtual void postOrder( ) const; // Function to perform a post-order traversal of the tree
  void remove(const string &); // Function to remove a node from the tree
  bool search(const string &) const; // Function to search for a node in the tree

private:
  // Add additional functions/variables here

  // Private helper function to recursively delete nodes in the tree
  void RecursiveDestructor(Node*);

  // Private helper function to perform a pre-order traversal of the tree
  void preOrder(Node*) const;

  // Private helper function to perform an in-order traversal of the tree
  void inOrder(Node*) const;

  // Private helper function to perform a post-order traversal of the tree
  void postOrder(Node*) const;

  // Private helper function to shift nodes up during removal operation
  void shiftUp(Node*);
  //Copy Constructor
  Tree(const Tree&) = delete;
  
  //Copy Assignment
  Tree& operator=(const Tree& ) = delete;
};


#endif
