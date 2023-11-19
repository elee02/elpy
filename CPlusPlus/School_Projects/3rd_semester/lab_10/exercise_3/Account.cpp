#include "Account.h"
#include <iostream>
using namespace std;

int Account::getID() const {
	return accID;
}
void Account::setID(int new_id) {
	accID = new_id;
}
int Account::getBalance() const {
	return balance;
}
void Account::setBalance(int new_balance) {
	balance = new_balance;
}
char* Account::getName() const {
	return cusName;
}
void Account::setName(const char* new_name) {
	strcpy(cusName, new_name);
}