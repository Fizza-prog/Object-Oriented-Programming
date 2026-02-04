#include<iostream>
#include<string>
using namespace std;

struct Book {
    string title;
    string author;
    double price;
};

double compareBooks(Book&, Book&);

int main() {
    Book b1, b2;
    double cheaperPrice;
    
    cout << "Enter details for book one:" << endl;
    cout << "Title: ";
    getline(cin, b1.title);
    cout << "Name of author: ";
    getline(cin, b1.author);
    cout << "Price of book: ";
    cin >> b1.price;
    cin.ignore();
    
    cout << "\nEnter details for book two:" << endl;
    cout << "Title: ";
    getline(cin, b2.title);
    cout << "Name of author: ";
    getline(cin, b2.author);
    cout << "Price of book: ";
    cin >> b2.price;
    
    cheaperPrice = compareBooks(b1, b2);
    
    cout << "\nThe details of cheaper book are:" << endl;
    if(cheaperPrice == b1.price) {
        cout << "Title: " << b1.title << endl;
        cout << "Name of the author: " << b1.author << endl;
        cout << "Price of the book: " << b1.price << endl;
    } else {
        cout << "Title: " << b2.title << endl;
        cout << "Name of the author: " << b2.author << endl;
        cout << "Price of the book: " << b2.price << endl;
    }
    
    return 0;
}

double compareBooks(Book& b1, Book& b2) 
{
    return (b1.price < b2.price) ? b1.price : b2.price;
}