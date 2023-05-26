#include <iostream>
#include <string>
#include <fstream>
#include "AVLTree.h"

using namespace std;

AVLTree::AVLTree() 
{
  // Initialize the root of the tree to null.
  root = nullptr;
}

AVLTree::~AVLTree() 
{
  // Recursively delete all nodes in the tree.
  RecursiveDeleteAVLTree(root);
}

void AVLTree::RecursiveDeleteAVLTree(Node* currentNode) 
{
  // Check if the current node is null.
  if (currentNode == nullptr) 
  {
    // If it is, do nothing.
    return;
  }

  // Recursively delete the left subtree.
  RecursiveDeleteAVLTree(currentNode->left);

  // Recursively delete the right subtree.
  RecursiveDeleteAVLTree(currentNode->right);

  // Delete the current node.
  delete currentNode;
}

void AVLTree::insert(const string& target)
{
  // Create a new node to insert
  Node* insertNode = new Node(target);

  // Initialize currentNode to root
  Node* currentNode = root;

  // If the tree is empty, make the new node the root
  if (root == nullptr)
  {
    root = insertNode;
    insertNode->parent = nullptr;
    return;
  }

  // Find the appropriate position to insert the new node
  while (currentNode != nullptr)
  {
    // Traverse left if the current node's key is greater than the target
    if (currentNode->key > target)
    {
      currentNode = currentNode->left;
    }
    // Traverse right if the current node's key is less than the target
    else if (currentNode->key < target)
    {
      currentNode = currentNode->right;
    }
    // If the key is equal, the target already exists in the tree, so we return
    else
    {
      return;
    }
  }

  // Reset currentNode to root
  currentNode = root;

  // Find the appropriate parent node to attach the new node
  while (currentNode != nullptr)
  {
    // Traverse left if the current node's key is greater than the target
    if (currentNode->key > target)
    {
      // Attach the new node as the left child if the left child is nullptr
      if (currentNode->left == nullptr)
      {
        currentNode->left = insertNode;
        insertNode->parent = currentNode;
        currentNode = nullptr;
      }
      else
      {
        currentNode = currentNode->left;
      }
    }
    // Traverse right if the current node's key is less than or equal to the target
    else
    {
      // Attach the new node as the right child if the right child is nullptr
      if (currentNode->right == nullptr)
      {
        currentNode->right = insertNode;
        insertNode->parent = currentNode;
        currentNode = nullptr;
      }
      else
      {
        currentNode = currentNode->right;
      }
    }
  }

  // Start rebalancing the tree by performing rotations
  insertNode = insertNode->parent;
  while(insertNode != nullptr)
  {
    rotate(insertNode);
    insertNode = insertNode->parent;
  }
}

void AVLTree::visualizeTree(const string &outputFilename)
{
  // Open the output file for writing
  ofstream outFS(outputFilename.c_str());
  
  // Check if the file opened successfully
  if (!outFS.is_open())
  {
    cout << "Error" << endl;
    return;
  }

  // Write the initial part of the DOT language representation for the graph
  outFS << "digraph G {" << endl;

  // Call the helper function to recursively visualize the tree
  visualizeTree(outFS, root);

  // Write the closing part of the DOT language representation for the graph
  outFS << "}";

  // Close the output file
  outFS.close();

  // Generate the JPG file from the DOT file using the 'dot' command
  string jpgFilename = outputFilename.substr(0, outputFilename.size() - 4) + ".jpg";
  string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
  system(command.c_str());
}

void AVLTree::visualizeTree(ofstream& outFS, Node* n)
{
  if (n)
  {
    // Recursively visualize the left subtree
    if (n->left)
    {
      visualizeTree(outFS, n->left);
      outFS << n->key << " -> " << n->left->key << ";" << endl;
    }

    // Recursively visualize the right subtree
    if (n->right)
    {
      visualizeTree(outFS, n->right);
      outFS << n->key << " -> " << n->right->key << ";" << endl;
    }
  }
}

int AVLTree::balanceFactor(Node* currentNode) const
{
  // Initialize the heights of the left and right subtrees
  int leftHeight = -1;
  int rightHeight = -1;

  // Check if the left child exists and update its height
  if (currentNode->left != nullptr)
  {
    leftHeight = currentNode->left->height;
  }

  // Check if the right child exists and update its height
  if (currentNode->right != nullptr)
  {
    rightHeight = currentNode->right->height;
  }

  // Return the difference in heights between the left and right subtrees
  return leftHeight - rightHeight;
}

