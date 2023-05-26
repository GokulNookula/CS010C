#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class AVLTree 
{
  public:
    // Constructor
    AVLTree();

    // Destructor
    ~AVLTree();

    // Insert a new node into the tree.
    void insert(const string& key);

    // Get the balance factor of a node.
    int balanceFactor(Node* node) const;

    // Print the balance factors of all nodes in the tree.
    void printBalanceFactors() const;

    // Visualize the tree as a text file.
    void visualizeTree(const string& outputFilename);

  private:
    // The root of the tree.
    Node* root;

    // Recursively delete all nodes in the tree.
    void RecursiveDeleteAVLTree(Node* node);

    // Update the height of a node.
    void updateHeight(Node* node);

    // Set the child of a node.
    bool setChild(Node* node, string whichChild, Node* child);

    // Replace the child of a node.
    bool replaceChild(Node* node, Node* givenChild, Node* insertChild);

    // Rotate a node.
    void rotate(Node* node);

    // Rotate a node to the left.
    void rotateLeft(Node* node);

    // Rotate a node to the right.
    void rotateRight(Node* node);

    // Print the balance factors of a subtree.
    void printBalanceFactors(Node* node) const;

    // Visualize a subtree as a text file.
    void visualizeTree(ofstream& outFS, Node* n);
    //Copy Constructor
    AVLTree(const AVLTree&) = delete;
    
    //Copy Assignment
    AVLTree& operator=(const AVLTree& ) = delete;
};


#endif
