#include<iostream>
#include<string>
using namespace std;

struct Date {
    string day;
    int month;
    int year;
};

struct Person {
    string name;
    Date dob;
};

int main() {
    Person people[5];
    
    for(int i = 0; i < 5; i++) {
        cout << "\nEnter details for Person " << i + 1 << ":" << endl;
        cout << "Name: ";
        getline(cin, people[i].name);
        cout << "Date of Birth:" << endl;
        cout << "Day (e.g., Monday): ";
        getline(cin, people[i].dob.day);
        cout << "Month (1-12): ";
        cin >> people[i].dob.month;
        cout << "Year: ";
        cin >> people[i].dob.year;
        cin.ignore();
    }
    
    cout << "\n People Information " << endl;
    for(int i = 0; i < 5; i++) {
        cout << "\nPerson " << i + 1 << ":" << endl;
        cout << "Name: " << people[i].name << endl;
        cout << "Date of Birth: " << people[i].dob.day << ", "
             << people[i].dob.month << "/" << people[i].dob.year << endl;
    }
    
    return 0;
}