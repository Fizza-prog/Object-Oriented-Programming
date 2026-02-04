#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "String.h"
#include <iostream>
using namespace std;

class Account {
protected:
    String customer;
    double balance;
    double interestRate;

public:
    Account(const String& c = "", double b = 0.0, double ir = 0.0);

    String getCustomer() const;
    double getBalance() const;
    double getInterestRate() const;

    void setBalance(double b);
    void setInterestRate(double ir);  

    virtual void depositMoney(double amt);
    virtual void withdrawMoney(double amt);
    virtual void calcInterest(int months) = 0;

    virtual ~Account() {}
};

#endif