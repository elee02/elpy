#include "SavingAccount.h"
#include <cmath>

void SavingAccount::Deposit(int money) {
    double exact_balance = money * (1 + m_rate / 100.0);
    balance = round(exact_balance);
}