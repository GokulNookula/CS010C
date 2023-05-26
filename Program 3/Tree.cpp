#include <iostream>
#include <string>
#include "Node.h"
#include "Tree.h"

using namespace std;

Tree::Tree()
{
    root = nullptr; // Initialize the root pointer to nullptr, indicating an empty tree
}

Tree::~Tree()
{
    RecursiveDestructor(root); // Call the recursive destructor function to delete all nodes in the tree
}

void Tree::RecursiveDestructor(Node* currentNode)
{
    if (currentNode != nullptr)
    {
        RecursiveDestructor(currentNode->left); // Recursively delete the left subtree
        RecursiveDestructor(currentNode->middle); // Recursively delete the middle subtree
        RecursiveDestructor(currentNode->right); // Recursively delete the right subtree
        delete currentNode; // Delete the current node
    }
}



void Tree::insert(const string &userString)
{
    if (root == nullptr)
    {
        // If the tree is empty, create a new root node and assign the userString to it
        root = new Node();
        root->small = userString;
        return;
    }
    else
    {
        Node* currentNode = root;

        // Traverse the tree to find the appropriate position for the new node
        while (currentNode->left)
        {
            if (currentNode->hasTwoStrings())
            {
                // If the current node has two strings, decide which child to follow based on the comparison with userString
                if (currentNode->small > userString)
                {
                    currentNode = currentNode->left;
                }
                else if (currentNode->large < userString)
                {
                    currentNode = currentNode->right;
                }
                else
                {
                    currentNode = currentNode->middle;
                }
            }
            else
            {
                // If the current node has only one string, decide which child to follow based on the comparison with userString
                if (currentNode->small > userString)
                {
                    currentNode = currentNode->left;
                }
                else
                {
                    currentNode = currentNode->middle;
                }
            }
        }

        if (currentNode->hasTwoStrings())
        {
            // If the current node has two strings, split it into three nodes to accommodate the new string

            string small;
            string middle;
            string large;

            // Determine the order of the three strings to be stored in the new nodes
            if (currentNode->small > userString)
            {
                small = userString;
                middle = currentNode->small;
                large = currentNode->large;
            }
            else
            {
                small = currentNode->small;

                if (currentNode->large < userString)
                {
                    middle = currentNode->large;
                    large = userString;
                }
                else
                {
                    middle = userString;
                    large = currentNode->large;
                }
            }

            // Create new nodes for the small and large strings
            Node* smallNode = new Node();
            smallNode->small = small;
            Node* largeNode = new Node();
            largeNode->small = large;

            // Update the current node with the middle string and adjust its children
            currentNode->small = middle;
            currentNode->large = "";
            currentNode->left = smallNode;
            currentNode->middle = largeNode;
            currentNode->right = nullptr;

            // Set the parent of the new nodes and adjust the tree structure
            smallNode->parent = currentNode;
            largeNode->parent = currentNode;

            shiftUp(currentNode); // Shift nodes up to maintain the tree properties
        }
        else
        {
            // If the current node has only one string, insert the new string into it
            if (currentNode->small > userString)
            {
                currentNode->large = currentNode->small;
                currentNode->small = userString;
            }
            else
            {
                currentNode->large = userString;
            }
        }
    }
}


