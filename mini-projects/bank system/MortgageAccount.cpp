#include "MortgageAccount.h"
#include <iostream>
using namespace std;

void MortgageAccount::depositMoney(double amt) {
    if (amt > 0) balance -= amt;
}

void MortgageAccount::withdrawMoney(double amt) {
    if (amt > 0) balance += amt;
}

void MortgageAccount::calcInterest(int months) {
    double interest = balance * (interestRate / 100.0) * months;
    cout << "Mortgage Account Interest: " << interest << endl;
}
