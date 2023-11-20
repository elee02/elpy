/*
Bank Program v0.3
*/
#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
	int choice;

	while (true) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (bank(choice)) {
		case bank::MAKE:
			MakeAccount();
			break;
		case bank::DEPOSIT:
			DepositMoney();
			break;
		case bank::SEND:
			SendMoney();
			break;
		case bank::WITHDRAW:
			WithdrawMoney();
			break;
		case bank::INQUIRE:
			ShowAllAccInfo();
			break;
		case bank::DELETE:
			DeleteAccount();
			break;
		case bank::EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}