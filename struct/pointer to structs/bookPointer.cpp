#include<iostream>
#include<cstring>
using namespace std;

struct Book {
    int id;
    char *title;
};

int main() 
{
    Book b;
    b.title = new char[100];
    
    cout << "Enter Book Details:" << endl;
    cout << "Book ID: ";
    cin >> b.id;
    cin.ignore();
    
    cout << "Title: ";
    cin.getline(b.title, 100);
    
    cout << "\nBook Information:" << endl;
    cout << "ID: " << b.id << endl;
    cout << "Title: " << b.title << endl;
    
    delete[] b.title;
    b.title = nullptr;
    
    return 0;
}