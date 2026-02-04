#include "LoanAccount.h"
#include <iostream>
using namespace std;

void LoanAccount::depositMoney(double amt) {
    if (amt > 0) balance -= amt; // paying loan reduces balance
}

void LoanAccount::withdrawMoney(double amt) {
    if (amt > 0) balance += amt; // taking more loan increases balance
}

void LoanAccount::calcInterest(int months) {
    double interest = balance * (interestRate / 100.0) * months;
    cout << "Loan Account Interest: " << interest << endl;
}
