#ifndef _BANK_H_
#define _BANK_H_

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void SendMoney(void); // Added
void WithdrawMoney(void);
void ShowAllAccInfo(void);
void DeleteAccount(void);
void SendMoney(void);
int GetAccIdx(int);

enum class bank {MAKE = 1, DEPOSIT, SEND, WITHDRAW, INQUIRE, DELETE, EXIT}; // scoped enumeration cannot be used as a constant expression with switch statement
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

#endif // _BANK_H_