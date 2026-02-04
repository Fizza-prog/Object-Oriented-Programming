#include <iostream>
using namespace std;

class Student {
private:
    const int rollNumber;
    string name;
public:
    Student(int r, string n) : rollNumber(r), name(n) {}
    
    void display() const 
    {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
    }
    
    void changeName(string newName) 
    {
        name = newName;
    }
};

int main() {
    Student s1(101, "Alice");
    s1.display();
    s1.changeName("Alicia");
    s1.display();
    return 0;
}