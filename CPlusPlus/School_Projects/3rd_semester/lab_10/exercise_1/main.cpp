/*
Bank Program v0.3
*/
#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
	int choice;

	while (1) {
		ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case SEND:
			SendMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case DELETE:
			DeleteAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}