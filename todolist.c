#include <stdio.h>
#include "command.h"
#include <string.h>
#include "util.h"
#include "add_subject.h"
#include "remove_subject.h"
#include "add_todo.h"
#include "clear_subject.h"
#include "print_subject.h"
#include "reset.h"
#include "remove_todo.h"
#include "random_todo.h"
#include "display_subjects.h"
#include "change_username.h"
#include "information.h"
#include "move_todo.h"

int main(void) {
	int username_update = FALSE;
	char* username = get_username();
	command cmd = none;
	print_line();
	printf("|---------------------------- TODOLIST -----------------------------\n");
	printf("| Bot> What do you want to do? (Type 'help' to display commands)\n");
	print_line();
	while(cmd == none) {
        printf("| %s> (cmd): ", username);
        char s_command[MAX_STR_SIZE];
        char s_check[CMD_SIZE];
        fgets(s_command, MAX_STR_SIZE, stdin);
        cmd = parse_command(s_command);
    }

	generate_files();
		
	print_line();
	while(cmd != quit) {
		switch(cmd) {
			case init:
				proc_init(username);
				print_line();
				break;
			case disp:
				proc_disp();
				print_line();
				break;
			case adds:
				proc_adds(username);
				print_line();
				break;
			case addt:
				proc_addt(username);
				print_line();
				break;
			case dels:
				proc_dels(username);
				print_line();
				break;
			case delt:
				proc_delt(username);
				print_line();
				break;
			case mvtp:
				proc_mvtp(username);
				print_line();
				break;	
			case rndm:
				proc_rndm();
				print_line();
				break;
			case clrs:
				proc_clrs(username);
				print_line();
				break;
			case prnt:
				proc_prnt(username);
				print_line();
				break;
			case usrn:
				username_update = proc_usrn(username);
				print_line();
				break;
			case info:
				proc_info();
				print_line();
				break;
			case help:
				print_commands();
				print_line();
				break;
			case quit:
				//do nothing
				break;
			default:
				break;
		}

		if(username_update == TRUE) {
			M_FREE(username);
			username = get_username();
		}
	

		do {
            printf("| %s> (cmd): ", username);
            char s_command[MAX_STR_SIZE];
            char s_check[CMD_SIZE];
            fgets(s_command, MAX_STR_SIZE, stdin);
            cmd = parse_command(s_command);
        } while(cmd == none);
		print_line();
		if(missing(FILE_LIST) == TRUE) {
			M_FREE(username);
    		printf("|------------------------- END OF TODOLIST -------------------------\n");
    		return 0;
		}

	}
	M_FREE(username);
	printf("|------------------------- END OF TODOLIST -------------------------\n");
	return 0;		
}
