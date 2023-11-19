#ifndef _HIGHCREDITACCOUNT_H_
#define _HIGHCREDITACCOUNT_H_

#include "SavingAccount.h"
#include <iostream>
using namespace std;

class HighCreditAccount : public SavingAccount {
protected:
    int m_srate_type;
    int m_srate[3];
public:
    HighCreditAccount() : m_srate_type{0}, m_srate{7, 4, 2} {}
    HighCreditAccount(int srate_type) : m_srate_type{srate_type}, m_srate{7, 4, 2} {}
    HighCreditAccount(int rate, int srate_type) : SavingAccount(rate), m_srate_type{srate_type}, m_srate{7, 4, 2} {}
    HighCreditAccount(int id, int bal, const char* name, int rate, int srate_type) : SavingAccount(id, bal, name, rate), m_srate_type{srate_type}, m_srate{7, 4, 2} {}

    void Deposit(int) override;
};

#endif