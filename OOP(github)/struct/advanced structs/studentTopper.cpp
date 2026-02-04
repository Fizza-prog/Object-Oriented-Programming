#include<iostream>
#include<string>
using namespace std;

struct Student {
    int roll;
    string name;
    double marks;
};

Student getTopper(Student students[], int size) 
{
    Student topper = students[0];
    
    for(int i = 1; i < size; i++) 
    {
        if(students[i].marks > topper.marks) 
        {
            topper = students[i];
        }
    }
    
    return topper;
}

int main() {
    int n;
    
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    
    Student *students = new Student[n];
    
    for(int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, students[i].name);
        cout << "Roll Number: ";
        cin >> students[i].roll;
        cout << "Marks: ";
        cin >> students[i].marks;
        cin.ignore();
    }
    
    Student topper = getTopper(students, n);
    
    cout << "\n TOPPER " << endl;
    cout << "Name: " << topper.name << endl;
    cout << "Roll Number: " << topper.roll << endl;
    cout << "Marks: " << topper.marks << endl;
    
    delete[] students;
    return 0;
}