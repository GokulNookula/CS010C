#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned minIndex = index;

    for (unsigned int i = index + 1; i < vals.size(); i++)
    {
        if (vals.at(i) < vals.at(minIndex))
        {
            minIndex = i;
        }
    }
    return minIndex;
}

template <typename T>
void selection_sort (vector<T> &vals)
{
    for (unsigned int i = 0; i < vals.size(); i++)
    {

        swap (vals.at(i),vals.at(min_index(vals,i)));

    }
}

template <typename T>

T getElement(vector<T> vals, int index)
{
    unsigned int i = index;

    if (index < 0 || i > vals.size())
    {
        throw out_of_range("out of range exception occured");
    }
    return i;
}

vector<char> createVector()
{
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main()
{
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0)
    {
        cout << "Enter a number: " << endl;
        cin >> index;
        try
        {
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch(const out_of_range& excpt)
        {
            cout << excpt.what() << endl;
        }
    
    }
    return 0;
}
