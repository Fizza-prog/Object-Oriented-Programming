#include<iostream>
#include<string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

int main() {
    Employee *array = new Employee[5];
    
    cout << "Enter data for five employees:" << endl;
    for(int i = 0; i < 5; i++) 
    {
        cout << "\nEMPLOYEE " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, array[i].name);
        cout << "ID: ";
        cin >> array[i].id;
        cout << "Salary: ";
        cin >> array[i].salary;
    }
    
    cout << "\nEmployee Details:" << endl;
    for(int i = 0; i < 5; i++) 
    {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        cout << "Name: " << array[i].name << endl;
        cout << "ID: " << array[i].id << endl;
        cout << "Salary: " << array[i].salary << endl;
    }
    
    delete[] array;
    array = nullptr;
    
    return 0;
}