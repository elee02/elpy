/*
Bank Program v0.3
*/
#ifndef _BANK_H_
#define _BANK_H_

#include <iostream>
#include <cstring>
using namespace std;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void SendMoney(void); // Added
void WithdrawMoney(void);
void ShowAllAccInfo(void);
void DeleteAccount(void);
void SendMoney(void);
int GetAccIdx(int);

enum bank {MAKE = 1, DEPOSIT, SEND, WITHDRAW, INQUIRE, DELETE, EXIT}; // scoped enumeration cannot be used as a constant expression with switch statement
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

class Account {
private:
    int accID{0};
    int balance{0};
    char* cusName{nullptr};
public:
    Account() : cusName{new char[NAME_LEN]} {}
    Account(int id, int bal,const char* name)
    : accID {id}, balance {bal}, cusName{new char[NAME_LEN]} {
        strncpy(cusName, name, NAME_LEN);
    }
    Account(const Account& arr) : accID{arr.accID}, balance{arr.balance} {
        strncpy(cusName, arr.cusName, NAME_LEN);
    }
    Account& operator=(const Account& arr) {
        if (this != &arr) {
            accID = arr.accID;
            balance = arr.balance;
            delete[] cusName;
            cusName = new char[NAME_LEN];
            strncpy(cusName, arr.cusName, NAME_LEN);
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

#endif // _BANK_H_