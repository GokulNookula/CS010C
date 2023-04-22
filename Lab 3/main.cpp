#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T> //Creating a function that can take in any type of vector like string, int or etc
const unsigned min_index(const vector<T> &vec, unsigned index)   //This function is trying to find the min value index and returing it 
{
    unsigned minIndex = index;

    for (unsigned int i = index + 1; i < vec.size(); i++)   //Iterating throughout the vector to find the lowest value
    {
        if (vec.at(i) < vec.at(minIndex))   //Checking if we are able to found the new mininmum value than the previous one
        {
            minIndex = i;
        }
    }
    return minIndex;    //Returning the new minimum index 
}

template <typename T> //Creating a function that can take in any type of vector like string, int or etc
void selection_sort (vector<T> &vec) //This function is used to sort the whole vector in ascending order
{
    for (unsigned int i = 0; i < vec.size(); i++) //Iterating through the entire vector in order to sort it in ascending order
    {
        // Find the index of the smallest element in the remaining unsorted portion of the vector
        // Swap the smallest element with the first unsorted element
        swap (vec.at(i),vec.at(min_index(vec,i))); 

    }
}

template <typename T> //Creating a function that can take in any type of vector like string, int or etc
const T getElement(vector<T> vec, int index) //This function is to get the data inside the vector and return it
{
    unsigned int i = index;

    if (index < 0 || i > vec.size())  //Checking if our index exists in the given vector or not
    {
        throw out_of_range("out of range exception occured");   //Throwing an error since it isn't in the range
    }
    return vec.at(i);
}

// Function to create a vector of random characters with a random length between 0 and 25
vector<char> createVector()
{
    // Generate a random size for the vector between 0 and 25
    int vecSize = rand() % 26;
    // Start with the character 'a'
    char c = 'a';
    // Create an empty vector to hold the characters
    vector<char> vec;
    // Loop to add characters to the vector up to the random size
    for(int i = 0; i < vecSize; i++)
    {
        // Add the current character to the vector
        vec.push_back(c);
        // Increment the character to the next letter
        c++;
    }
    // Return the completed vector
    return vec;
}


int main()
{

    //Part A

    //Testing int Vector
    vector <int> vec1 {6,7,3,5,8,6,0,9,1};
    //Testing the min_index function 

    cout << "Testing for min_index should return index value 6 we get: " << min_index(vec1,0) << endl;

    //Before selection sort
    cout << "Printing the whole for ints vector before selection sort: ";
    for (auto i = 0; i < vec1.size(); i++)
    {
        cout << vec1.at(i) << " ";
    }
    cout << endl;

    //After selection sort

    selection_sort(vec1);

    cout << "Printing the whole for int vector after selection sort: ";
    for (auto i = 0; i < vec1.size(); i++)
    {
        cout << vec1.at(i) << " ";
    }
    cout << endl;

    //Testing for char vector

    vector <char> vec2 {'b','e','k','a','c','h','h','k'};
    //Testing the min_index function 

    cout << "Testing for min_index should return index value 3 we get: " << min_index(vec2,0) << endl;

    //Before selection sort
    cout << "Printing the whole for char vector before selection sort: ";
    for (auto i = 0; i < vec2.size(); i++)
    {
        cout << vec2.at(i) << " ";
    }
    cout << endl;

    //After selection sort

    selection_sort(vec2);

    cout << "Printing the whole for char vector after selection sort: ";
    for (auto i = 0; i < vec2.size(); i++)
    {
        cout << vec2.at(i) << " ";
    }
    cout << endl;

    //Testing for double vector
    vector <double> vec3 {6.9,8.5,1.1,2.50,10.1,77.7,9.01,0.1};
    //Testing the min_index function 

    cout << "Testing for min_index should return index value 7 we get: " << min_index(vec3,0) << endl;

    //Before selection sort
    cout << "Printing the whole for double vector before selection sort: ";
    for (auto i = 0; i < vec3.size(); i++)
    {
        cout << vec3.at(i) << " ";
    }
    cout << endl;

    //After selection sort

    selection_sort(vec3);

    cout << "Printing the whole for double vector after selection sort: ";
    for (auto i = 0; i < vec3.size(); i++)
    {
        cout << vec3.at(i) << " ";
    }
    cout << endl;


    //Part B

    srand(time(0));
    vector<char> vec = createVector();
    char curChar;
    int index;
    int numOfRuns = 5;
    while(--numOfRuns >= 0)
    {
        cout << "Enter a number: " << endl;
        cin >> index;
        try
        {
            curChar = getElement(vec,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        }
        catch(const out_of_range& excpt)
        {
            cout << excpt.what() << endl;
        }
    
    }
    return 0;
}
