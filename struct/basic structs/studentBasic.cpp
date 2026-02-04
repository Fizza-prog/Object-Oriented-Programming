#include<iostream>
#include<string>
using namespace std;

struct Student {
    string name;
    int rollNo;
    double percentage;
};

int main() {
    Student s1 = {"Alice Johnson", 101, 92.5};
    
    cout << "Student Name: " << s1.name << endl;
    cout << "Roll Number: " << s1.rollNo << endl;
    cout << "Percentage: " << s1.percentage << "%" << endl;
    
    return 0;
}