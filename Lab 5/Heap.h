#ifndef __HEAP_H
#define __HEAP_H

#include <iostream>
#include <cstdlib>
#include "PrintJob.h"

using namespace std;

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  //current number of items in heap

public:
  /*Initializes an empty heap.*/
  Heap();

  ~Heap();

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue(PrintJob*);

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void dequeue();

  /*Returns the node with highest priority.*/
  PrintJob* highest() const;

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void print() const;

private:
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void trickleDown(int);
  /*
  The trickleUp() function is used in a binary heap data structure to
  move a newly added element up the tree until it is in its correct
  position relative to the other elements in the heap.
  */
  void trickleUp(int);
  
};
#endif
