/*
Bank Program v0.4
*/
#ifndef _BANK_H_
#define _BANK_H_

#include <iostream>
#include <cstring>
using namespace std;

enum bank {MAKE = 1, DEPOSIT, SEND, WITHDRAW, INQUIRE, DELETE, EXIT}; // scoped enumeration cannot be used as a constant expression with switch statement
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

class AccountHandler;

class Account {
private:
    int accID{0};
    int balance{0};
    char* cusName{nullptr};
    friend class AccountHandler;
public:
    Account() {
        cusName = new char[NAME_LEN];
    }
    Account(int id, int bal,const char* name)
    : accID {id}, balance {bal} {
        cusName = new char[NAME_LEN];
        strncpy(cusName, name, NAME_LEN);
    }
    Account(const Account& arr) : accID{arr.accID}, balance{arr.balance} {
        strncpy(cusName, arr.cusName, NAME_LEN);
    }
    Account& operator=(const Account& arr) {
        accID = arr.accID;
        balance = arr.balance;
        for (int i = 0; i < NAME_LEN; ++i) {
            cusName[i] = arr.cusName[i];
        }
        return *this;
    }
    ~Account() {
        cout << "Name '";
        if (cusName != nullptr) {
            for (int i = 0; i < NAME_LEN; ++i) 
                cout << cusName[i];
            delete[] cusName;        
        }
        cout <<  "' is deleted!" << endl;
    }

    int getID() const;
    void setID(int);

    int getBalance() const;
    void setBalance(int);

    char* getName() const;
    void setName(const char*);
};


class AccountHandler {
private:
    Account* accArr[MAX_ACC_NUM]; // Account array
    int accNum = 0;      // # of accounts
    
    int GetAccIdx(int);
public:
    void ShowMenu(void);
    void MakeAccount(void);
    void DepositMoney(void);
    void SendMoney(void); // Added
    void WithdrawMoney(void);
    void ShowAllAccInfo(void);
    void DeleteAccount(void);
    void SendMoney(void);
};

#endif // _BANK_H_