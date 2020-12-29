#pragma once
#include <string>
#include <vector>

/*
	Account List
		- Account
			- Username
			- Password
			- Bank List
				- Bank
					- Bank name
					- Amount
			- Transaction List
				- Sign
				- Amount
				- Date
				- Bank
*/

class BankType {
	std :: string bank_name;
	int amount;
	
	public:
		BankType() {
			bank_name = "";
			amount = 0;
		}
		
		void show_bank_details();
		void init_bank();
};

class AccountClass {
	
	private:
		std :: string username;
		std :: string password;
		std :: vector <BankType> bank_list;
		
	public:
		// System Functions
		std :: string return_username();
		
		// Account Functions
		int check_login();
		void create_account();
		void create_banks();
		void show_account_details();
};

extern AccountClass* current_account;
