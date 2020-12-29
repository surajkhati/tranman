#pragma once
#include <string>
#include <vector>

class REPLClass {
	private:
		std :: string prompt;
		bool is_running;
		
		int total = 0;
	
	public:
		
		REPLClass() {
			prompt = "<tranman> ";
			is_running = true;
			
			total = 0;
		}
		
		bool run_status();
		void quit();
		void clear_screen();
		void print_info();
		void change_prompt(std :: string);
		
		void parse(std :: string);
		std :: string prompt_user();
		std :: vector <std :: string> tokenize(std :: string);
};

extern REPLClass repl;	// Declaration
