#include<iostream>
#include<string>
using namespace std;

struct Employee {
    string name;
    int id;
    double salary;
};

void printEmployees(Employee empList[], int size);

int main() {
    Employee array[3];
    
    for(int i = 0; i < 3; i++) 
    {
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, array[i].name);
        cout << "ID: ";
        cin >> array[i].id;
        cout << "Salary: ";
        cin >> array[i].salary;
        cin.ignore();
    }
    
    printEmployees(array, 3);
    
    return 0;
}

void printEmployees(Employee empList[], int size) 
{
    for(int i = 0; i < size; i++) 
    {
        cout << "\nEmployee " << i + 1 << ":" << endl;
        cout << "Name: " << empList[i].name << endl;
        cout << "ID: " << empList[i].id << endl;
        cout << "Salary: " << empList[i].salary << endl;
    }
}