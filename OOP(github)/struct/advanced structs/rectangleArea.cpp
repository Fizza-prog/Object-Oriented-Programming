#include<iostream>
using namespace std;

struct Rectangle {
    double length;
    double width;
    double area;
};

Rectangle createRectangle()
{
    Rectangle r;
    
    cout << "Enter rectangle dimensions:" << endl;
    cout << "Length: ";
    cin >> r.length;
    cout << "Width: ";
    cin >> r.width;
    
    r.area = r.length * r.width;
    return r;
}

int main() {
    Rectangle rect = createRectangle();
    
    cout << "\nRectangle Details:" << endl;
    cout << "Length: " << rect.length << endl;
    cout << "Width: " << rect.width << endl;
    cout << "Area: " << rect.area << endl;
    
    return 0;
}