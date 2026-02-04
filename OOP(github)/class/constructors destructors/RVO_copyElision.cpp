#include<iostream>
using namespace std;

class Sample {
private:
    int num;
public:
    Sample() 
    { 
        cout << "default constructor " << this << endl; 
    }
    Sample(int n) 
    { 
        cout << "overloading constructor " << this << endl; num = n; 
    }
    ~Sample() 
    { 
        cout << "destructor " << this << endl; 
    }
    Sample(const Sample & orig) 
    { 
        cout << "copy constructor " << this << endl; num = orig.num; 
    }
    
    void display() 
    { 
        cout << "in display: " << num << endl; 
    }
};

Sample testing() {
    Sample s(15);
    return s;
}

int main() {
    cout << "SCENARIO A!" << endl << endl;
    Sample s1;
    s1 = testing();
    s1.display();
    
    cout << "\nSCENARIO B!" << endl << endl;
    Sample s2 = testing();
    s2.display();
    
    return 0;
}