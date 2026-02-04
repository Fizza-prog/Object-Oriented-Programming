#ifndef MORTGAGEACCOUNT_H
#define MORTGAGEACCOUNT_H

#include "Account.h"

class MortgageAccount : public Account {
public:
    MortgageAccount(const String& c = "", double b = 0.0, double ir = 0.0)
        : Account(c, b, ir) {}

    void depositMoney(double amt) override;
    void withdrawMoney(double amt) override;
    void calcInterest(int months) override;
};

#endif
