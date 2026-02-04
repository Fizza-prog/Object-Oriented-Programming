#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point() 
    {
        x = 0;
        y = 0;
    }
    
    Point(int a) 
    {
        x = a;
        y = 0;
    }
    
    Point(int a, int b) 
    {
        x = a;
        y = b;
    }
    
    void display() 
    {
        cout << "x = " << x << ", y = " << y << endl;
    }
};

int main() {
    Point p1;
    Point p2(5);
    Point p3(3, 7);
    
    p1.display();
    p2.display();
    p3.display();
    
    return 0;
}