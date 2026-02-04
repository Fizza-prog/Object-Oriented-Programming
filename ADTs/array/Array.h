#ifndef ARRAY_H
#define ARRAY_H

#include<iostream>
using namespace std;

class Array 
{
    int* data;
    int size;

    bool isValid(int ind) const;

public:
    friend ostream& operator<<(ostream& out, const Array& arr);
    friend istream& operator>>(istream& in, Array& arr);
    
    Array();
    Array(int s);
    Array(const Array& other);
    Array& operator=(const Array& other); 
    ~Array();
    
    int getSize() const;
    void resize(int s);
    
    Array operator+(const Array& other) const;
    Array operator-(const Array& other) const;
    Array operator*(const Array& other) const;
    Array operator/(const Array& other) const;
    
    Array& operator++();       // Prefix increment
    Array operator++(int);     // Postfix increment
    Array& operator--();       // Prefix decrement
    Array operator--(int);     // Postfix decrement
    
    bool operator==(const Array& other) const;
    bool operator!=(const Array& other) const;
    bool operator<(const Array& other) const;
    bool operator>(const Array& other) const;
    bool operator<=(const Array& other) const;  
    bool operator>=(const Array& other) const;
    
    int& operator[](int index);
    const int& operator[](int index) const;
    
    operator int() const;
};

#endif