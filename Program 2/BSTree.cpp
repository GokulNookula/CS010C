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
    RemoveBSTree(root);
}

void BSTree::RemoveBSTree(Node* victimNode)
{
    if(victimNode != nullptr)
    {
        if (victimNode->left != nullptr)
        {
            RemoveBSTree(victimNode->left);
        }
        if (victimNode->right != nullptr)
        {
            RemoveBSTree(victimNode->right);
        }
        delete victimNode;
    }
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
    if (root == nullptr)
    {
        return;
    }

    Node* victimNode = searchRecursive(root, key);
    if (victimNode == nullptr)
    {
        return;
    }

    if (victimNode->count > 1)
    {
        victimNode->count--;
        return;
    }

    if (victimNode->left == nullptr && victimNode->right == nullptr)
    {
        if (victimNode->parent == nullptr)
        {
            root = nullptr;
        }
        else if (victimNode->parent->left = victimNode)
        {
            victimNode->parent->left = nullptr;
        }
        else
        {
            victimNode->parent->right = nullptr;
        }
        delete victimNode;
        victimNode = nullptr;
    }
    else if (victimNode->right == nullptr)
    {
        if (victimNode->right == nullptr)
        {
            if (victimNode->parent == root)
            {
                root == victimNode->right;
            }
            else if (victimNode->parent->right == victimNode)
            {
                victimNode->parent->left = victimNode->left;
            }
            else
            {
                victimNode->parent->right = victimNode->left;
            }
            delete victimNode;
            victimNode = nullptr;
        }
    }
    else if (victimNode->left == nullptr)
    {
        if (victimNode->parent == nullptr)
        {
            root = victimNode->right;
        }
        else if (victimNode->parent->left == victimNode)
        {
            victimNode->parent->left = victimNode->right;
        }
        else
        {
            victimNode->parent->right = victimNode->right;
        }
        delete victimNode;
        victimNode = nullptr;
    }
    else
    {
        Node* successorNode = victimNode->right;
        while (successorNode->left != nullptr)
        {
            successorNode = successorNode->left;
        }
        string successorData = successorNode->data;
        int successorCount = successorNode->count;
        successorNode->count = 1;
        remove(successorData);
        victimNode->data = successorData;
        victimNode->cont = successorCount;
        return;
    }
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

void BSTree::preOrder() const
{
    preOrder(root);
    cout << endl;

}

void BSTree::preOrder(Node* currentNode) const
{
    cout << currentNode->data << "(" << currentNode->count << ")" << endl;
    preOrder(currentNode->left);
    preOrder(currentNode->right);
}

void BSTree::postOrder() const
{
    postOrder(root);
    cout << endl;
}

void BSTree::postOrder(Node* currentNode) const
{
    postOrder(currentNode->left);
    postOrder(currentNode->right);
    cout << currentNode->data << "(" << currentNode->count << ")" << endl;
}

void BSTree::inOrder() const
{
    inOrder(root);
    cout << endl;
}

void BSTree::inOrder(Node* currentNode) const
{
    inOrder(currentNode->left);
    cout << currentNode->data << "(" << currentNode->count << ")" << endl;
    inOrder(currentNode->right);
}
