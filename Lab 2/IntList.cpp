#include <iostream>
#include <ostream>
#include <string>
#include "IntList.h"

using namespace std;

// IntList::IntList()
// Constructor for the IntList class.
// Initializes the dummy head and dummy tail nodes.
// The dummy head node points to the dummy tail node,
// and the dummy tail node points to the dummy head node.
IntList::IntList()
{
    // Create a new dummy head node.
    dummyHead = new IntNode(0);

    // Create a new dummy tail node.
    dummyTail = new IntNode(0);

    // Set the next pointer of the dummy head node to the dummy tail node.
    dummyHead->next = dummyTail;

    // Set the prev pointer of the dummy tail node to the dummy head node.
    dummyTail->prev = dummyHead;
}

// IntList::~IntList()
// Destructor for the IntList class.
// Iterates through the list and deletes all of the nodes.
// Finally, it deletes the dummy head and dummy tail nodes.
IntList::~IntList()
{
    // While the list is not empty,
    while (!empty())
    {
        // Pop the front element off of the list.
        pop_front();
    }

    // Delete the dummy head node.
    delete dummyHead;

    // Delete the dummy tail node.
    delete dummyTail;
}

// void IntList::push_front(int value)
// Method to add an element to the front of the list.
// Creates a new node with the given value,
// and inserts it in front of the dummy head node.
void IntList::push_front(int value)
{
    // Create a new node with the given value.
    IntNode* userNode = new IntNode(value);

    // Set the next pointer of the new node to the next pointer of the dummy head node.
    userNode->next = dummyHead->next;

    // Set the prev pointer of the new node to the dummy head node.
    userNode->prev = dummyHead;

    // Set the next pointer of the dummy head node to the new node.
    dummyHead->next = userNode;

    // Set the prev pointer of the new node's next node to the new node.
    userNode->next->prev = userNode;
}


// void IntList::pop_front()
// Method to remove the first element from the list.
// If the list is empty, it does nothing.
void IntList::pop_front()
{
    // Check if the list is empty.
    if (dummyHead == nullptr)
    {
        // If the list is empty, do nothing.
        return;
    }

    // Create a temporary pointer to the first node in the list.
    IntNode* temp = dummyHead->next;

    // Set the next pointer of the dummy head node to the second node in the list.
    dummyHead->next = temp->next;

    // Set the prev pointer of the second node in the list to the dummy head node.
    temp->next->prev = dummyHead;

    // Set the next and prev pointers of the temporary node to nullptr.
    temp->next = temp->prev = nullptr;

    // Delete the temporary node.
    delete temp;
}

// void IntList::push_back(int value)
// Method to add an element to the end of the list.
// Creates a new node with the given value,
// and inserts it after the dummy tail node.
void IntList::push_back(int value)
{
    // Create a new node with the given value.
    IntNode* userNode = new IntNode(value);

    // If the list is empty, set the dummy head and dummy tail nodes to the new node.
    if (dummyHead->next == dummyTail)
    {
        dummyHead->next = userNode;
    }

    // Set the prev pointer of the new node to the dummy tail node.
    userNode->prev = dummyTail->prev;

    // Set the next pointer of the dummy tail node's prev node to the new node.
    dummyTail->prev->next = userNode;

    // Set the prev pointer of the dummy tail node to the new node.
    dummyTail->prev = userNode;

    // Set the next pointer of the new node to the dummy tail node.
    userNode->next = dummyTail;
}

// void IntList::pop_back()
// Method to remove the last element from the list.
// If the list is empty, it does nothing.
void IntList::pop_back()
{
    // Check if the list is empty.
    if (dummyTail == nullptr)
    {
        // If the list is empty, do nothing.
        return;
    }

    // Create a temporary pointer to the last node in the list.
    IntNode* temp = dummyTail;

    // Set the prev pointer of the dummy tail node to the second to last node in the list.
    dummyTail = dummyTail->prev;

    // Set the next pointer of the second to last node in the list to nullptr.
    dummyTail->next = nullptr;

    // Delete the temporary node.
    delete temp;
}

// bool IntList::empty() const
// Method to check if the list is empty.
// Returns true if the list is empty, false otherwise.
bool IntList::empty() const
{
    // Check if the dummy head node's next pointer is the dummy tail node.
    // If it is, the list is empty.
    if (dummyHead->next == dummyTail)
    {
        return true;
    }

    // Otherwise, the list is not empty.
    return false;
}

// ostream & operator<<(ostream &out, const IntList &rhs)
// Overloaded operator<< for the IntList class.
// Prints the list to the given output stream.
ostream & operator<<(ostream &out, const IntList &rhs)
{
    // Iterate through the list, printing each node's data to the output stream.
    for (IntNode* currentNode = rhs.dummyHead->next; currentNode != rhs.dummyTail; currentNode = currentNode->next)
    {
        out << currentNode->data;

        // If the current node is not the last node in the list, print a space.
        if (currentNode->next != rhs.dummyTail)
        {
            out << " ";
        }
    }

    // Return the output stream.
    return out;
}

// void IntList::printReverse() const
// Method to print the list in reverse order.
void IntList::printReverse() const
{
    // Iterate through the list, printing each node's data to the console in reverse order.
    for (IntNode* currentNode = dummyTail->prev; currentNode != dummyHead; currentNode = currentNode->prev)
    {
        cout << currentNode->data;

        // If the current node is not the first node in the list, print a space.
        if (currentNode->prev != dummyHead)
        {
            cout << " ";
        }
    }
}
