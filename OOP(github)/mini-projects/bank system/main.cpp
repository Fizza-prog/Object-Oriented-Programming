#include <iostream>
#include "Account.h"
#include "DepositAccount.h"
#include "LoanAccount.h"
#include "MortgageAccount.h"

using namespace std;

int main() {
    Account* accounts[3];

    accounts[0] = new DepositAccount("John Doe", 2000.0, 5.0);
    accounts[1] = new LoanAccount("Jane Smith", 10000.0, 4.5);
    accounts[2] = new MortgageAccount("Alice Johnson", 50000.0, 3.0);

    cout << "Initial account balances and interest calculation:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << accounts[i]->getCustomer()
            << " | Balance: " << accounts[i]->getBalance() << endl;
        accounts[i]->calcInterest(12);  
        cout << endl;
    }

    cout << "\nPerforming transactions (deposit/withdraw) using base pointers:" << endl;
    accounts[0]->depositMoney(500.0);  // DepositAccount
    accounts[1]->withdrawMoney(200.0); // LoanAccount
    accounts[2]->depositMoney(2000.0); // MortgageAccount

    cout << "\nBalances after transactions:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << accounts[i]->getCustomer()
            << " | Balance: " << accounts[i]->getBalance() << endl;
        accounts[i]->calcInterest(12);  
        cout << endl;
    }

    for (int i = 0; i < 3; i++) {
        delete accounts[i];
    }

    return 0;
}
