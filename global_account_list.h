#pragma once
#include <vector>
#include "account.h"

class GlobalAccountListClass {
	private:
		std :: vector <AccountClass> account_list;
	
	public:
		int return_size() { return account_list.size(); }
		int  account_exists(std :: string username);
		std :: vector <AccountClass> :: iterator find_account(std :: string username);
		
		void add_account(AccountClass);
		void delete_account(std :: string username);
		void delete_all_accounts();
		
		void show_all_accounts();

};

extern GlobalAccountListClass global_account_list;
