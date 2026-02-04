#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    
    Point(int a, int b) 
    {
        x = a;
        y = b;
    }
    
    void display() 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() 
{
    Point points[3] = { {1, 2}, {3, 4}, {5, 6} };
    
    cout << "Displaying points:\n";
    for(int i = 0; i < 3; i++) 
    {
        cout << "Point " << i << ": ";
        points[i].display();
    }
    
    return 0;
}