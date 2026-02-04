#include "DepositAccount.h"
#include <iostream>
using namespace std;

void DepositAccount::calcInterest(int months) {
    double interest = balance * (interestRate / 100.0) * months;
    cout << "Deposit Account Interest: " << interest << endl;
}
