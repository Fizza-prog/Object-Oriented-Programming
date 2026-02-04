#include <iostream>
using namespace std;

#define SIZE 5

class MyClass {
public:
    MyClass(int arr1[]) 
    {
        cout << "Stack array received in constructor: ";
        for(int i = 0; i < SIZE; i++) 
        {
            cout << arr1[i] << " ";
        }
        cout << endl;
    }
    
    MyClass(int arr2[], int size) 
    {
        cout << "Heap array received in constructor: ";
        for(int i = 0; i < size; i++) {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int stackArr[SIZE] = {2, 4, 6, 8, 10};
    MyClass obj1(stackArr);
    
    int size = 4;
    int* heapArr = new int[size];
    
    for(int i = 0; i < size; i++) {
        heapArr[i] = (i + 1) * 100;
    }
    
    MyClass obj2(heapArr, size);
    delete[] heapArr;
    
    return 0;
}