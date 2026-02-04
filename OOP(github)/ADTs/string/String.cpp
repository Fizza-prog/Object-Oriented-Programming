#include<iostream>
#include"String.h"
using namespace std;


int String::calculateLength(const char* str) const
{
    int len = 0;
    if (str != nullptr)
    {
        while (str[len] != '\0')
        {
            len++;
        }
    }
    return len;
}

bool String::isValid(int index) const
{
    return index >= 0 && index < getLength();
}

int String::findFirst(String subStr, int start)
{
    int subLen = subStr.getLength();
    int strLen = getLength();

    if (start < 0 || subLen == 0 || subLen > strLen)
    {
        return -1;
    }

    for (int i = start; i <= strLen - subLen; i++)
    {
        bool match = true;
        for (int j = 0; j < subLen; j++)
        {
            if (data[i + j] != subStr.data[j])
            {
                match = false;
                break;
            }
        }
        if (match)
            return i;
    }
    return -1;
}

int String::findNum(const char* str)const
{
    if (str == nullptr)
        return 0;
        
    int i = 0;
    int count = 0;
    while ((str[i] >= '0') && (str[i] <= '9'))
    {
        count++;
        i++;
    }
    return count;
}

int String::digitCount(long long int num)
{
    if (num == 0)
        return 1;
        
    long long int temp = num;
    if (num < 0)
    {
        temp = -num;
    }
    
    int digcount = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        digcount++;
    }
    return digcount;
}

ostream& operator<<(ostream& out, const String& ref)
{
    if (ref.data != nullptr)
    {
        out << ref.data;
    }
    return out;
}

istream& operator>>(istream& in, String& ref)
{
    ref.input();
    return in;
}

String::String()
{
    size = 1;
    data = new char[1];
    data[0] = '\0';
}

String::String(char c) : String()
{
    delete[] data;
    size = 2;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
}

String::String(const char* str)
{
    if (str == nullptr)
    {
        size = 1;
        data = new char[1];
        data[0] = '\0';
        return;
    }

    int l = calculateLength(str);
    size = l + 1;
    data = new char[l + 1];
    for (int i = 0; i < l; i++)
    {
        data[i] = str[i];
    }
    data[l] = '\0';
}

String::String(const String& r)
{
    if (r.data == nullptr || r.size == 0)
    {
        size = 1;
        data = new char[1];
        data[0] = '\0';
        return;
    }
    
    size = r.size;
    data = new char[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = r.data[i];
    }
}

String::String(String&& other)
{
    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

String& String::operator=(String&& other)
{
    if (this != &other) 
    { 
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}

String& String::operator =(const String& r)
{
    if (this == &r)
    {
        return *this;
    }
    
    delete[] data;
    
    if (r.data == nullptr || r.size == 0)
    {
        size = 1;
        data = new char[1];
        data[0] = '\0';
    }
    else
    {
        size = r.size;
        data = new char[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = r.data[i];
        }
    }
    return *this;
}

String::~String()
{
    if (data != nullptr)
        delete[] data;
    size = 0;
    data = nullptr;
}

char& String::at(int index)
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}

const char& String::at(int index)const
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}

char& String::operator [](const int index)
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}

const char& String::operator [](const int index)const
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}

void String::input()
{
    if (data != nullptr)
    {
        delete[] data;
    }
    
    const int INITIAL_SIZE = 16;
    size = INITIAL_SIZE;
    data = new char[size];
    
    char ch;
    int count = 0;
    
    while ((ch = cin.get()) != '\n')
    {
        if (count + 1 == size)
        {
            resize(size * 2);
        }
        data[count++] = ch;
    }
    data[count] = '\0';
    
    if (count + 1 < size)
    {
        shrink();
    }
}

bool String::isEmpty() const
{
    return (data == nullptr || data[0] == '\0');
}

bool String::operator! () const
{
    return isEmpty();
}

int String::getLength() const
{
    return calculateLength(data);
}

int String::getSize()const
{
    return size;
}

void String::display() const
{
    if (data != nullptr)
    {
        cout << data;
    }
}

void String::shrink()
{
    int len = getLength();
    if (len + 1 < size)
    {
        resize(len + 1);
    }
}

void String::makeUpper()
{
    for (int i = 0; i < getLength(); i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = data[i] - 32;
        }
    }
}

void String::makeLower()
{
    for (int i = 0; i < getLength(); i++)
    {
        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = data[i] + 32;
        }
    }
}

String String::left(int count)
{
    if (count <= 0 || count > getLength())
    {
        cout << "Invalid count in left()\n";
        exit(0);
    }

    char* temp = new char[count + 1];
    for (int i = 0; i < count; i++)
    {
        temp[i] = data[i];
    }
    temp[count] = '\0';
    
    String result(temp);
    delete[] temp;
    return result;
}