void Tree::shiftUp(Node* currentNode)
{
    if (currentNode->parent)
    {
        Node* parentNode = currentNode->parent;

        if (parentNode->hasTwoStrings())
        {
            // If the parent node has two strings, perform the necessary shifting and reorganizing

            if (parentNode->small > currentNode->small)
            {
                // If the small string of the parent is greater than the current node's small string

                // Create a new large node and update its left and middle children
                Node* largeNode = new Node();
                largeNode->left = parentNode->middle;
                largeNode->left->parent = largeNode;
                largeNode->middle = parentNode->right;
                largeNode->middle->parent = largeNode;
                largeNode->small = parentNode->large;

                // Update the parent node with the current node and the new large node
                parentNode->left = currentNode;
                parentNode->middle = largeNode;
                parentNode->right = nullptr;
                parentNode->large = "";

                // Update the parent of the large node
                largeNode->parent = parentNode;
            }
            else if (parentNode->large < currentNode->small)
            {
                // If the large string of the parent is smaller than the current node's small string

                // Create a new small node and update its left and middle children
                Node* smallNode = new Node();
                smallNode->left = parentNode->left;
                smallNode->left->parent = smallNode;
                smallNode->middle = parentNode->middle;
                smallNode->middle->parent = smallNode;
                smallNode->small = parentNode->small;

                // Update the parent node with the new small node and the current node
                parentNode->left = smallNode;
                parentNode->middle = currentNode;
                parentNode->right = nullptr;
                parentNode->small = parentNode->large;
                parentNode->large = "";

                // Update the parent of the small node
                smallNode->parent = parentNode;
            }
            else
            {
                // If the current node's small string falls between the parent's small and large strings

                // Create a new small node and update its left and middle children
                Node* smallNode = new Node();
                smallNode->small = parentNode->small;
                smallNode->left = parentNode->left;
                smallNode->left->parent = smallNode;
                smallNode->middle = currentNode->left;
                smallNode->middle->parent = smallNode;

                // Create a new large node and update its left and middle children
                Node* largeNode = new Node();
                largeNode->small = parentNode->large;
                largeNode->left = currentNode->middle;
                largeNode->left->parent = largeNode;
                largeNode->middle = parentNode->middle;
                largeNode->middle->parent = largeNode;

                // Update the parent node with the new small node, the new large node, and adjust its strings
                parentNode->left = smallNode;
                parentNode->middle = largeNode;
                parentNode->right = nullptr;
                parentNode->small = currentNode->small;
                parentNode->large = "";

                // Update the parents of the new nodes
                smallNode->parent = parentNode;
                largeNode->parent = parentNode;

                delete currentNode; // Delete the current node since it's no longer needed
            }

            shiftUp(parentNode); // Recursively shift up the parent node
        }
        else
        {
            // If the parent node has only one string, update its strings and children accordingly

            if (parentNode->small > currentNode->small)
            {
                // If the small string of the parent is greater than the current node's small string,
                // update the parent node with the current node's small string as the new large string

                parentNode->large = parentNode->small;
                parentNode->small = currentNode->small;

                parentNode->left = currentNode->left;
                parentNode->middle = currentNode->middle;
                parentNode->right = nullptr;
            }
            else
            {
                // If the small string of the parent is smaller than the current node's small string,
                // update the parent node with the current node's small string as the new large string

                parentNode->large = currentNode->small;

                parentNode->middle = currentNode->left;
                currentNode->left->parent = parentNode;
                parentNode->right = currentNode->middle;
                currentNode->middle->parent = parentNode;
            }

            // Update the parent pointers of the children
            currentNode->left->parent = parentNode;
            currentNode->middle->parent = parentNode;

            delete currentNode; // Delete the current node since it's no longer needed
        }
    }
}



void Tree::preOrder() const
{
    preOrder(root); // Call the private preOrder function starting from the root node
}

void Tree::preOrder(Node* currentNode) const
{
    if (currentNode)
    {
        // If the current node exists

        if (currentNode->hasTwoStrings())
        {
            // If the current node has two strings

            cout << currentNode->small << ", "; // Print the small string
            preOrder(currentNode->left); // Recursively traverse the left subtree
            cout << currentNode->large << ", "; // Print the large string
            preOrder(currentNode->middle); // Recursively traverse the middle subtree
            preOrder(currentNode->right); // Recursively traverse the right subtree
        }
        else
        {
            // If the current node has only one string

            cout << currentNode->small << ", "; // Print the small string
            preOrder(currentNode->left); // Recursively traverse the left subtree
            preOrder(currentNode->middle); // Recursively traverse the middle subtree
        }
    }
}



void Tree::inOrder() const
{
    inOrder(root); // Call the private inOrder function starting from the root node
}


void Tree::inOrder(Node* currentNode) const
{
    if (currentNode)
    {
        // If the current node exists

        inOrder(currentNode->left); // Recursively traverse the left subtree
        cout << currentNode->small << ", "; // Print the small string
        inOrder(currentNode->middle); // Recursively traverse the middle subtree

        if (currentNode->hasTwoStrings())
        {
            // If the current node has two strings

            cout << currentNode->large << ", "; // Print the large string
            inOrder(currentNode->right); // Recursively traverse the right subtree
        }
    }
}


void Tree::postOrder() const
{
    postOrder(root); // Call the private postOrder function starting from the root node
}

