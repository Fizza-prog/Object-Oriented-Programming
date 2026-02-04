#ifndef LOANACCOUNT_H
#define LOANACCOUNT_H

#include "Account.h"

class LoanAccount : public Account {
public:
    LoanAccount(const String& c = "", double b = 0.0, double ir = 0.0)
        : Account(c, b, ir) {}

    void depositMoney(double amt) override;
    void withdrawMoney(double amt) override;
    void calcInterest(int months) override;
};

#endif
