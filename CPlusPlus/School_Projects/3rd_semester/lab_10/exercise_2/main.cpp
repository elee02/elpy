/*
Bank Program v0.4
*/
#include <iostream>
#include "bank.h"
using namespace std;

int main(void) {
	AccountHandler mn;
	int choice;

	while (true) {
		mn.ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (bank(choice)) {
		case bank::MAKE:
			mn.MakeAccount();
			break;
		case bank::DEPOSIT:
			mn.DepositMoney();
			break;
		case bank::SEND:
			mn.SendMoney();
			break;
		case bank::WITHDRAW:
			mn.WithdrawMoney();
			break;
		case bank::INQUIRE:
			mn.ShowAllAccInfo();
			break;
		case bank::DELETE:
			mn.DeleteAccount();
			break;
		case bank::EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}