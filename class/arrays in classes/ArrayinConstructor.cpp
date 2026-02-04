#include <iostream>
using namespace std;

class MyClass {
    int arr[5];
public:
    MyClass(int inputArr[]) {
        for(int i = 0; i < 5; i++) {
            arr[i] = inputArr[i];
        }
        
        cout << "Array in class: ";
        for(int i = 0; i < 5; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int myArr[5];
    cout << "Enter 5 numbers: ";
    
    for(int i = 0; i < 5; i++) 
    {
        cin >> myArr[i];
    }
    
    MyClass obj(myArr);
    return 0;
}