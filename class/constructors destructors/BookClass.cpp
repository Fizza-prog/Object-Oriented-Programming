#include<iostream>
#include<string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;
    double price;
public:
    void setTitle(string input) 
    { 
        title = input; 
    }
    void setAuthor(string input) 
    { 
        author = input; 
    }
    void setYear(int input) 
    { 
        year = input; 
    }
    void setPrice(double input) 
    { 
        price = input; 
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
        double discount = (percent/100) * price;
        cout << "the discount price on the book is: " << discount;
    }
};

int main() {
    Book b;
    string strInput;
    int intgr;
    double fpoint;
    
    cout << "USER INPUT!" << endl;
    cout << "enter the title of book: "; getline(cin, strInput); b.setTitle(strInput);
    cout << "enter name of the author: "; getline(cin, strInput); b.setAuthor(strInput);
    cout << "enter the year of publication: "; cin >> intgr; b.setYear(intgr);
    cout << "enter the price: "; cin >> fpoint; b.setPrice(fpoint);
    
    cout << "enter the discount percentage: "; cin >> fpoint;
    cout << "title: " << b.getTitle() << endl;
    cout << "author: " << b.getAuthor() << endl;
    cout << "year of publication: " << b.getYear() << endl;
    cout << "price of book: " << b.getPrice() << endl;
    b.applyDiscount(fpoint);
    
    cout << "\nMANUAL INPUT!" << endl;
    b.setTitle("Harry Potter");
    b.setAuthor("JK Rowling");
    b.setYear(2012);
    b.setPrice(234);
    
    cout << "title: " << b.getTitle() << endl;
    cout << "author: " << b.getAuthor() << endl;
    cout << "year of publication: " << b.getYear() << endl;
    cout << "price: " << b.getPrice() << endl;
    
    return 0;
}