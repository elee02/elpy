/*
Bank Program v0.5
*/
#include "AccountHandler.h"
#include <iostream>
using namespace std;

int main(void) {
	AccountHandler mn;
	int choice;

	while (true) {
		mn.ShowMenu();
		cout << "Select menu: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case MAKE:
			mn.MakeAccount();
			break;
		case DEPOSIT:
			mn.DepositMoney();
			break;
		case SEND:
			mn.SendMoney();
			break;
		case WITHDRAW:
			mn.WithdrawMoney();
			break;
		case INQUIRE:
			mn.ShowAllAccInfo();
			break;
		case DELETE:
			mn.DeleteAccount();
			break;
		case EXIT:
			return 0;
		default:
			cout << "Illegal selection.." << endl;
		}
	}
	return 0;
}