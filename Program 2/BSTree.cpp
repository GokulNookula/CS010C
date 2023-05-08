#include <iostream>
#include <string>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree()
{
    root = nullptr;
}

BSTree::~BSTree()
{
    delete root;
}

void BSTree::insert(const string &newString)
{
    Node* newNode = new Node(newString);
    //empty tree check case
    if (root == nullptr)
    {
        root = newNode;
    }
    else
    {
        Node* currentNode = root;
        while(currentNode != nullptr)
        {
            if (newString < currentNode->data)
            {
                if (currentNode->left == nullptr)
                {
                    currentNode->left = newNode;
                    newNode->parent = currentNode;
                    currentNode->add();
                    currentNode = nullptr;
                }
                else if (currentNode->left->data == newString)
                {
                    currentNode->add();
                    currentNode = nullptr;
                }
                else
                {
                    currentNode = currentNode->left;
                }
            }
            else
            {
                if (currentNode->right == nullptr)
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = newNode;
                        newNode->parent = currentNode;
                        currentNode->add();
                        currentNode = nullptr;
                    }
                    else if (currentNode->right->data == newString)
                    {
                        currentNode->add();
                        currentNode = nullptr;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
            }
        }
    }

}

void BSTree::remove(const string &key)
{

}

bool BSTree::search(const string &key) const
{
    if (searchRecursive(root,key) != nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Node* BSTree::searchRecursive(Node* currentNode, const string& key) const
{
    if (currentNode)
    {
        if (currentNode->data == key)
        {
            return currentNode;
        }
        else
        {
            if (key < currentNode->data)
            {
                return searchRecursive(currentNode->left,key);
            }
            else if (key > currentNode->data)
            {
                return searchRecursive(currentNode->right, key);
            }
            else
            {
                return nullptr;
            }
        }
    }
    else
    {
        return nullptr;
    }
}

string BSTree::largest() const
{
    Node* currentNode = root;
    string maxVal;

    if (currentNode == nullptr)
    {
        maxVal = "";
    }
    else
    {
        maxVal = currentNode->data;

        while (currentNode != nullptr)
        {
            if (currentNode->data > maxVal)
            {
                maxVal = currentNode->data;
            }
            currentNode = currentNode->left;
        }
    }
    return maxVal;
}

string BSTree::smallest() const
{
    Node* currentNode = root;
    string minVal;

    if (currentNode == nullptr)
    {
        minVal = "";
    }
    else
    {
        minVal = currentNode->data;

        while (currentNode != nullptr)
        {
            if (currentNode->data < minVal)
            {
                minVal = currentNode->data;
            }
            currentNode = currentNode->left;
        }
    }
    return minVal;
}

int BSTree::height(const string& key) const
{
    Node* currentNode = new Node(key);
    return HeightHelper(currentNode);
}

int BSTree::HeightHelper(Node* curr) const
{
    if (curr == nullptr)
    {
        return -1;
    }
    else
    {
        int leftHeight = HeightHelper(curr->left);
        int rightHeight = HeightHelper(curr->right);

        if (leftHeight > rightHeight)
        {
            return (leftHeight + 1);
        }
        else
        {
            return (rightHeight + 1);
        }
    }
}
