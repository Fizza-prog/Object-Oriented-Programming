#include<iostream>
using namespace std;

class Student {
private:
    int sub1;
    int sub2;
    int sub3;
public:
    void set1(int m) 
    { 
        sub1 = m; 
    }
    void set2(int m) 
    { 
        sub2 = m; 
    }
    void set3(int m) 
    { 
        sub3 = m; 
    }
    
    int get1() const 
    { 
        return sub1; 
    }
    int get2() const 
    { 
        return sub2; 
    }
    int get3() const 
    { 
        return sub3; 
    }
    
    int total(int m1, int m2, int m3) 
    {
        return m1 + m2 + m3;
    }
};

int main() {
    int in1, in2, in3;
    Student s;
    int sum[3];
    Student array[3];
    
    for(int i = 0; i < 3; i++) 
    {
        cout << "student " << i+1 << endl;
        cout << "sub1: "; cin >> in1; array[i].set1(in1);
        cout << "sub2: "; cin >> in2; array[i].set2(in2);
        cout << "sub3: "; cin >> in3; array[i].set3(in3);
        sum[i] = s.total(in1, in2, in3);
    }
    
    cout << "the info u entered:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        cout << "student " << i+1 << endl;
        cout << "sub1: " << array[i].get1() << endl;
        cout << "sub2: " << array[i].get2() << endl;
        cout << "sub3: " << array[i].get3() << endl;
    }
    
    cout << "the total of scores is:" << endl;
    for(int i = 0; i < 3; i++) 
    {
        cout << "student " << i+1 << ": " << sum[i] << endl;
    }
}