#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point();
    Point(int, int);
    Point(int);
    void setX(int);
    void setY(int);
    void setCoordinates(int, int);
    int getX() const;
    int getY() const;
    void displayPoint() const;
    ~Point();
    Point(const Point&);
};

Point::Point() : x(0), y(0) 
{
    cout << "default constructor called!" << endl;
}

Point::Point(int a, int b) : x(a), y(b) 
{
    cout << "overloaded constructor called!(2 parameters)" << endl;
}

Point::Point(int a) : x(a), y(a) 
{
    cout << "overloaded constructor called(1 parameter)" << endl;
}

void Point::setX(int val) 
{ 
    x = val; 
}
void Point::setY(int val) 
{ 
    y = val; 
}
void Point::setCoordinates(int v1, int v2) 
{ 
    setX(v1); 
    setY(v2); 
}
int Point::getX() const 
{ 
    return x; 
}
int Point::getY() const 
{ 
    return y; 
}

void Point::displayPoint() const 
{
    cout << "display function called!" << endl;
    cout << "( " << getX() << " " << getY() << " )" << endl;
}

Point::Point(const Point& orig) 
{
    cout << "copy constructor called!" << endl;
    x = orig.x;
    y = orig.y;
}

Point::~Point() 
{
    cout << "destructor called on " << x << " " << y << "!" << endl;
}

void Display(const Point &p) 
{
    p.displayPoint();
}

void Display2(Point p) 
{
    p.displayPoint();
}

Point createApoint() 
{
    Point temp;
    temp.setCoordinates(40, 70);
    return temp;
}

int main() 
{
    Point pt1;
    Point pt2(10, 20);
    Display(pt2);
    
    Display2(pt2);
    cout << "destructors from main:" << endl;
    
    Point pt3 = pt2;
    Display2(pt3);
    
    Point p1(2, 3);
    cout << "before calling function createApoint:" << endl;
    p1.displayPoint();
    
    p1 = createApoint();
    cout << "after calling function createApoint:" << endl;
    p1.displayPoint();
    
    return 0;
}