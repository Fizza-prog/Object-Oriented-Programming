#include<iostream>
#include"String.h"
using namespace std;
int String::calculateLength(const char* str) const
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}
bool  String::isValid(int index) const
{
    return index >= 0 && index < size;
}
int  String::findFirst(String subStr, int start)
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
            }
        }
        if (match)
            return i;
    }
    return -1;
}
int  String::findNum(const char* str)const
{
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
    long long int temp = num;
    if (num < 0)
    {
        return 1;
    }
    int digcount = 0;
    int dig = 0;
    while (temp != 0)
    {
        dig = temp % 10;
        digcount++;
        temp = temp / 10;
    }
    return digcount;

}
String::String()
{
    //cout << "default string  " << this << "\n ";
    size = 0;
    data = nullptr;
}
String::String(char c) :String()
{
    //cout << "single string " << this << "\n ";
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
}
String::String(const char* str)
{
    //cout << "const char string " << this << "\n ";
    if (str == nullptr)
    {
        size = 0;
        data = nullptr;
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
    //cout << "copy string " << this << "\n ";

    if (r.size == 0)
    {
        return;
    }
    // cout << "Copy Constructor\n";
    size = r.size;
    data = new  char[size];
    for (int i = 0; i < size; i++)
    {
        data[i] = r.data[i];
    }

}
String :: ~String()
{
    //cout << "destructor string  " << this << "\n ";
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
char& String::at(int index)const
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}
char& String ::operator [](const int index)
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}
const   char& String ::operator [](const int index)const
{
    if (isValid(index))
    {
        return data[index];
    }
    cout << "Index out of bound";
    exit(0);
}
void  String::input()
{
    if (data != nullptr)
    {
        this->~String();
    }
    char ch;
    int count = 0;
    data = new char[1];
    size = 1;
    while ((ch = cin.get()) != '\n')
    {
        data[count] = ch;
        if (count + 1 == size)
        {
            resize(size * 2);
        }
        count++;
    }
    data[count] = '\0';
}
bool String::isEmpty() const
{
    if ((data[0] == '\0') || (data == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }

}
bool  String ::operator! () const
{
    if ((data[0] == '\0') || (data == nullptr))
    {
        return true;
    }
    else
    {
        return false;
    }

}
int  String::getLength() const
{
    return  calculateLength(data);
}
int  String::getSize() const
{
    return size;
}
void String::display() const
{
    if (data != nullptr)
    {
        cout << data;
        cout << "\n";
    }
}
void  String::shrink()
{
    resize(getLength() + 1);
}
void  String::makeUpper()
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] >= 'a' && data[i] <= 'z')
        {
            data[i] = data[i] - 32;
        }
        cout << data[i];
    }
    cout << "\n";
}
void String::makeLower()
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] >= 'A' && data[i] <= 'Z')
        {
            data[i] = data[i] + 32;
        }
        cout << data[i];
    }
    cout << "\n";
}
String String::left(int count)
{
    if (count <= 0 || count > getLength())
    {
        cout << "Invalid count in left()\n";
        exit(0);
    }

    data[count] = '\0';         // Truncate temporarily
    String result(data);        // Construct from truncated view
    size = count + 1;           // Update this->size
    return result;
}
String  String::right(int count)
{
    if (count <= 0 || count > getLength())
    {
        cout << "Invalid count in left/right()\n";
        exit(0);
    }
    int len1 = this->getLength();
    for (int i = 0; i < count; i++)
    {
        data[i] = data[len1 - count + i];
    }
    data[count] = '\0';
    String result(data);
    this->~String();
    return  result;
}
int String::compare(String& s2)
{
    int len1 = getLength();
    int len2 = s2.getLength();

    int minLength;
    if (len1 < len2)
    {
        minLength = len1;
    }
    else
    {
        minLength = len2;
    }

    for (int i = 0; i < minLength; i++)
    {
        if ((data[i]) != (s2.data[i]))
        {
            if (data[i] > s2.data[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

    }
    if (len1 == len2)
        return 0;
    else if (len1 > len2)
        return 1;
    else
        return -1;
}
int  String ::operator ==(String& s2) const
{
    int len1 = getLength();
    int len2 = s2.getLength();

    int minLength;
    if (len1 < len2)
    {
        minLength = len1;
    }
    else
    {
        minLength = len2;
    }

    for (int i = 0; i < minLength; i++)
    {
        if ((data[i]) != (s2.data[i]))
        {
            if (data[i] > s2.data[i])
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

    }
    if (len1 == len2)
        return 0;
    else if (len1 > len2)
        return 1;
    else
        return -1;
}
void  String::concatEqual(String r)
{
    //cout << "concat \n";
    int newSize = (this->getLength() + r.getLength()) + 1;
    resize(newSize);
    int i = this->getLength();
    for (int j = 0; j < r.getLength(); j++)
    {
        data[i] = r.data[j];
        i++;
    }
    data[i] = '\0';
    size = newSize;
}
void  String ::operator +=(String r)
{
    //cout << "concat \n";
    int newSize = (this->getLength() + r.getLength()) + 1;
    resize(newSize);
    int i = this->getLength();
    for (int j = 0; j < r.getLength(); j++)
    {
        data[i] = r.data[j];
        i++;
    }
    data[i] = '\0';
    size = newSize;
}
String String::concatenate(String r) const
{
    int newSize = this->getLength() + r.getLength() + 1;
    char* temp = new char[newSize];
    int j = 0;

    for (int i = 0; i < this->getLength(); i++)
    {
        temp[j++] = data[i];
    }

    for (int i = 0; i < r.getLength(); i++)
    {
        temp[j++] = r.data[i];
    }

    temp[j] = '\0';
    String result(temp);
    delete[] temp;
    return result;
}
String String :: operator +(const String& s2) const
{
    int newSize = this->getLength() + s2.getLength() + 1;
    char* temp = new char[newSize];
    int j = 0;

    for (int i = 0; i < this->getLength(); i++)
    {
        temp[j++] = data[i];
    }

    for (int i = 0; i < s2.getLength(); i++)
    {
        temp[j++] = s2.data[i];
    }

    temp[j] = '\0';
    String result(temp);
    delete[] temp;
    return result;
}
void  String::resize(int s)
{
    //cout << "resize " << "\n";
    if (s <= 0)
    {
        this->~String();
        return;
    }
    char* temp = new char[s];
    int i = 0;
    while (i < size && i < s)
    {
        temp[i] = data[i];
        i++;
    }
    delete[] data;
    size = s;
    data = temp;
}
void  String::trimLeft()
{
    int i = 0;
    while (i < size && data[i] == ' ')
    {
        i++;
    }

    if (data == nullptr || i == 0)
    {
        return;
    }
    int j = 0;
    while ((i + j) < size)
    {
        data[j] = data[i + j];
        j++;
    }
    cout << "\n";
    size = j;

}
void  String::trimRight()
{
    if (data == nullptr)
        return;

    int i = size - 2; // size includes '\0', so last char is at size - 2

    while (i >= 0 && data[i] == ' ')
    {
        i--;
    }
    data[i + 1] = '\0';
    size = i + 2;  // +1 for index, +1 for '\0'
}
void  String::trim()
{
    trimLeft();
    trimRight();
}
int  String::replace(const String& old, const String& newSubStr)
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
int  String::find(const String& subStr, const int start) const
{
    if (subStr.isEmpty())
    {
        return 0;
    }
    int count = 0;
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
            }
        }
        if (found)
        {
            count++;
        }
    }
    return count;
}
void String::reverse()
{
    char* temp = new char[size];
    int a = 0;
    for (int i = size - 2; i >= 0; i--)
    {
        temp[a] = data[i];
        a++;
    }
    temp[a] = '\0';
    delete[] data;
    data = temp;
    size = a + 1;
}
void  String::remove(const int index, const int count)
{
    if (!isValid(index) || index + count > getLength())
    {
        cout << "\nInvalid index";
        exit(0);
    }

    int len = getLength();
    for (int i = index; i + count < len; ++i)
    {
        data[i] = data[i + count];
    }

    data[len - count] = '\0';
    size = size - count;
}
void  String::insert(const int index, const String& subStr)
{
    cout << "insert " << "\n";
    if (index < 0 || index > getLength())
    {
        cout << "\nInvalid index";
        exit(0);
    }
    int subStrLen = subStr.getLength();
    int originalLength = getLength();

    int newSize = originalLength + subStrLen;
    char* newData = new char[newSize + 1];
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
        newData[i + subStrLen] = data[i];     //Buffer
    }
    newData[newSize] = '\0';

    delete[] data;
    data = newData;
    size = newSize + 1;
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
float  String::convertToFloat() const
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
void  String::setNumber(long long int num)
{
    if (data != nullptr)
    {
        this->~String();
    }
    if (num > 0)
    {
        int numdigitcount = digitCount(num); // digits count
        size = numdigitcount + 1;               // size including null terminator

        if (data != nullptr)
        {
            this->~String();
        }

        data = new char[size];                // allocate memory for data

        long long int temp = num;
        int i = 0;
        while (i < numdigitcount)
        {
            data[i] = (temp % 10) + '0';     // digits reversed
            temp /= 10;
            i++;
        }
        data[numdigitcount] = '\0';             // null terminate

        reverse();                           // reverse the digits to correct order

    }
    else if (num == 0)
    {
        size = 2;

        if (data != nullptr)
        {
            this->~String();
        }

        data = new char[size];
        data[0] = '0';
        data[1] = '\0';
    }
    else
    {
        long long temp = -num;
        int count = digitCount(temp);
        size = count + 2;
        data = new char[size];

        data[0] = '-';
        int i = count;
        while (temp > 0)
        {
            data[i] = (temp % 10) + '0';
            temp /= 10;
            i--;
        }
        data[size - 1] = '\0';
    }


}
String& String ::operator =(const long long int num)
{
    if (data != nullptr)
    {
        this->~String();
    }
    if (num > 0)
    {
        int numdigitcount = digitCount(num); // digits count
        size = numdigitcount + 1;               // size including null terminator

        if (data != nullptr)
        {
            this->~String();
        }

        data = new char[size];                // allocate memory for data

        long long int temp = num;
        int i = 0;
        while (i < numdigitcount)
        {
            data[i] = (temp % 10) + '0';     // digits reversed
            temp /= 10;
            i++;
        }
        data[numdigitcount] = '\0';             // null terminate

        reverse();                           // reverse the digits to correct order



    }
    else if (num == 0)
    {
        size = 2;

        if (data != nullptr)
        {
            this->~String();
        }

        data = new char[size];
        data[0] = '0';
        data[1] = '\0';
    }
    else
    {
        long long temp = -num;
        int count = digitCount(temp);
        size = count + 2;
        data = new char[size];

        data[0] = '-';
        int i = count;
        while (temp > 0)
        {
            data[i] = (temp % 10) + '0';
            temp /= 10;
            i--;
        }
        data[size - 1] = '\0';
    }

    return *this;
}
String& String ::operator =(const String& r)
{
    if (this == &r)
    {
        return *this;
    }
    else if (r.data == nullptr)
    {
        this->~String();
        return *this;
    }
    else
    {
        delete[] data;
        size = r.size;
        data = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            data[i] = r.data[i];
        }
        return *this;
    }
}
String :: operator bool() const
{
    return (!(isEmpty()));
}
String :: operator long long int() const
{
    return convertToInteger();
}

istream& operator>>(istream& in, String& r)
{
    r.input();
    return in;
}
ostream& operator<<(ostream& out, const String& r)
{
    r.display();
    return out;
}