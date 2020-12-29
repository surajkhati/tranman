#include <iostream>
#include <bits/stdc++.h>

#include "repl.h"
#include "account.h"
#include "global_account_list.h"
using namespace std;

REPLClass repl;	// Definition

void login() {
	string username;
	
	while (1) {
		
		cout << "Enter username: ";
		cin >> username;
		
		if (username == "") {
			cout << "Empty input. Try again." << endl;
			continue;
		}
		
		if (global_account_list.account_exists(username) == 1) {
			auto it = global_account_list.find_account(username);
			if (it -> check_login() == 1) {
				current_account = &(*it);
				cout << "Logged in successfully." << endl;
				repl.change_prompt(current_account -> return_username() + " > ");
			}
			
			else {
				current_account = NULL;
				cout << "Login unsuccessful." << endl;
			}
			
			break;
		}
		
		else {
			cout << "Account with that username does not exist." << endl;
			break;
		}
	}
	
	cin.get();
}

void logout() {
	current_account = NULL;
	repl.change_prompt("<tranman> ");
}

bool logged_in() {
	if (current_account == NULL)
		return false;
	else
		return true;
}

bool REPLClass :: run_status() {
	return is_running;
}

void REPLClass :: quit() {
	is_running = false;
}

void REPLClass :: change_prompt(string text) {
	prompt = text;
}

void REPLClass :: clear_screen() {
	for (int i = 0; i < 128; ++i)
		cout << endl;
}

void REPLClass :: print_info() {
	cout << " --- Transaction Manager [tranman] --- " << endl;
	cout << "      Written: Suraj Khati, 2020" << endl;
}

vector <string> REPLClass :: tokenize(string line) {
	
	vector <string> tokens;
	stringstream ss(line);
	string current_token;
	
	if (line == "") {
		tokens.push_back("");
		return tokens;
	}
	
	while (getline(ss, current_token, ' ')) {
		tokens.push_back(current_token);
	}
	
	return tokens;
}

string REPLClass :: prompt_user() {
	
	string user_input;
	
	cout << prompt;
	getline(cin, user_input);
	
	return user_input;
}

void REPLClass :: parse(string user_input) {
	
	vector<string> args = tokenize(user_input); // List of arguments
	string command = args[0]; // The first argument is the command
	args.erase(args.begin()); // Now delete it.

	// System Commands
	if (command == "clear" || command == "c") {
		if (args.size() == 0)
			clear_screen();
		else if (args[0] == "total" || args[0] == "t")
			total = 0;
		else
			cout << command << ": not understood." << endl;
	}
	
	else if (command == "total" || command == "t") {
		for (int i = 0; i < args.size(); ++i)
			total += stoi(args[i]);
			
		cout << "Total: " << total << endl;
	}
	
	else if (command == "quit" || command == "q") {
		cout << "Bye!" << endl;
		quit();
	}
	
	else if (command == "")
		; // pass
		
	/* Tranman Commands */
	
	else if (command == "new" || command == "n") {
		if (!logged_in()) {
			if (args[0] == "account" || args[0] == "a") {
				AccountClass* new_account = new AccountClass;
				new_account -> create_account();
				global_account_list.add_account(*new_account);
			}
			
			else
				cout << command << ": not understood." << endl;
		}
		
		else {
			cout << "Log out first." << endl;
		}
	}
	
	else if (command == "login" || command == "li") {
		if (global_account_list.return_size() == 0)
			cout << "No accounts in list." << endl;
		
		else {
			if (!logged_in()) {
				login();
			}
			
			else {
				cout << "Already logged in." << endl;
			}
		}
	}
	
	else if (command == "logout" || command == "lo") {
		if (logged_in()) {
			logout();
		}
		
		else {
			cout << "Not logged in." << endl;
		}
	}
	
	else if (command == "show" || command == "s") {
		
		if (args[0] == "all") {
			global_account_list.show_all_accounts();
		}
		
		else if (args[0] == "account" || args[0] == "a") {
			if (logged_in()) {
				current_account -> show_account_details();
			}
			
			else {
				cout << "Must login to view account details." << endl;
			}
		}
		
		else
			cout << command << ": not understood." << endl;
	}
	
	else if (command == "delete" || command == "d") {
		if (!logged_in()) {
			if (args[0] == "account" || args[0] == "a") {
				global_account_list.delete_account(args[1]);
			}
			
			else if (args[0] == "all") {
				global_account_list.delete_all_accounts();
			}
			
			else
				cout << command << ": not understood." << endl;
		}
		
		else {
			cout << "Must logout before deleting." << endl;
		}
	}
	
	else
		cout << "Error: Invalid input." << endl;
}
