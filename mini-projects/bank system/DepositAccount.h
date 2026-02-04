#ifndef DEPOSITACCOUNT_H
#define DEPOSITACCOUNT_H

#include "Account.h"

class DepositAccount : public Account {
public:
    DepositAccount(const String& c = "", double b = 0.0, double ir = 0.0)
        : Account(c, b, ir) {}

    void calcInterest(int months) override;
};

#endif
