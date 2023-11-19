#include "HighCreditAccount.h"
#include <cmath>

void HighCreditAccount::Deposit(int money) {
    int total = m_rate + m_srate[m_srate_type - 1];
    double exact_balance = money * (1 + total / 100.0);
    balance =  round(exact_balance);
}