#include <iostream>
using namespace std;

class MyClass {
    int* arr;
    int size;
public:
    MyClass(int* inputArr, int s) 
    {
        size = s;
        arr = new int[size];
        
        for(int i = 0; i < size; i++) 
        {
            arr[i] = inputArr[i];
        }
        
        cout << "Array stored in class: ";
        for(int i = 0; i < size; i++) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
    ~MyClass() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    
    int* myArr = new int[size];
    cout << "Enter " << size << " elements: ";
    
    for(int i = 0; i < size; i++) {
        cin >> myArr[i];
    }
    
    MyClass obj(myArr, size);
    delete[] myArr;
    
    return 0;
}