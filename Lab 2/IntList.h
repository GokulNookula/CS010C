#ifndef INTLIST_H
#define INTLIST_H

#include <iostream>
#include <ostream>
#include <string>

using namespace std;

struct IntNode {
    int data;           // the integer value stored in this node
    IntNode *prev;      // pointer to the previous node in the list
    IntNode *next;      // pointer to the next node in the list
    IntNode(int data) : data(data), prev(0), next(0) {}
    // constructor to initialize the data and pointers
};

class IntList
{
    public:
        IntList();              // constructor to create an empty list
        ~IntList();             // destructor to free memory allocated by the list
        void push_front(int);   // add a node to the front of the list
        void pop_front();       // remove the front node from the list
        void push_back(int);    // add a node to the back of the list
        void pop_back();        // remove the back node from the list
        bool empty() const;     // check if the list is empty
        friend ostream & operator<<(ostream &out, const IntList &rhs);
        // overload the output operator to print the list
        void printReverse() const;
        // print the list in reverse order

    private:
        IntNode* dummyHead;     // dummy node representing the head of the list
        IntNode* dummyTail;     // dummy node representing the tail of the list
};


#endif
