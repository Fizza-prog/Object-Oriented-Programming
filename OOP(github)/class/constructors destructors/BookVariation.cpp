#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    double price;
public:
    void setTitle(string t) 
    { 
        title = t; 
    }
    void setAuthor(string a) 
    { 
        author = a; 
    }
    void setYear(int y) 
    {  
        year = y; 
    }
    void setPrice(double p) 
    { 
        price = p; 
    }
    
    string getTitle() const 
    { 
        return title; 
    }
    string getAuthor() const 
    { 
        return author; 
    }
    int getYear() const 
    { 
        return year; 
    }
    double getPrice() const 
    { 
        return price; 
    }
    
    void applyDiscount(double percent) 
    {
        price -= price * (percent / 100.0);
    }
    
    void print() const 
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Price: $" << price << endl;
    }
};

int main() {
    Book b1;
    b1.setTitle("1984");
    b1.setAuthor("George Orwell");
    b1.setYear(1949);
    b1.setPrice(29.99);
    
    cout << "Original book info:\n";
    b1.print();
    
    cout << "\nApplying 10% discount...\n";
    b1.applyDiscount(10);
    b1.print();
    
    Book b2;
    b2.setTitle("Brave New World");
    b2.setAuthor("Aldous Huxley");
    b2.setYear(1932);
    b2.setPrice(24.99);
    
    const Book constBook = b2;
    
    cout << "\nConst book info:\n";
    constBook.print();
    cout << "Title: " << constBook.getTitle() << endl;
    
    return 0;
}