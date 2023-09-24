#include <iostream>
#include "bank.h"
using namespace std;

Account accArr[MAX_ACC_NUM]; // Account array
int accNum = 0;      // # of accounts

void ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Send Money" << endl; // Added
	cout << "4. Withdrawal" << endl;
	cout << "5. Display all" << endl;
	cout << "6. Delete account" << endl;
	cout << "7. Exit program" << endl;
}

void MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;

	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}

	cout << "[Make Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cin.ignore(100, '\n');
	cout << "Customer Name: ";
	cin.getline(name,40);
	cout << "Deposit amount: ";
	cin >> balance;
	cout << endl;

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl;
		return;
	}

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

void DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "Deposit completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance" << endl << endl;
				return;
			}

			accArr[i].balance -= money;
			cout << "Withdrawal completed" << endl << endl;
			return;
		}
	}
	cout << "This ID is not valid." << endl << endl;
}

void DeleteAccount(void) {
	int id;
	cout << "[Delete Account]" << endl;
	cout << "Account ID (0 to delete all accounts): ";
	cin >> id;

	if (id == 0) {
		accNum = 0;
		cout << "All accounts have been deleted." << endl << endl;
		return;
	}

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			for (int j = i; j < accNum - 1; j++) {
				accArr[j] = accArr[j + 1];
			}
			accNum--;
			cout << "Account " << id << " has been deleted." << endl << endl;
			return;
		}
	}
	cout << "Account " << id << " not found." << endl << endl;
}

void SendMoney(void) {
	int money;
	int sender, receiver;
	cout << "[Send Money]" << endl;
	cout << "Withdrawal Account ID: ";
	cin >> sender;
	cout << "Receiving Account: ";
	cin >> receiver;
	if (sender == receiver) {
		cout << "Cannot send money to the same account." << endl << endl;
		return;
	}
	cout << "Amount: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == sender) {
			if (accArr[i].balance < money) {
				cout << "Not enough balance" << endl << endl;
				return;
			}
			for (int j = 0; j < accNum; j++) {
				if (accArr[j].accID == receiver) {
					accArr[j].balance += money;
					break;
				}
				if ((j == accNum - 1) && (accArr[j].accID != receiver)) {
					cout << "Invalid Receiving Account!" << endl << endl;
					return;
				}
			}
			accArr[i].balance -= money;
			cout << "Send completed" << endl << endl;
			return;
		}
	}
	cout << "Invalid Withdrawal Account!" << endl << endl;
}

void ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i].accID << endl;
		cout << "Name: " << accArr[i].cusName << endl;
		cout << "Balance: " << accArr[i].balance << endl << endl;
	}
	if (accNum == 0) {
		cout << "No accounts exist." << endl << endl;
	}
}

int GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			return i;
		}
	}
	return -1;
}