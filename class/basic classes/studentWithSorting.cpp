#include <iostream>
#include <algorithm>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int test1, test2, test3;
public:
    void setDetails(int r, string n, int t1, int t2, int t3)
    {
        rollNo = r;
        name = n;
        test1 = t1;
        test2 = t2;
        test3 = t3;
    }
    
    int getTotal() const 
    { 
        return test1 + test2 + test3; 
    }
    double getAverage() const 
    { 
        return getTotal() / 3.0; 
    }
    
    void printDetails() const 
    {
        cout << "Roll No: " << rollNo << ", Name: " << name
             << ", Scores: " << test1 << ", " << test2 << ", " << test3
             << ", Total: " << getTotal()
             << ", Average: " << getAverage() << endl;
    }
};

int main() {
    const int SIZE = 10;
    Student students[SIZE];
    
    cout << "Enter data for 10 students (roll no, name, 3 test scores):\n";
    
    for(int i = 0; i < SIZE; i++) {
        int r, t1, t2, t3;
        string n;
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll No: "; cin >> r;
        cout << "Name: "; cin >> ws; getline(cin, n);
        cout << "Enter 3 test scores: "; cin >> t1 >> t2 >> t3;
        students[i].setDetails(r, n, t1, t2, t3);
    }
    
    sort (students, students + SIZE, [](const Student &a, const Student &b) {
        return a.getAverage() > b.getAverage();
    });
    
    cout << "\n Sorted Students by Average (High to Low) \n";
    for(int i = 0; i < SIZE; i++) 
    {
        students[i].printDetails();
    }
    
    double totalAvg = 0;
    for(int i = 0; i < SIZE; i++) 
    {
        totalAvg += students[i].getAverage();
    }
    totalAvg /= SIZE;
    
    cout << "\nClass Average Score: " << totalAvg << endl;
    cout << "\n Top Scorer \n";
    students[0].printDetails();
    
    return 0;
}