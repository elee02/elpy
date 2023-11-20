#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "BankCommon.h"
#include <iostream>
#include <cstring>
using namespace std;

class Account {
protected:
    int accID;
    int balance;
    char* cusName;
    friend class AccountHandler;
public:
    Account() : accID{0}, balance{0}, cusName{new char[NAME_LEN]} {}
    Account(int id, int bal, const char* name)
    : accID {id}, balance {bal}, cusName{new char[NAME_LEN]} {
        strncpy(cusName, name, NAME_LEN);
    }
    Account(const Account& arr) : accID{arr.accID}, balance{arr.balance} {
        strncpy(cusName, arr.cusName, NAME_LEN);
    }
    Account& operator=(const Account& arr) {
        accID = arr.accID;
        balance = arr.balance;
        strncpy(cusName, arr.cusName, NAME_LEN);
        return *this;
    }
    ~Account() {
        cout << "Pointer No_";
        if (cusName != nullptr) {
            for (int i = 0; i < NAME_LEN; ++i) 
                cout << i << ": " << cusName;
            delete[] cusName;        
        }
        cout <<  " is deleted!" << endl;
    }

    virtual void Deposit(int);
    int getID() const;
    void setID(int);

    int getBalance() const;
    void setBalance(int);

    char* getName() const;
    void setName(const char*);
};

#endif