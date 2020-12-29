#include <iostream>
#include "global_account_list.h"
#include "account.h"

GlobalAccountListClass global_account_list; // Definition

int GlobalAccountListClass :: account_exists(std :: string username) {
	for (AccountClass account : account_list) {
		if (account.return_username() == username) {
			return 1;
		}
	}
	
	return -1;
}

std :: vector <AccountClass> :: iterator GlobalAccountListClass :: find_account(std :: string username) {
	if (account_exists(username) == 1) {
		for (auto it = account_list.begin(); it != account_list.end(); ++it) {
			if (it -> return_username() == username) {
				return it;
			}
		}
	}
	
	else {
		std :: cout << "Account does not exist." << std :: endl;
		return account_list.end();
	}
}

void GlobalAccountListClass :: add_account(AccountClass account) {
	account_list.push_back(account);
}

void GlobalAccountListClass :: delete_account(std :: string username) {
	account_list.erase(find_account(username));
	std :: cout << username << ": deleted." << std :: endl;
}

void GlobalAccountListClass :: delete_all_accounts() {
	account_list.clear();
	std :: cout << "Deleted all accounts." << std :: endl;
}

void GlobalAccountListClass :: show_all_accounts() {
	int i = 0;
	for (auto it = account_list.begin(); it != account_list.end(); ++it) {
		std :: cout << "[" << i << "] " << it -> return_username() << std :: endl;
		i += 1;
	}
}
