#include <iostream>
#include <fstream>
using namespace std;

class Student {
private:
    int rollNumber;
    string name;
public:
    Student() : rollNumber(0), name("") {}
    Student(int r, string n) : rollNumber(r), name(n) {}
    
    void display() const 
    {
        cout << "Roll Number: " << rollNumber << ", Name: " << name << endl;
    }
    
    void writeToFile(ofstream& outFile) const 
    {
        outFile << rollNumber << "\n" << name << "\n";
    }
    
    void readFromFile(ifstream& inFile) 
    {
        inFile >> rollNumber;
        inFile.ignore();
        getline(inFile, name);
    }
};

int main() {
    Student s1(101, "Alice");
    Student s2(102, "Bob");
    
    ofstream outFile("students.txt");
    if(!outFile) {
        cerr << "Error opening file for writing." << endl;
        return 1;
    }
    
    s1.writeToFile(outFile);
    s2.writeToFile(outFile);
    outFile.close();
    
    ifstream inFile("students.txt");
    if(!inFile) {
        cerr << "Error opening file for reading." << endl;
        return 1;
    }
    
    Student s3, s4;
    s3.readFromFile(inFile);
    s4.readFromFile(inFile);
    inFile.close();
    
    cout << "Read objects from file:" << endl;
    s3.display();
    s4.display();
    
    return 0;
}