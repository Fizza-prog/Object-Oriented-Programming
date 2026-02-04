#include "String.h"

int String::calculateLength(const char* str) const {
    if (!str) return 0;
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

bool String::isValid(int index) const {
    return index >= 0 && index < getLength();
}

String::String() {
    size = 1;
    data = new char[1];
    data[0] = '\0';
}

String::String(char c) {
    size = 2;
    data = new char[2];
    data[0] = c;
    data[1] = '\0';
}

String::String(const char* str) {
    if (!str) {
        size = 1;
        data = new char[1];
        data[0] = '\0';
        return;
    }
    int len = calculateLength(str);
    size = len + 1;
    data = new char[size];
    for (int i = 0; i < len; i++)
        data[i] = str[i];
    data[len] = '\0';
}

String::String(const String& r) {
    size = r.size;
    data = new char[size];
    for (int i = 0; i < size; i++)
        data[i] = r.data[i];
}

String::~String() {
    delete[] data;
    data = nullptr;
    size = 0;
}

String& String::operator=(const String& r) {
    if (this == &r) return *this;
    delete[] data;
    size = r.size;
    data = new char[size];
    for (int i = 0; i < size; i++)
        data[i] = r.data[i];
    return *this;
}

char& String::operator[](int index) {
    if (!isValid(index)) {
        cout << "Index out of bounds\n";
        exit(0);
    }
    return data[index];
}

const char& String::operator[](int index) const {
    if (!isValid(index)) {
        cout << "Index out of bounds\n";
        exit(0);
    }
    return data[index];
}

bool String::isEmpty() const {
    return data[0] == '\0';
}

int String::getLength() const {
    return calculateLength(data);
}

int String::getSize() const {
    return size;
}

void String::resize(int s) {
    if (s <= 0) {
        delete[] data;
        data = new char[1];
        data[0] = '\0';
        size = 1;
        return;
    }
    char* temp = new char[s];
    int len = getLength();
    int limit = (s-1 < len) ? s-1 : len;
    for (int i = 0; i < limit; i++)
        temp[i] = data[i];
    temp[limit] = '\0';
    delete[] data;
    data = temp;
    size = s;
}

void String::display() const {
    if (data)
        cout << data;
}

istream& operator>>(istream& in, String& r) {
    char buffer[1000];
    in.getline(buffer, 1000);  // FIXED: Using getline instead of >>
    r = String(buffer);
    return in;
}

ostream& operator<<(ostream& out, const String& r) {
    if (r.data)
        out << r.data;
    return out;
}

bool String::operator==(const String& s2) const {
    if (getLength() != s2.getLength()) return false;
    for (int i = 0; i < getLength(); i++)
        if (data[i] != s2.data[i]) return false;
    return true;
}

bool String::operator==(const char* str) const {
    if (!str) return false;
    int i = 0;
    while (data[i] != '\0' && str[i] != '\0') {
        if (data[i] != str[i]) return false;
        i++;
    }
    return data[i] == '\0' && str[i] == '\0';
}