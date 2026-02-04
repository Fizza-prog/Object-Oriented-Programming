#include<iostream>
using namespace std;

struct Box {
    double length;
    double width;
    double height;
};

void scaleBox(Box &b, float factor) 
{
    b.length *= factor;
    b.width *= factor;
    b.height *= factor;
}

int main() {
    Box myBox;
    float factor;
    
    cout << "Enter box dimensions:" << endl;
    cout << "Length: ";
    cin >> myBox.length;
    cout << "Width: ";
    cin >> myBox.width;
    cout << "Height: ";
    cin >> myBox.height;
    
    cout << "\nEnter scaling factor: ";
    cin >> factor;
    
    scaleBox(myBox, factor);
    
    cout << "\nScaled Box Dimensions:" << endl;
    cout << "Length: " << myBox.length << endl;
    cout << "Width: " << myBox.width << endl;
    cout << "Height: " << myBox.height << endl;
    
    return 0;
}