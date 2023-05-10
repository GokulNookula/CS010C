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
        RemoveBSTree(victimNode->left);
        RemoveBSTree(victimNode->right);
        delete victimNode;
    }
}

void BSTree::insert(const string &newString)
{
    Node* insertNode = new Node(newString);

    if (root == nullptr)
    {
        root = insertNode;
        insertNode->parent = nullptr;
        return;
    }

    Node* currentNode = root;
    while (currentNode != nullptr)
    {
        if (newString < currentNode->data)
        {
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
        else if (newString > currentNode->data)
        {
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
        else
        {
            currentNode->count += 1;
            return;
        }
    }
}

void BSTree::remove(const string& value)
{
    Node* parentNode = nullptr;
    Node *currentNode = root;

    if (!search(value)) 
    {
        return;
    }
    while (currentNode != nullptr)
    {
        if (currentNode->data == value)
        {
            if (currentNode->count > 1) 
            {
                currentNode->count -= 1;
            }
            else if ((currentNode->left == nullptr) && (currentNode->right == nullptr))
            {
                if (parentNode == nullptr)
                {
                    root = nullptr;
                }
                else if (parentNode->left == currentNode)
                {
                    parentNode->left = nullptr;
                }
                else
                {
                    parentNode->right = nullptr;
                }
            }
            else if (currentNode->left == nullptr)
            {
                if (parentNode == nullptr)
                {
                    root = currentNode->right;
                }
                else
                {
                    Node* sucessorNode = currentNode->right;
                    while (sucessorNode->left != nullptr)
                    {
                        sucessorNode = sucessorNode->left;
                    }
                    string removeData = sucessorNode->data;
                    remove(removeData);
                    currentNode->data = removeData;
                }
            }
            else
            {
                Node* sucessorNode = currentNode->left;
                while(sucessorNode->right != nullptr)
                {
                    sucessorNode = sucessorNode->right;
                }
                string removeData = sucessorNode->data;
                remove(removeData);
                currentNode->data = removeData;
            }
            return;
        }
        else if (currentNode->data < value)
        {
            parentNode = currentNode;
            currentNode = currentNode->right;
        }
        else
        {
            parentNode = currentNode;
            currentNode = currentNode->left;
        }
    }
    return;
    
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
            currentNode = currentNode->right;
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
    Node* currentNode = searchRecursive(root,key);
    if (currentNode == nullptr)
    {
        return -1;
    }
    else
    {
        return HeightHelper(currentNode);
    }
}

int BSTree::HeightHelper(Node* curr) const
{
    if (curr == nullptr)
    {
        return -1;
    }
    int leftHeight = HeightHelper(curr->left);
    int rightHeight = HeightHelper(curr->right);
    return 1 + max(leftHeight,rightHeight); 
}

void BSTree::preOrder() const
{
    preOrder(root);

}

void BSTree::preOrder(Node* currentNode) const
{
    if (currentNode != nullptr)
    {
        cout << currentNode->data << "(" << currentNode->count << "), ";
        preOrder(currentNode->left);
        preOrder(currentNode->right);
    }
}

void BSTree::postOrder() const
{
    postOrder(root);
}

void BSTree::postOrder(Node* currentNode) const
{
    if (currentNode != nullptr)
    {
        postOrder(currentNode->left);
        postOrder(currentNode->right);
        cout << currentNode->data << "(" << currentNode->count << "), ";
    }
}

void BSTree::inOrder() const
{
    inOrder(root);
}

void BSTree::inOrder(Node* currentNode) const
{
    if (currentNode != nullptr)
    {
        inOrder(currentNode->left);
        cout << currentNode->data << "(" << currentNode->count << "), ";
        inOrder(currentNode->right);
    }
}
