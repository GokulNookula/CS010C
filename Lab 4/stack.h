#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <string>
#include <stdexcept>

const int MAX_SIZE = 20;

using namespace std;

template <typename T>
class stack
{
    public:
        stack()
        {
            _data = new T[MAX_SIZE];
            _size = 0;
        }
        ~stack()
        {
            delete[] _data;
            _size = 0;
        }
        void push(T val)
        {
            if (_size < MAX_SIZE)
            {
                _data[_size] = val;
                _size++;
                return;
            }
            throw overflow_error ("Called push on full stack.");
        }
        void pop()
        {
            if (_size > 0)
            {
                _size--;
                return;
            }
            throw out_of_range ("Called pop on empty stack.");
        }
        void pop_two()
        {
            if (_size <= 0)
            {
                throw out_of_range ("Called pop_two on empty stack.");
                return;
            }
            else if (_size == 1)
            {
                throw out_of_range ("Called pop_two on a stack of size 1.");
                return;
            }
            else
            {
                _size -= 2;
                return;
            }
        }
        const T top()
        {
            if (!empty())
            {
                return _data[_size - 1];
            }
            throw underflow_error ("Called top on empty stack.");
            return 0;
        }
        const bool empty()
        {
            return (_size == 0);
        }


    private:
        T* _data;
        int _size;
};

#endif
