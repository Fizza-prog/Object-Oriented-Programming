#include<iostream>
#include<cmath>
#include<random>
#include<ctime>
using namespace std;

class Point {
private:
    int x;
    int y;
    int dis;
public:
    void setX(int val) 
    { 
        x = val; 
    }
    void setY(int val) 
    { 
        y = val; 
    }
    
    int calcDis() 
    {
        dis = sqrt((x*x) + (y*y));
        return dis;
    }
    
    int returnX() 
    { 
        return x; 
    }
    int returnY() 
    { 
        return y; 
    }
    
    void displayInfo() 
    {
        cout << "X coordinate: " << returnX() << endl;
        cout << "Y coordinate: " << returnY() << endl;
        cout << "Distance calculated: " << calcDis() << endl;
    }
};

int main() {
    srand(time(0));
    Point p;
    int n, temp1, temp2, input;
    
    cout << "enter the size of array: " << endl;
    cin >> n;
    Point *array = new Point[n];
    
    cout << "Initializing points with random values!" << endl;
    for(int i = 0; i < n; i++) {
        temp1 = (rand() % 9);
        p.setX(temp1);
        temp2 = (rand() % 9);
        p.setY(temp2);
        cout << "( " << p.returnX() << " , " << p.returnY() << ") ";
    }
    
    cout << endl << "Now asking for user input!" << endl;
    for(int i = 0; i < n; i++) {
        cout << "point " << i+1 << ":" << endl;
        cout << "x coordinate: "; cin >> input; array[i].setX(input);
        cout << "y coordinate: "; cin >> input; array[i].setY(input);
        array[i].displayInfo();
    }
    
    delete[] array;
    array = nullptr;
    return 0;
}