#ifndef _HANDLER_H_
#define _HANDLER_H_

#include "Account.h"
#include <iostream>
using namespace std;

class AccountHandler {
private:
    Account* accArr; // Account array
    int accNum;      // # of accounts
    
    int GetAccIdx(int);
public: 
    AccountHandler() : accArr{new Account[MAX_ACC_NUM]}, accNum{0} {}
    ~AccountHandler() {
        delete[] accArr;
        cout << "AccountHandler Destructor Called" << endl;
    }
    void ShowMenu(void);
    void MakeAccount(void);
    void DepositMoney(void);
    void SendMoney(void); // Added
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    void DeleteAccount(void);
};

#endif