void Tree::postOrder(Node* currentNode) const
{
    if (currentNode)
    {
        // If the current node exists

        if (currentNode->hasTwoStrings())
        {
            // If the current node has two strings

            postOrder(currentNode->left); // Recursively traverse the left subtree
            postOrder(currentNode->middle); // Recursively traverse the middle subtree
            cout << currentNode->small << ", "; // Print the small string
            postOrder(currentNode->right); // Recursively traverse the right subtree
            cout << currentNode->large << ", "; // Print the large string

        }
        else
        {
            // If the current node has only one string

            postOrder(currentNode->left); // Recursively traverse the left subtree
            postOrder(currentNode->middle); // Recursively traverse the middle subtree
            cout << currentNode->small << ", "; // Print the small string
        }
    }
}


bool Tree::search(const string &userString) const
{
    Node* currentNode = root; // Start the search from the root node

    while (currentNode)
    {
        // While there are nodes to search

        if (currentNode->small == userString || (currentNode->hasTwoStrings() && currentNode->large == userString))
        {
            // If the current node's small string matches the user string
            // OR if the current node has two strings and the large string matches the user string
            // Return true to indicate a successful search

            return true;
        }
        else
        {
            if (currentNode->small > userString)
            {
                // If the user string is smaller than the current node's small string
                // Move to the left subtree

                currentNode = currentNode->left;
            }
            else
            {
                if (currentNode->hasTwoStrings() && currentNode->large < userString)
                {
                    // If the user string is larger than the current node's large string (in a node with two strings)
                    // Move to the right subtree

                    currentNode = currentNode->right;
                }
                else
                {
                    // Otherwise, the user string falls between the small and large strings (in a node with two strings)
                    // Move to the middle subtree

                    currentNode = currentNode->middle;
                }
            }
        }
    }
    // If the search reaches this point, the user string was not found in the tree
    // Return false to indicate an unsuccessful search

    return false;
}


void Tree::remove(const string &userString)
{
    Node* currentNode = root;
    while (currentNode)
    {
        // Traverse the tree to find the node containing the user string

        if (currentNode->small == userString || (currentNode->hasTwoStrings() && currentNode->large == userString))
        {
            // If the current node contains the user string, break the loop and proceed with removal

            break;
        }
        else
        {
            if (currentNode->small > userString)
            {
                currentNode = currentNode->left;
            }
            else
            {
                if (currentNode->hasTwoStrings() && currentNode->large < userString)
                {
                    currentNode = currentNode->right;
                }
                else
                {
                    currentNode = currentNode->middle;
                }
            }
        }
    }

    if (currentNode->hasTwoStrings())
    {
        // If the current node has two strings

        if (userString == currentNode->small)
        {
            // If the user string matches the small string in the current node
            // Remove the small string by swapping it with the large string

            currentNode->small = currentNode->large;
            currentNode->large = "";
        }
        else
        {
            // If the user string matches the large string in the current node
            // Simply remove the large string by setting it to an empty string

            currentNode->large = "";
        }
    }
    else
    {
        // If the current node has only one string

        Node* parentNode = currentNode->parent;
        if (parentNode)
        {
            // If the current node has a parent

            if (parentNode->small > userString)
            {
                // If the user string is smaller than the small string in the parent node
                // Remove the current node by setting the left subtree of the parent to nullptr
                // Update the parent's large string to the small string in the middle subtree
                // Set the middle subtree of the parent to nullptr

                parentNode->left = nullptr;
                parentNode->large = parentNode->middle->small;
                parentNode->middle = nullptr;
            }
            else
            {
                // If the user string is larger than or equal to the small string in the parent node
                // Remove the current node by setting the middle subtree of the parent to nullptr
                // Update the parent's large string to the small string in the left subtree
                // Set the small string in the parent to the small string in the left subtree
                // Set the left subtree of the parent to nullptr

                parentNode->middle = nullptr;
                parentNode->large = parentNode->small;
                parentNode->small = parentNode->left->small;
                parentNode->left = nullptr;
            }
        }
        else
        {
            // If the current node is the root node (no parent)

            Node* insertNode = new Node();
            if (root->left)
            {
                // If the root has a left subtree
                // Set the insertNode's small string to the small string in the left subtree
                // Set the insertNode's large string to the small string in the middle subtree
                // Set the root to the insertNode

                insertNode->small = root->left->small;
                insertNode->large = root->middle->small;
                root = insertNode;
            }
            else
            {
                // If the root has no left subtree
                // Set the root to nullptr (empty tree)

                root = nullptr;
            }
        }
    }
}
