#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}
    
    int getValue() const 
    {
        return value;
    }
    
    void setValue(int v) 
    {
        value = v;
    }
};

int main() {
    const MyClass obj1(10);
    cout << "Value from const object: " << obj1.getValue() << endl;
    
    MyClass obj2(30);
    obj2.setValue(40);
    cout << "Value from non-const object: " << obj2.getValue() << endl;
    
    return 0;
}