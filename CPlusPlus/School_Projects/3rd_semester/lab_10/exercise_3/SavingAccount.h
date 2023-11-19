#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_

#include "Account.h"
#include <iostream>
using namespace std;

class SavingAccount : public Account {
private:
    int m_rate;
public:
    SavingAccount(double rate) : m_rate{rate} {}
};

#endif