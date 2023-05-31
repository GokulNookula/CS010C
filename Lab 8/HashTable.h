#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <list>
#include <iostream>
#include "WordEntry.h"

using namespace std;

class HashTable 
{
private:
    list<WordEntry> *hashTable;  // Pointer to an array of linked lists
    int size;  // Size of the hash table

public:
    // Constructor
    HashTable(int);

    // Public member functions
    bool contains(const string &);
    double getAverage(const string &);
    void put(const string &, int);
 
private:
    // Private member functions
    int computeHash(const string &) const;
    // Destructor (marked as "delete" to prevent accidental deletion)
    // ~HashTable() = delete;
  	//Copy Constructor
  	HashTable(const HashTable&) = delete;
  	//Copy Assignment
  	HashTable& operator=(const HashTable& ) = delete;
};

#endif
