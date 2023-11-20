#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_

#include "Account.h"
#include <iostream>
using namespace std;

class SavingAccount : public Account {
protected:
    int m_rate;
public:
    SavingAccount() : m_rate{0} {}
    SavingAccount(int rate) : m_rate{rate} {}
    SavingAccount(int id, int bal, const char* name, int rate) : Account(id, bal, name), m_rate{rate} {}
    
    void Deposit(int) override;
    
};

#endif