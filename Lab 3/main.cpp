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

int main()
{
    vector<int> test {0,1,2,3};

    cout << min_index(test, 1) << endl;

    return 0;
}
