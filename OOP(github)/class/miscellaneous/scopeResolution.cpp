#include<iostream>
using namespace std;

class Rect {
private:
    int l;
    int w;
public:
    void setl(int);
    void setw(int);
    int retl();
    int retw();
    void calcArea(int, int);
};

void Rect::setl(int v) 
{
    l = v;
}

void Rect::setw(int v) 
{
    w = v;
}

int Rect::retl() 
{
    return l;
}

int Rect::retw() 
{
    return w;
}

void Rect::calcArea(int l, int w) 
{
    cout << "area is " << l * w;
}

int main() {
    Rect r;
    int i, i2;
    
    cout << "enter length: "; cin >> i; r.setl(i);
    cout << "enter width: "; cin >> i2; r.setw(i2);
    
    cout << "info entered is:" << endl;
    cout << r.retl() << " " << r.retw() << endl;
    r.calcArea(i, i2);
    
    return 0;
}