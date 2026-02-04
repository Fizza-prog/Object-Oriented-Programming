#ifndef STRING_H
#define STRING_H

#include<iostream>
using namespace std;

class String
{
private:
    char* data;
    int size;
    int calculateLength(const char* str) const;
    bool isValid(int index) const;
    int findFirst(String subStr, int start = 0);
    int findNum(const char* str)const;
    int digitCount(long long int num);
public:
    friend std::istream& operator>>(std::istream& in, String& s);
    friend std::ostream& operator<<(std::ostream& out, const String& s);

    String();
    String(char c);
    String(const char* str);
    String(const String& r);
    String(String&& other);
    ~String();
    
    char& at(int index);
    const char& at(int index)const;
    char& operator [](const int index);
    const char& operator [](const int index)const;
    
    void input();
    bool isEmpty() const;
    bool operator! () const;
    int getLength() const;
    int getSize()const;
    void display() const;
    
    void shrink();
    void makeUpper();
    void makeLower();
    String left(int count);
    String right(int count);
    
    int compare(String& s2);
    int operator ==(String& s2) const;
    
    void concatEqual(String r);
    void operator +=(String r);
    
    String concatenate(String r) const;
    String operator +(const String& s2) const;
    
    void resize(int s);
    void trimLeft();
    void trimRight();
    void trim();
    
    int replace(const String& old, const String& newSubStr);
    int find(const String& subStr, const int start = 0) const;
    
    void reverse();
    void remove(const int index, const int count = 1);
    void insert(const int index, const String& subStr);
    
    long long int convertToInteger() const;
    float convertToFloat() const;
    void setNumber(long long int num);
    
    String& operator =(const long long int num);
    String& operator =(const String& r);
    String& operator=(String&& other);
    
    explicit operator bool() const;
    explicit operator long long int() const;
};

#endif