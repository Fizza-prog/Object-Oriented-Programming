#include <iostream>
using namespace std;

class Counter {
private:
    static int count;
public:
    Counter() 
    { 
        count++; 
    }
    
    static void increment() 
    {
        count++;
    }
    
    static void showCount() 
    {
        cout << "Current count is: " << count << endl;
    }
};

int Counter::count = 0;

int main() {
    Counter::increment();
    Counter::increment();
    Counter::showCount();
    
    Counter c1, c2;
    Counter::increment();
    c1.showCount();
    
    return 0;
}