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
};

void myFunc(Point p) 
{
    cout << "my function is called!" << endl;
    p.display();
}

int main() 
{
    Point p1;
    myFunc(p1);
    return 0;
}