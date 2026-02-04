#include<iostream>
#include<cmath>
using namespace std;

struct Distance {
    int feet;
    double inches;
};

Distance sumDistances(Distance d1, Distance d2)
{
    Distance result;
    result.feet = d1.feet + d2.feet;
    result.inches = d1.inches + d2.inches;
    
    if(result.inches >= 12) 
    {
        result.feet += (int)(result.inches / 12);
        result.inches = fmod(result.inches, 12.0);
    }
    
    return result;
}

int main() {
    Distance d1, d2, sum;
    
    cout << "Enter first distance:" << endl;
    cout << "Feet: ";
    cin >> d1.feet;
    cout << "Inches: ";
    cin >> d1.inches;
    
    cout << "\nEnter second distance:" << endl;
    cout << "Feet: ";
    cin >> d2.feet;
    cout << "Inches: ";
    cin >> d2.inches;
    
    sum = sumDistances(d1, d2);
    
    cout << "\nSum of distances: " << sum.feet << " feet " << sum.inches << " inches" << endl;
    
    return 0;
}