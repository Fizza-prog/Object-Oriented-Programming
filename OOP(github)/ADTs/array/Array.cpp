#include<iostream>
#include "Array.h"
using namespace std;

bool Array::isValid(int ind) const 
{
    return ind >= 0 && ind < size;
}

Array::Array() : data(nullptr), size(0) {}

Array::Array(int s)
{
    if (s > 0)
    {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0; 
    }
    else
    {
        size = 0;
        data = nullptr;
    }
}

Array::Array(const Array& other)
{
    size = other.size;
    if (size > 0)
    {
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = other.data[i];
    }
    else
    {
        data = nullptr;
    }
}

Array& Array::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] data;
        
        size = other.size;
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
                data[i] = other.data[i];
        }
        else
        {
            data = nullptr;
        }
    }
    return *this;
}

int Array::getSize() const
{
    return size;
}

Array::~Array()
{
    delete[] data;
    data = nullptr;
    size = 0;
}

void Array::resize(int s)
{
    if (s <= 0)
    {
        delete[] data;
        data = nullptr;
        size = 0;
        return;
    }
    
    int* temp = new int[s];
    
    // Copy old data
    int minSize = (size < s) ? size : s;
    for (int i = 0; i < minSize; i++)
        temp[i] = data[i];
    
    // Initialize new elements to zero
    for (int i = size; i < s; i++)
        temp[i] = 0;
    
    delete[] data;
    data = temp;
    size = s;
}

Array Array::operator+(const Array& other) const
{
    int minsize = (size < other.size) ? size : other.size;
    Array result(minsize);
    for (int i = 0; i < minsize; i++)
        result.data[i] = data[i] + other.data[i];
    return result;
}

Array Array::operator-(const Array& other) const
{
    int minsize = (size < other.size) ? size : other.size;
    Array result(minsize);
    for (int i = 0; i < minsize; i++)
        result.data[i] = data[i] - other.data[i];
    return result;
}

Array Array::operator*(const Array& other) const
{
    int minsize = (size < other.size) ? size : other.size;
    Array result(minsize);
    for (int i = 0; i < minsize; i++)
        result.data[i] = data[i] * other.data[i];
    return result;
}

Array Array::operator/(const Array& other) const
{
    int minsize = (size < other.size) ? size : other.size;
    Array result(minsize);
    for (int i = 0; i < minsize; i++)
    {
        if (other.data[i] == 0)
        {
            cout << "Division by zero at index " << i << endl;
            result.data[i] = 0;
        }
        else {
            result.data[i] = data[i] / other.data[i];
        }
    }
    return result;
}

Array& Array::operator++()
{
    for (int i = 0; i < size; i++)
        data[i]++;
    return *this;
}

Array Array::operator++(int)
{
    Array temp = *this;
    ++(*this);
    return temp;
}

Array& Array::operator--()
{
    for (int i = 0; i < size; i++)
        data[i]--;
    return *this;
}

Array Array::operator--(int)
{
    Array temp = *this;
    --(*this);
    return temp;
}

bool Array::operator==(const Array& other) const
{
    if (size != other.size)
        return false;
    for (int i = 0; i < size; i++)
    {
        if (data[i] != other.data[i])
            return false;
    }
    return true;
}

bool Array::operator!=(const Array& other) const
{
    return !(*this == other);
}

bool Array::operator<(const Array& other) const
{
    int minsize = (size < other.size) ? size : other.size;
    for (int i = 0; i < minsize; i++) {
        if (data[i] < other.data[i]) return true;
        if (data[i] > other.data[i]) return false;
    }
    return size < other.size;
}

bool Array::operator>(const Array& other) const
{
    return other < *this;
}

bool Array::operator<=(const Array& other) const
{
    return !(other < *this);
}

bool Array::operator>=(const Array& other) const
{
    return !(*this < other);
}

int& Array::operator[](int index)
{
    if (!isValid(index)) 
    {
        cout << "Index out of bounds!" << endl;
        exit(1);
    }
    return data[index];
}

const int& Array::operator[](int index) const
{
    if (!isValid(index))
    {
        cout << "Index out of bounds!" << endl;
        exit(1);
    }
    return data[index];
}

Array::operator int() const
{
    return size;
}

ostream& operator<<(ostream& out, const Array& arr)
{
    for (int i = 0; i < arr.size; i++)
        out << arr.data[i] << " ";
    return out;
}

istream& operator>>(istream& in, Array& arr)
{
    for (int i = 0; i < arr.size; i++)
        in >> arr.data[i];
    return in;
}