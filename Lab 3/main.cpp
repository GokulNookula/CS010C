#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    unsigned minIndex = index;

    for (auto i = index; i < vals.size() - 1; i++)
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
    for (auto i = 0; i < vals.size() - 1; i++)
    {
        unsigned minIndex = min_index(vals,i);

        if (minIndex != i)
        {
            swap (vals.at(i),vals.at(minIndex));
        }

    }
}

template <typename T>

T getElement(vector<T> vals, int index)
{
    T element;

    for (auto i = 0; i < vals.size() - 1; i++)
    {
        try
        {
            if (i == index)
            {
                element = vals.at(i);
            }
            else
            {
                throw out_of_range ("out of range exception occured");
            }
        }
        catch(const out_of_range& excpt)
        {
            cout << excpt.what() << endl;
        }
        
    }
    return element;
}

int main()
{
    vector<int> test {90, 76, 1, 54, 20, 2000};

    cout << "Testing min index where it should return me index 2 and we get: "  << min_index(test, 1) << endl;

    selection_sort(test);

    for (int i = 0; i < test.size();i++)
    {
        cout << test.at(i) << " ";
    }
    cout << endl;

    return 0;
}
