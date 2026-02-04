#include <iostream>
#define SIZE 5
using namespace std;

class MyClass {
    int arr[SIZE];
public:
    MyClass(int input[]) {
        for(int i = 0; i < SIZE; i++) 
        {
            arr[i] = input[i];
        }
        
        cout << "Array stored in class: ";
        for(int i = 0; i < SIZE; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int myArr[SIZE] = {1, 2, 3, 4, 5};
    MyClass obj(myArr);
    return 0;
}