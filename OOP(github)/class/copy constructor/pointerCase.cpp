#include<iostream>
using namespace std;

class Point {
private:
    int *ptr = new int;
    int val;
public:
    Point() 
    {
        cout << "default constructor called!" << endl;
        val = 0;
        *ptr = 0;
    }
    
    Point(Point &p1) 
    {
        cout << "copy constructor called!" << endl;
        val = p1.val;
        *ptr = *(p1.ptr);
    }
    
    void display() const 
    {
        cout << "display function!" << endl;
        cout << "ptr is: " << *ptr << endl;
        cout << "val is: " << val << endl;
    }
    
    ~Point() 
    {
        cout << "destructor called on: " << *ptr << " " << val << endl;
        delete ptr;
    }
    
    void setval(int v) 
    { 
        val = v; 
    }
    void setptr(int *p) 
    { 
        *ptr = *p; 
    }
};

void myFunc(Point p) 
{
    cout << "my function is called!" << endl;
    p.display();
}

int main() {
    int x;
    Point p1;
    p1.display();
    
    p1.setval(3);
    cout << "enter the ptr val:" << endl;
    cin >> x;
    p1.setptr(&x);
    
    myFunc(p1);
    p1.display();
    
    cout << "program termination!" << endl;
    return 0;
}