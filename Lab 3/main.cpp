#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
unsigned min_index(const vector<T> &vals, unsigned index)
{
    T minVal = vals.at(index);

    for (auto i = index; i < vals.size() - 1; i++)
    {
        if (vals.at(i) < minVal)
        {
            minVal = vals.at(i);
        }
    }
    return minVal;
}

template <typename T>
void selection_sort (vector<T> &vals)
{
    for (auto i = 0; i < vals.size(); i++)
    {
        T minVal = min_index(vals,i);

        if (vals.at(i) < minVal)
        {
            swap (vals.at(i),minVal);
        }

    }
}

int main()
{
    vector<int> test {0,1,2,3};

    cout << min_index(test, 1) << endl;

    return 0;
}