String String::right(int count)
{
    if (count <= 0 || count > getLength())
    {
        cout << "Invalid count in right()\n";
        exit(0);
    }
    
    int len = getLength();
    char* temp = new char[count + 1];
    
    for (int i = 0; i < count; i++)
    {
        temp[i] = data[len - count + i];
    }
    temp[count] = '\0';
    
    String result(temp);
    delete[] temp;
    return result;
}

int String::compare(String& s2)
{
    int len1 = getLength();
    int len2 = s2.getLength();

    int minLength = (len1 < len2) ? len1 : len2;

    for (int i = 0; i < minLength; i++)
    {
        if (data[i] != s2.data[i])
        {
            return (data[i] > s2.data[i]) ? 1 : -1;
        }
    }
    
    if (len1 == len2)
        return 0;
    else if (len1 > len2)
        return 1;
    else
        return -1;
}

int String::operator ==(String& s2) const
{
    int len1 = getLength();
    int len2 = s2.getLength();

    if (len1 != len2)
        return 0;
    
    for (int i = 0; i < len1; i++)
    {
        if (data[i] != s2.data[i])
        {
            return 0;
        }
    }
    return 1;
}

void String::concatEqual(String r)
{
    int len1 = getLength();
    int len2 = r.getLength();
    int newSize = len1 + len2 + 1;
    
    char* temp = new char[newSize];
    
    for (int i = 0; i < len1; i++)
    {
        temp[i] = data[i];
    }
    
    for (int i = 0; i < len2; i++)
    {
        temp[len1 + i] = r.data[i];
    }
    
    temp[newSize - 1] = '\0';
    
    delete[] data;
    data = temp;
    size = newSize;
}

void String::operator +=(String r)
{
    concatEqual(r);
}

String String::concatenate(String r) const
{
    int len1 = getLength();
    int len2 = r.getLength();
    int newSize = len1 + len2 + 1;
    
    char* temp = new char[newSize];
    
    for (int i = 0; i < len1; i++)
    {
        temp[i] = data[i];
    }
    
    for (int i = 0; i < len2; i++)
    {
        temp[len1 + i] = r.data[i];
    }
    
    temp[newSize - 1] = '\0';
    
    String result(temp);
    delete[] temp;
    return result;
}

String String::operator +(const String& s2) const
{
    int len1 = getLength();
    int len2 = s2.getLength();
    int newSize = len1 + len2 + 1;
    
    char* temp = new char[newSize];
    
    for (int i = 0; i < len1; i++)
    {
        temp[i] = data[i];
    }
    
    for (int i = 0; i < len2; i++)
    {
        temp[len1 + i] = s2.data[i];
    }
    
    temp[newSize - 1] = '\0';
    
    String result(temp);
    delete[] temp;
    return result;
}

void String::resize(int s)
{
    if (s <= 0)
    {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        size = 1;
        return;
    }
    
    char* temp = new char[s];
    int len = getLength();
    int copySize = (len < s - 1) ? len : s - 1;
    
    for (int i = 0; i < copySize; i++)
    {
        temp[i] = data[i];
    }
    
    temp[copySize] = '\0';
    
    delete[] data;
    data = temp;
    size = s;
}

void String::trimLeft()
{
    if (data == nullptr)
        return;
    
    int i = 0;
    while (i < getLength() && data[i] == ' ')
    {
        i++;
    }
    
    if (i == 0)
        return;
    
    int newLen = getLength() - i;
    char* temp = new char[newLen + 1];
    
    for (int j = 0; j < newLen; j++)
    {
        temp[j] = data[i + j];
    }
    
    temp[newLen] = '\0';
    
    delete[] data;
    data = temp;
    size = newLen + 1;
}

void String::trimRight()
{
    if (data == nullptr)
        return;
    
    int len = getLength();
    int i = len - 1;
    
    while (i >= 0 && data[i] == ' ')
    {
        i--;
    }
    
    data[i + 1] = '\0';
    size = i + 2;
}

void String::trim()
{
    trimLeft();
    trimRight();
}

int String::replace(const String& old, const String& newSubStr)
{
    if (old.getLength() == 0)
    {
        cout << "Error: Cannot replace an empty substring.\n";
        return 0;
    }

    int oldLen = old.getLength();
    int newLen = newSubStr.getLength();
    int start = 0;
    int count = 0;
    
    int index = findFirst(old, start);
    while (index != -1)
    {
        remove(index, oldLen);
        insert(index, newSubStr);
        start = index + newLen;
        count++;
        index = findFirst(old, start);
    }
    return count;
}

