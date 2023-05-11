#include <iostream>
#include <cstdlib>
#include "Heap.h"
#include "PrintJob.h"

using namespace std;

// Constructor for the Heap class
Heap::Heap()
{
    // Set the number of items to zero
    numItems = 0;
    
    // Set the first element of the array to null
    arr[0] = nullptr;
}

// Destructor for the Heap class
Heap::~Heap()
{
    // Set the number of items to zero
    numItems = 0;
}

// Method to insert a new PrintJob into the heap
void Heap::enqueue(PrintJob* insertNode)
{
    // If the heap is full, return without inserting the new node
    if (numItems >= MAX_HEAP_SIZE)
    {
        return;
    }

    // Increment the number of items in the heap
    numItems++;

    // Add the new node to the end of the heap array
    arr[numItems - 1] = insertNode;

    // Move the new node up the heap until it is in the correct position
    trickleUp(numItems - 1);

    // Return after the new node has been added to the heap
    return;
}


// Method to remove the highest priority PrintJob from the heap
void Heap::dequeue()
{
    // If there are no items in the heap, return without doing anything
    if (numItems == 0)
    {
        return;
    }

    // Replace the root node with the last node in the heap array
    arr[0] = arr[numItems - 1];

    // Decrement the number of items in the heap
    numItems--;

    // Move the new root node down the heap until it is in the correct position
    trickleDown(0);
}

// Method to get a pointer to the highest priority PrintJob in the heap
PrintJob* Heap::highest() const
{
    // If there are no items in the heap, return null
    if (numItems == 0)
    {
        return nullptr;
    }

    // Return a pointer to the root node, which has the highest priority
    return (arr[0]);
}

// Method to print information about the highest priority PrintJob in the heap
void Heap::print() const
{
    // If there are no items in the heap, return without doing anything
    if (numItems == 0)
    {
        return;
    }

    // Get a pointer to the highest priority PrintJob
    PrintJob* highestNode = highest();

    // Print information about the highest priority PrintJob
    cout << "Priority: " << highestNode->getPriority() << ", ";
    cout << "Job Number: " << highestNode->getJobNumber() << ", ";
    cout << "Number of Pages: " << highestNode->getPages() << endl;
}

// Recursive method to move a node up the heap until it is in the correct position
void Heap::trickleUp(int index)
{
    // If the node is already at the root of the heap, return without doing anything
    if (index == 0)
    {
        return;
    }
    // If the parent node has lower priority than the current node, swap them and continue recursively
    else if (arr[(index - 1)/2]->getPriority() < arr[index]->getPriority())
    {
        swap(arr[index], arr[(index - 1)/2]);
        trickleUp((index - 1)/2);
    }
    // Otherwise, the node is in the correct position, so return without doing anything
    else
    {
        return;
    }
}

void Heap::trickleDown(int index)
{
    // If the index is greater than 3, we don't need to perform any further operations.
    if (index > 3)
    {
        return;
    }

    // Calculate the indices of the left and right children.
    int leftIndex = (index * 2) + 1;
    int rightIndex = (index * 2) + 2;

    // If the number of items is greater than the left and right indices, we need to compare the priorities of the parent node with its children.
    if (numItems > leftIndex && numItems > rightIndex)
    {
        // If the priority of the parent node is less than one of its children, we need to swap the parent node with the child that has the higher priority.
        if (arr[index]->getPriority() < arr[leftIndex]->getPriority() || arr[index]->getPriority() < arr[rightIndex]->getPriority())
        {
            // If the left child has a higher priority, swap the parent node with the left child and call trickleDown recursively on the left child's index.
            if (arr[leftIndex]->getPriority() > arr[rightIndex]->getPriority())
            {
                swap(arr[index],arr[leftIndex]);
                trickleDown(leftIndex);
            }
            // Otherwise, swap the parent node with the right child and call trickleDown recursively on the right child's index.
            else
            {
                swap(arr[index],arr[rightIndex]);
                trickleDown(rightIndex);
            }
        }
    }
    // If the number of items is greater than the left index but not the right index, we only need to swap the parent node with the left child.
    else if (numItems > leftIndex)
    {
        swap(arr[index],arr[rightIndex]);
    }
}
