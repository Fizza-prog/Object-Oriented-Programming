#include <iostream>
using namespace std;

class MyClass {
    int arr[5];
public:
    MyClass() {
        for(int i = 0; i < 5; i++) {
            arr[i] = i * 10;
        }
        
        cout << "Static array initialized in constructor: ";
        for(int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MyClass obj;
    return 0;
}