#include<iostream>
using namespace std;

struct Student {
    int *rollNo;
    int *marks;
};

int main() 
{
    Student *s = new Student;
    s->marks = new int;
    s->rollNo = new int;
    
    cout << "Enter Student Details:" << endl;
    cout << "Roll Number: ";
    cin >> *(s->rollNo);
    cout << "Marks: ";
    cin >> *(s->marks);
    
    cout << "\nStudent Information:" << endl;
    cout << "Roll Number: " << *(s->rollNo) << endl;
    cout << "Marks: " << *(s->marks) << endl;
    
    delete s->marks;
    delete s->rollNo;
    delete s;
    s = nullptr;
    
    return 0;
}