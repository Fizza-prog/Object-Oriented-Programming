#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

class String
{
private:
    char* data;
    int size;

    int calculateLength(const char* str) const;
    bool isValid(int index) const;

public:
    friend istream& operator>>(istream&, String&);
    friend ostream& operator<<(ostream&, const String&);

    String();
    String(char c);
    String(const char* str);
    String(const String& r);
    ~String();

    String& operator=(const String& r);

    char& operator[](int index);
    const char& operator[](int index) const;

    bool isEmpty() const;
    int getLength() const;
    int getSize() const;

    void resize(int s);
    void display() const;

    
    bool operator==(const String& s2) const;
    bool operator==(const char* str) const;
};

#endif