void AVLTree::printBalanceFactors() const
{
  // Call the helper function to print the balance factors starting from the root
  printBalanceFactors(root);

  // Print a new line at the end for formatting
  cout << endl;
}

void AVLTree::printBalanceFactors(Node* currentNode) const
{
  if (currentNode != nullptr)
  {
    // Recursively traverse the left subtree
    printBalanceFactors(currentNode->left);

    // Print the key and its balance factor
    cout << currentNode->key << "(" << balanceFactor(currentNode) << "), ";

    // Recursively traverse the right subtree
    printBalanceFactors(currentNode->right);
  }
}

void AVLTree::rotate(Node* currentNode)
{
  // Update the height of the current node
  updateHeight(currentNode);

  // Perform a rotation if the balance factor indicates an imbalance
  if (balanceFactor(currentNode) == -2)
  {
    // Right-Right case
    if (balanceFactor(currentNode->right) == 1)
    {
      // Perform a right rotation on the right child
      rotateRight(currentNode->right);
    }

    // Perform a left rotation on the current node
    rotateLeft(currentNode);
  }
  else if (balanceFactor(currentNode) == 2)
  {
    // Left-Left case
    if (balanceFactor(currentNode->left) == -1)
    {
      // Perform a left rotation on the left child
      rotateLeft(currentNode->left);
    }

    // Perform a right rotation on the current node
    rotateRight(currentNode);
  }
}

void AVLTree::rotateRight(Node* currentNode)
{
  // Store the right child of the left child
  Node* leftRightChild = currentNode->left->right;

  // Check if the current node has a parent
  if (currentNode->parent != nullptr)
  {
    // Replace the current node with its left child in the parent's children
    replaceChild(currentNode->parent, currentNode, currentNode->left);
  }
  else
  {
    // The current node is the root, update the root to be the left child
    root = currentNode->left;
    root->parent = nullptr;
  }

  // Set the left child's right child as the current node
  setChild(currentNode->left, "right", currentNode);

  // Set the current node's left child as the leftRightChild
  setChild(currentNode, "left", leftRightChild);
}

void AVLTree::rotateLeft(Node* currentNode)
{
  // Store the left child of the right child
  Node* rightLeftChild = currentNode->right->left;

  // Check if the current node has a parent
  if (currentNode->parent != nullptr)
  {
    // Replace the current node with its right child in the parent's children
    replaceChild(currentNode->parent, currentNode, currentNode->right);
  }
  else
  {
    // The current node is the root, update the root to be the right child
    root = currentNode->right;
    root->parent = nullptr;
  }

  // Set the right child's left child as the current node
  setChild(currentNode->right, "left", currentNode);

  // Set the current node's right child as the rightLeftChild
  setChild(currentNode, "right", rightLeftChild);
}

bool AVLTree::setChild(Node* currentNode, string whichChild, Node* child)
{
  // Check if the child position is valid
  if (whichChild != "left" && whichChild != "right")
  {
    return false;
  }

  // Set the child based on the position
  if (whichChild == "left")
  {
    currentNode->left = child;
  }
  else
  {
    currentNode->right = child;
  }

  // Update the parent-child relationship
  if (child != nullptr)
  {
    child->parent = currentNode;
  }

  // Update the height of the current node
  updateHeight(currentNode);

  return true;
}

bool AVLTree::replaceChild(Node* currentNode, Node* givenChild, Node* insertChild)
{
  // Check if the givenChild is the left child of the currentNode
  if (currentNode->left == givenChild)
  {
    // Call setChild to replace the left child with the insertChild
    return setChild(currentNode, "left", insertChild);
  }
  // Check if the givenChild is the right child of the currentNode
  else if (currentNode->right == givenChild)
  {
    // Call setChild to replace the right child with the insertChild
    return setChild(currentNode, "right", insertChild);
  }
  // No matching child found, return false
  return false;
}

void AVLTree::updateHeight(Node* currentNode)
{
  // Initialize the heights of the left and right subtrees
  int leftHeight = -1;
  int rightHeight = -1;

  // Check if the left child exists and update its height
  if (currentNode->left != nullptr)
  {
    leftHeight = currentNode->left->height;
  }

  // Check if the right child exists and update its height
  if (currentNode->right != nullptr)
  {
    rightHeight = currentNode->right->height;
  }

  // Update the height of the current node based on the maximum height of its children
  currentNode->height = max(leftHeight, rightHeight) + 1;
}
