#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    void setX(int val) 
    { 
        x = val; 
    }
    void setY(int val) 
    { 
        y = val; 
    }
    int getX() const 
    { 
        return x; 
    }
    int getY() const 
    { 
        return y; 
    }
    
    void display() const 
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    int inputX, inputY;
    Point* points = new Point[3];
    
    cout << "Enter 3 points (x y):\n";
    for(int i = 0; i < 3; i++) {
        cout << "Point " << i + 1 << ": ";
        cin >> inputX >> inputY;
        (points + i)->setX(inputX);
        (points + i)->setY(inputY);
    }
    
    cout << "\nYou entered:\n";
    for(int i = 0; i < 3; i++) {
        (points + i)->display();
    }
    
    delete[] points;
    points = nullptr;
    return 0;
}