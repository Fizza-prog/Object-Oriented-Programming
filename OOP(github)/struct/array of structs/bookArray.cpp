#include<iostream>
#include<string>
using namespace std;

struct Book {
    string title;
    string author;
    double price;
    int year;
};

int main() {
    Book info[3];
    
    for(int i = 0; i < 3; i++) 
    {
        cout << "\nEnter details for Book " << i + 1 << ":" << endl;
        cout << "Title: ";
        getline(cin, info[i].title);
        cout << "Author: ";
        getline(cin, info[i].author);
        cout << "Price: ";
        cin >> info[i].price;
        cout << "Year: ";
        cin >> info[i].year;
        cin.ignore();
    }
    
    cout << "\n Book Information " << endl;
    for(int i = 0; i < 3; i++) {
        cout << "\nBook " << i + 1 << ":" << endl;
        cout << "Title: " << info[i].title << endl;
        cout << "Author: " << info[i].author << endl;
        cout << "Price: $" << info[i].price << endl;
        cout << "Year: " << info[i].year << endl;
    }
    
    return 0;
}