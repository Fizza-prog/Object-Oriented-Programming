#include<iostream>
using namespace std;

struct Circle {
    double radius;
    int centerX;
    int centerY;
};

void displayCircle(Circle c) 
{
    double area = 3.14159 * c.radius * c.radius;
    cout << "Circle Center: (" << c.centerX << ", " << c.centerY << ")" << endl;
    cout << "Radius: " << c.radius << endl;
    cout << "Area: " << area << endl;
}

int main() 
{
    Circle c;
    
    cout << "Enter Circle Details:" << endl;
    cout << "Radius: ";
    cin >> c.radius;
    cout << "Center X coordinate: ";
    cin >> c.centerX;
    cout << "Center Y coordinate: ";
    cin >> c.centerY;
    
    cout << "\nCircle Information:" << endl;
    displayCircle(c);
    
    return 0;
}