#include<iostream>
using namespace std;

class Record {
private:
    int age;
    double height;
public:
    void setAge(int val) { age = val; }
    void setHeight(double val) { height = val; }
    int showAge() { return age; }
    double showHeight() { return height; }
    
    void displayOutput() {
        cout << "the age is: " << showAge() << endl;
        cout << "the height is: " << showHeight();
    }
};

int main() {
    Record r1;
    int temp1;
    double temp2;
    
    cout << "enter the age and height:" << endl;
    cin >> temp1 >> temp2;
    r1.setAge(temp1);
    r1.setHeight(temp2);
    r1.displayOutput();
    
    return 0;
}