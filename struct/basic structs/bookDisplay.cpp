#include<iostream>
#include<string>
using namespace std;

struct Book {
    string name;
    double price;
};

void DisplayBook(Book b);

int main() {
    Book b1 = {"Namal", 2005.0};
    DisplayBook(b1);
    return 0;
}

void DisplayBook(Book b) 
{
    cout << "Name of the book is: " << b.name << endl;
    cout << "Price of the book is: " << b.price << endl;
}