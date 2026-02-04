#include<iostream>
using namespace std;

class Matrix {
private:
    int m[2][2];
    int s[2][2];
public:
    void read() 
    {
        cout << "enter elements of matrix:" << endl;
        for(int i = 0; i < 2; i++) 
        {
            for(int j = 0; j < 2; j++) 
            {
                cin >> m[i][j];
            }
        }
    }
    
    void calcSum(Matrix m1, Matrix m2) 
    {
        for(int i = 0; i < 2; i++) 
        {
            for(int j = 0; j < 2; j++) 
            {
                s[i][j] = m1.m[i][j] + m2.m[i][j];
            }
        }
        
        for(int i = 0; i < 2; i++) 
        {
            for(int j = 0; j < 2; j++) 
            {
                cout << s[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix m1, m2, sum;
    
    cout << "enter first matrix:" << endl;
    m1.read();
    
    cout << "enter second matrix:" << endl;
    m2.read();
    
    cout << "the sum of both matrices is:" << endl;
    sum.calcSum(m1, m2);
    
    return 0;
}