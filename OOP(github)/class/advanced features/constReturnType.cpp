#include <iostream>
using namespace std;

class MyClass {
private:
    int value;
public:
    MyClass(int v) : value(v) {}
    
    const int getValue() 
    {
        return value;
    }
    
    const int* getValuePtr() const 
    {
        return &value;
    }
    
    int* getUnsafeValuePtr() 
    {
        return &value;
    }
};

int main() {
    MyClass obj(42);
    const int result = obj.getValue();
    int res = obj.getValue();
    
    cout << "Returned value received by const var: " << result << endl;
    cout << "Returned value received by non-const var: " << res << endl;
    
    res = 24;
    cout << "Modified res (copy): " << res << endl;
    
    const int* safePtr = obj.getValuePtr();
    cout << "Value via safe const pointer: " << *safePtr << endl;
    
    int* unsafePtr = obj.getUnsafeValuePtr();
    *unsafePtr = 999;
    cout << "Modified private member via unsafe pointer: " << obj.getValue() << endl;
    
    return 0;
}