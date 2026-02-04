#include<iostream>
using namespace std;

class Temperature {
private:
    double kelvin;
public:
    void setKelvin(double x) { kelvin = x; }
    void setCelcius(double x) { kelvin = x + 273.15; }
    void setFahrenheit(double x) { kelvin = (x - 32) * 5.0/9 + 273.15; }
    
    double toCelcius() { return kelvin - 273.15; }
    double toFahrenheit() { return (kelvin - 273.15) * 9.0/5 + 32; }
    
    void print() {
        cout << "kelvin: " << kelvin << endl;
        cout << "celcius: " << toCelcius() << endl;
        cout << "fahrenheit: " << toFahrenheit() << endl;
    }
};

int main() {
    Temperature t1, t2, t3;
    double var;
    
    cout << "Enter the temperature in kelvin scale: ";
    cin >> var; t1.setKelvin(var);
    
    cout << "Enter the temperature in celcius scale: ";
    cin >> var; t2.setCelcius(var);
    
    cout << "Enter the temperature in fahrenheit scale: ";
    cin >> var; t3.setFahrenheit(var);
    
    cout << endl;
    t1.print();
    t2.print();
    t3.print();
    
    return 0;
}