#include<iostream>
using namespace std;

class Complex {
private:
    int x;
    int y;
public:
    void setX(int v) 
    {
         x = v; 
    }
    void setY(int v) 
    { 
        y = v; 
    }
    int getx() const 
    { 
        return x;
    }
    int gety() const
    { 
        return y; 
    }
};

int main() {
    int x, y;
    Complex *points = new Complex[3];
    
    for(int i = 0; i < 3; i++) {
        cout << "points " << i+1 << endl;
        cin >> x >> y;
        points[i].setX(x);
        points[i].setY(y);
    }
    
    cout << "the points entered are:" << endl;
    for(int i = 0; i < 3; i++) {
        cout << "( " << points[i].getx() << " , " << points[i].gety() << " )" << endl;
    }
    
    delete[] points;
    points = nullptr;
}