int String::find(const String& subStr, const int start) const
{
    if (subStr.isEmpty())
    {
        return -1;
    }
    
    int len1 = getLength();
    int len2 = subStr.getLength();

    if (len2 == 0 || len2 > len1 || start < 0 || start > len1)
    {
        return -1;
    }
    
    for (int i = start; i <= len1 - len2; i++)
    {
        bool found = true;
        for (int j = 0; j < len2; j++)
        {
            if (data[i + j] != subStr.data[j])
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            return i;
        }
    }
    return -1;
}

void String::reverse()
{
    int len = getLength();
    if (len <= 1)
        return;
    
    for (int i = 0; i < len / 2; i++)
    {
        char temp = data[i];
        data[i] = data[len - 1 - i];
        data[len - 1 - i] = temp;
    }
}

void String::remove(const int index, const int count)
{
    if (!isValid(index) || index + count > getLength())
    {
        cout << "\nInvalid index";
        exit(0);
    }

    int len = getLength();
    for (int i = index; i + count < len; i++)
    {
        data[i] = data[i + count];
    }

    data[len - count] = '\0';
    size = size - count;
}

void String::insert(const int index, const String& subStr)
{
    if (index < 0 || index > getLength())
    {
        cout << "\nInvalid index";
        exit(0);
    }
    
    int subStrLen = subStr.getLength();
    int originalLength = getLength();

    int newSize = originalLength + subStrLen + 1;
    char* newData = new char[newSize];
    
    for (int i = 0; i < index; i++)
    {
        newData[i] = data[i];
    }
    
    for (int i = 0; i < subStrLen; i++)
    {
        newData[index + i] = subStr.data[i];
    }
    
    for (int i = index; i < originalLength; i++)
    {
        newData[i + subStrLen] = data[i];
    }
    
    newData[newSize - 1] = '\0';

    delete[] data;
    data = newData;
    size = newSize;
}

long long int String::convertToInteger() const
{
    if (data == nullptr || data[0] == '\0')
    {
        cout << "Error: String is empty.\n";
        return 0;
    }
    
    int i = 0;
    bool isNegative = false;

    if (data[i] == '-')
    {
        isNegative = true;
        i++;
    }
    else if (data[i] == '+')
    {
        i++;
    }

    int digitCount = findNum(data + i);
    if (digitCount == 0)
    {
        cout << "Error: No digits found for integer part.\n";
        exit(0);
    }

    long long int result = 0;
    for (int j = 0; j < digitCount; j++)
    {
        result = result * 10 + (data[i + j] - '0');
    }

    if (isNegative)
    {
        result *= -1;
    }
    return result;
}

float String::convertToFloat() const
{
    int i = 0;
    bool isNegative = false;

    if (data == nullptr || data[0] == '\0')
    {
        cout << "Error: String is empty.\n";
        return 0.0f;
    }

    if (data[i] == '-')
    {
        isNegative = true;
        i++;
    }
    else if (data[i] == '+')
    {
        i++;
    }
    
    if (data[i] < '0' || data[i] > '9')
    {
        cout << "Error: Must start with digit after sign.\n";
        exit(0);
    }
    
    float result = 0.0f;
    while (data[i] >= '0' && data[i] <= '9')
    {
        result = result * 10 + (data[i] - '0');
        i++;
    }

    if (data[i] == '.')
    {
        i++;
        float divisor = 10.0f;
        while (data[i] >= '0' && data[i] <= '9')
        {
            result += (data[i] - '0') / divisor;
            divisor *= 10.0f;
            i++;
        }
    }
    
    if (isNegative)
    {
        result *= -1;
    }

    return result;
}

void String::setNumber(long long int num)
{
    if (data != nullptr)
    {
        delete[] data;
    }
    
    if (num == 0)
    {
        size = 2;
        data = new char[size];
        data[0] = '0';
        data[1] = '\0';
        return;
    }
    
    bool isNegative = false;
    long long int temp = num;
    
    if (num < 0)
    {
        isNegative = true;
        temp = -num;
    }
    
    int numDigits = digitCount(temp);
    size = numDigits + (isNegative ? 2 : 1);
    data = new char[size];
    
    int index = isNegative ? 1 : 0;
    
    for (int i = 0; i < numDigits; i++)
    {
        data[index + numDigits - 1 - i] = (temp % 10) + '0';
        temp /= 10;
    }
    
    if (isNegative)
    {
        data[0] = '-';
    }
    
    data[size - 1] = '\0';
}

String& String::operator =(const long long int num)
{
    setNumber(num);
    return *this;
}

String::operator bool() const
{
    return !isEmpty();
}

String::operator long long int() const
{
    return convertToInteger();
}