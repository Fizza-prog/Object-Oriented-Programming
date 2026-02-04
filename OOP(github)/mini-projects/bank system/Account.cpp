#include "Account.h"

Account::Account(const String& c, double b, double ir)
    : customer(c), balance(b), interestRate(ir) {}

String Account::getCustomer() const { return customer; }
double Account::getBalance() const { return balance; }
double Account::getInterestRate() const { return interestRate; }
void Account::setBalance(double b) { balance = b; }
void Account::setInterestRate(double ir) { interestRate = ir; }  

void Account::depositMoney(double amt) {
    if (amt > 0) balance += amt;
}

void Account::withdrawMoney(double amt) {
    if (amt > 0 && amt <= balance) balance -= amt;
}