#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "Account.h"
#include <iostream>
using namespace std;

class AccountHandler {
private:
    Account* accArr[MAX_ACC_NUM]; // Account array
    int accNum;      // # of accounts
    int accType;
    
    int GetAccIdx(int);
public: 
    AccountHandler() : accNum{0} {
        for (int i = 0; i < MAX_ACC_NUM; i++) {
            accArr[i] = new Account();
        }
    }
    ~AccountHandler() {
        for (int i = 0; i < MAX_ACC_NUM; i++) {
            delete accArr[i];
        }
        cout << "AccountHandler Destructor Called" << endl;
    }
    void ShowMenu(void);

    void MakeAccount(void);
    void MakeSavingAccount(int&, int&, char*);
    void MakeHighCreditAccount(int&, int&, char*);

    void DepositMoney(void);
    void SendMoney(void); // Added
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    void DeleteAccount(void);
};

#endif