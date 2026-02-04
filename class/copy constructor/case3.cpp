#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) 
    {
        cout << "default constructor called!" << endl;
    }
    
    Point(int a, int b) : x(a), y(b) 
    {
        cout << "parametric constructor called!" << endl;
    }
    
    Point(Point &p1) 
    {
        cout << "copy constructor called!" << endl;
        x = p1.x;
        y = p1.y;
    }
    
    void display() const 
    {
        cout << "display function!" << endl;
        cout << "x is: " << x << endl;
        cout << "y is: " << y << endl;
    }
    
    ~Point() 
    {
        cout << "destructor called on: " << x << " " << y << endl;
    }
    
    void setx(int v) 
    { 
        x = v; 
    }
    void sety(int v) 
    { 
        y = v; 
    }
};

Point myFunc2() 
{
    Point z1;
    z1.setx(4);
    z1.sety(3);
    return z1;
}

int main() {
    Point p2 = myFunc2();
    p2.display();
    cout << "end!" << endl;
    return 0;
}