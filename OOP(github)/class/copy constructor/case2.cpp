#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int a, int b) 
    {
        cout << "parameterized constructor called!" << endl;
        x = a;
        y = b;
    }
    
    Point(Point& p) 
    {
        cout << endl << "copy constructor called!" << endl;
        x = p.x;
        y = p.y;
    }
    
    void display() 
    {
        cout << x << " , " << y << endl;
    }
    
    ~Point() 
    {
        cout << "destructor on " << x << " " << y << " is called!" << endl;
    }
};

int main() 
{
    int x, y;
    cout << "enter vals:" << endl;
    cin >> x >> y;
    
    Point p1(x, y);
    p1.display();
    
    Point p2 = p1;
    p2.display();
    
    cout << "end!" << endl;
    return 0;
}