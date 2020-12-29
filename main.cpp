#include "repl.h"
#include "account.h"

int main() {

	repl.print_info();
	while (repl.run_status()) {
		repl.parse(repl.prompt_user());
	}
	
	return 0;
}
