#include "AccountHandler.h"
#include "SavingAccount.h"
#include "HighCreditAccount.h"
#include <iostream>
using namespace std;

void AccountHandler::ShowMenu(void) {
	cout << "-----Menu------" << endl;
	cout << "1. Make Accout" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Send Money" << endl; // Added
	cout << "4. Withdrawal" << endl;
	cout << "5. Display all" << endl;
	cout << "6. Delete account" << endl;
	cout << "7. Exit program" << endl;
}

void AccountHandler::MakeAccount(void) {
	int id;
	char name[NAME_LEN];
	int balance;
	if (accNum >= MAX_ACC_NUM) {
		cout << "Sorry! cannot make an accout anymore." << endl;
		return;
	}
	while (true) {
		cout << "[Select Account Type]" << endl;
		cout << "1. Saving Account" << endl;
		cout << "2. High Credit Account" << endl;
		cout << "Select: ";
		cin >> accType;
		switch (accType) {
		case 1:
			MakeSavingAccount(id, balance, name);
			break;
		case 2:
			MakeHighCreditAccount(id, balance, name);
			break;
		default:
			cout << "Illegal Selection" << endl << endl;
			continue;
		}
		break;
	}
	

	if (GetAccIdx(id) != -1) {
		cout << "Error: Existing account ID" << endl << endl;
		return;
	}
	
	accArr[accNum] -> Deposit(balance);
	accNum++;
}

void AccountHandler::MakeSavingAccount(int& id, int& balance, char* name) {
	int int_rate;

	cout << "[Make Saving Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cin.ignore(100, '\n'); 
	cout << "Customer Name: ";
	cin.getline(name,40);
	cout << "Deposit amount: ";
	cin >> balance;
	cout << "Interest Rate: ";
	cin >> int_rate;
	cout << endl;

	accArr[accNum] = new SavingAccount(id, balance, name, int_rate); 
}

void AccountHandler::MakeHighCreditAccount(int& id, int& balance, char* name) {
	int int_rate;
	int cr_rating;

	cout << "[Make High Credit Account]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cin.ignore(100, '\n'); 
	cout << "Customer Name: ";
	cin.getline(name,40);
	cout << "Deposit amount: ";
	cin >> balance;
	cout << "Interest Rate: ";
	cin >> int_rate;
	cout << "Credit Rating (A:1, B:2, C:3): ";
	cin >> cr_rating;
	cout << endl;

	accArr[accNum] = new HighCreditAccount(id, balance, name, int_rate, cr_rating); 
}

void AccountHandler::DepositMoney(void) {
	int money;
	int id;
	cout << "[Deposit]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Deposit amount: ";
	cin >> money;

	int idx = GetAccIdx(id);
	if (idx == -1) {
		cout << "This ID is not valid." << endl << endl;
		return;
	}
	accArr[idx] -> setBalance(accArr[idx] -> getBalance() + money);
	cout << "Deposit completed" << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
	int money;
	int id;
	cout << "[Withdrawal]" << endl;
	cout << "Account ID: ";
	cin >> id;
	cout << "Withdrawal amount: ";
	cin >> money;

	int idx = GetAccIdx(id);
	if (idx != -1) {
		if (accArr[idx] -> getBalance() < money) {
			cout << "Not enough balance" << endl << endl;
			return;
		}
		accArr[idx] -> setBalance(accArr[idx] -> getBalance() - money);
		cout << "Withdrawal completed" << endl << endl;
		return;
	}
	cout << "This ID is not valid" << endl << endl;
}

void AccountHandler::DeleteAccount(void) {
	int id;
	cout << "[Delete Account]" << endl;
	cout << "Account ID (0 to delete all accounts): ";
	cin >> id;

	if (id == 0) {
		accNum = 0;
		cout << "All accounts have been deleted" << endl << endl;
		return;
	}
	int idx = GetAccIdx(id);
	if (idx != -1) {
		for (int j = idx; j < accNum - 1; j++) {
			accArr[j] = accArr[j + 1];
		}
		accNum--;
		cout << "Account " << id << " has been deleted" << endl << endl;
		return;
	}
	cout << "Account " << id << " not found" << endl << endl;
}

void AccountHandler::SendMoney() {
	int money;
	int sender, receiver;
	cout << "[Send Money]" << endl;
	cout << "Withdrawal Account ID: ";
	cin >> sender;
	cout << "Receiving Account: ";
	cin >> receiver;
	if (sender == receiver) {
		cout << "Cannot send money to the same account" << endl << endl;
		return;
	}
	cout << "Amount: ";
	cin >> money;
	int idx_sender = GetAccIdx(sender);
	int idx_receiver = GetAccIdx(receiver);
	if (idx_receiver == -1) {
		cout << "Invalid Receiving Account!" << endl << endl;
		return;
	}else if (idx_sender == -1) {
		cout << "Invalid Withdrawal Account!" << endl << endl;
		return;
	}

	if (accArr[idx_sender] -> getBalance() < money) {
		cout << "Not enough balance" << endl << endl;
		return;
	}
	accArr[idx_sender] -> setBalance(accArr[idx_sender] -> getBalance() - money);
	accArr[idx_receiver] -> setBalance(accArr[idx_receiver] -> getBalance() + money);
	cout << "Sending completed" << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) {
	for (int i = 0; i < accNum; i++) {
		cout << "Account ID: " << accArr[i] -> getID() << endl;
		cout << "Name: ";
		char* namePtr = accArr[i] -> getName();
		for (int j = 0; j < NAME_LEN; j++)
			cout << namePtr[j];
		cout << endl;
		cout << "Balance: " << accArr[i] -> getBalance() << endl << endl;
	}
	if (accNum == 0) {
		cout << "No accounts exist" << endl << endl;
	}
}

int AccountHandler::GetAccIdx(int id) {
	for (int i = 0; i < accNum; i++) {
		if (accArr[i] -> getID() == id) {
			return i;
		}
	}
	return -1;
}