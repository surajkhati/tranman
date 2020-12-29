#include <iostream>
#include "account.h"
#include "global_account_list.h"
using namespace std;

AccountClass* current_account = NULL; // Current Account Definition

string AccountClass :: return_username() {
	return username;
}

int AccountClass :: check_login() {
	
	cout << "Account found :-" << endl;
	
	string check_password;
	while(1) {
		cout << "Enter password: ";
		cin >> check_password;
		
		if (check_password == "") {
			cout << "Empty input." << endl;
			continue;
		}
		
		else {
			if (password == check_password) {
				return 1;
			}
			
			else {
				return -1;
			}
		}
	}

	return -1;
}

void BankType :: init_bank() {
	cout << "\tEnter bank name: ";
	cin >> bank_name;
	cout << "\tEnter amount:    ";
	cin >> amount;
}

void BankType :: show_bank_details() {
	cout << "\t\t" << bank_name << ": ";
	cout << "\t\t" << amount << endl;
}

void AccountClass :: create_banks() {
	int n;
	cout << "Enter number of banks: ";
	cin >> n;
	
	for (int i = 0; i < n; ++i) {
		BankType* new_bank = new BankType;
		cout << "Enter bank [" << i << "] details: " << endl;
		new_bank -> init_bank();
		bank_list.push_back(*new_bank);
	}
}


void AccountClass :: create_account() {
	
	cout << "Creating a new account:-" << endl;
	
	while(1) {
		cout << "\tEnter username: ";
		cin >> username;
		
		if (username == "") {
			cout << "Account name cannot be empty." << endl;
			continue;
		}
		
		else {
			if (global_account_list.account_exists(username) == 1) {
				cout << "\t\tAccount with that username already exists." << endl;
				continue;
			}
		}
		
		cout << "\tEnter password: ";
		cin >> password;
		
		if (password == "") {
			cout << "Password cannot be empty." << endl;
			continue;
		}
		
		break;
	}
	
	create_banks();
	
	cin.get();
	cout << endl << "Account created successfully." << endl;
}

void AccountClass :: show_account_details() {
	cout << "\tUsername: " << username << endl;
	if (bank_list.size() > 0) {
		cout << "\tBank details:- " << endl;
		for (BankType bank : bank_list) {
			bank.show_bank_details();
		}
	}
}
