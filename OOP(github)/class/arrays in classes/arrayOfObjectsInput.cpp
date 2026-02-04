#include <iostream>
using namespace std;

class Point {
public:
    int x, y;
    
    Point() {
        x = 0;
        y = 0;
    }
    
    void input() 
    {
        cout << "Enter x and y: ";
        cin >> x >> y;
    }
    
    void display() const 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    const int SIZE = 3;
    Point points[SIZE];
    
    for(int i = 0; i < SIZE; i++) 
    {
        cout << "Point " << i + 1 << ": ";
        points[i].input();
    }
    
    cout << "\nPoints entered:\n";
    for(int i = 0; i < SIZE; i++) 
    {
        cout << "Point " << i + 1 << ": ";
        points[i].display();
    }
    
    return 0;
}