/*
Bank Program v0.5
*/
#ifndef _BANKCOMMON_H_
#define _BANKCOMMON_H_

enum bank {MAKE = 1, DEPOSIT, SEND, WITHDRAW, INQUIRE, DELETE, EXIT}; // scoped enumeration cannot be used as a constant expression with switch statement
const int NAME_LEN = 40;
const int MAX_ACC_NUM = 100;

#endif