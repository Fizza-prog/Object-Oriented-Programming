#include<iostream>
#include<string>
using namespace std;

struct Subject {
    string name;
    int marks;
};

struct Student {
    string name;
    int rollNO;
    Subject subjects[5];
    int total = 0;
    double percentage;
    char grade;
};

int main() {
    Student s;
    
    cout << "Enter student name: ";
    getline(cin, s.name);
    cout << "Enter roll number: ";
    cin >> s.rollNO;
    cin.ignore();
    
    cout << "\nEnter marks for 5 subjects (out of 100):" << endl;
    for(int i = 0; i < 5; i++) 
    {
        cout << "\nSubject " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, s.subjects[i].name);
        cout << "Marks: ";
        cin >> s.subjects[i].marks;
        cin.ignore();
        s.total += s.subjects[i].marks;
    }
    
    s.percentage = (s.total / 500.0) * 100;
    
    if(s.percentage >= 90) s.grade = 'A';
    else if(s.percentage >= 80) s.grade = 'B';
    else if(s.percentage >= 70) s.grade = 'C';
    else if(s.percentage >= 60) s.grade = 'D';
    else s.grade = 'F';
    
    cout << "\n=== Student Result ===" << endl;
    cout << "Name: " << s.name << endl;
    cout << "Roll No: " << s.rollNO << endl;
    cout << "Total Marks: " << s.total << "/500" << endl;
    cout << "Percentage: " << s.percentage << "%" << endl;
    cout << "Grade: " << s.grade << endl;
    
    return 0;
}