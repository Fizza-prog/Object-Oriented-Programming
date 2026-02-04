#include<iostream>
using namespace std;

struct ComplexNumber {
    int real;
    int imaginary;
};

void readComplex(ComplexNumber &c) 
{
    cout << "Enter real part: ";
    cin >> c.real;
    cout << "Enter imaginary part: ";
    cin >> c.imaginary;
}

int main() 
{
    ComplexNumber num;
    readComplex(num);
    cout << "\nComplex Number: " << num.real << " + " << num.imaginary << "i" << endl;
    return 0;
}