#include <iostream>
#include <ostream>
#include <string>
#include "IntList.h"

using namespace std;

int main()
{
    //Creating a list
    IntList list;
    cout << "Initial List: " << list << endl; // should print an empty line

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);
    cout << "List after push_front: " << list << endl; // should print "1 2 3"

    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    cout << "List after push_back: " << list << endl; // should print "1 2 3 4 5 6"

    list.pop_front();
    list.pop_front();
    list.pop_front();
    cout << "List after pop_front: " << list << endl; // should print "4 5 6"

    list.pop_back();
    list.pop_back();
    list.pop_back();
    cout << "List after pop_back: " << list << endl; // should print an empty line

    cout << "Is the list empty? " << (list.empty() ? "Yes" : "No") << endl; // should print "Yes"

    list.push_front(1);
    list.push_back(3);
    cout << "List after push_front and push_back: " << list << endl; // should print "1 3"

    cout << "List in reverse: ";
    list.printReverse(); // should print "3 1"


    return 0;
}
