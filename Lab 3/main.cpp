#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned minIndex = index;

    for (auto i = index + 1; i < vals.size(); i++)
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
    for (auto i = 0; i < vals.size(); i++)
    {

        swap (vals.at(i),vals.at(min_index(vals,i)));

    }
}

template <typename T>

T getElement(vector<T> vals, int index)
{
    T i = index;

    if (index < 0 || i > vals.size())
    {
        throw out_of_range("out of range exception occured");
    }
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
    vector<int> test {90, 76, 500, 54, 20, 1};

    cout << "Testing min index where it should return me index 2 and we get: "  << min_index(test, 1) << endl;

    selection_sort(test);

    for (int i = 0; i < test.size();i++)
    {
        cout << test.at(i) << " ";
    }
    cout << endl;

    return 0;
}
