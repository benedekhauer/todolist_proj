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
#include "update.h"
#include "display_subjects.h"
#include "change_username.h"
#include "information.h"

int main(void) {
	int username_update = FALSE;
	char username[USERNAME_SIZE];
	FILE* file_usr = fopen(FILE_USERNAME, "r");
	fscanf(file_usr, "%s", username);
	fclose(file_usr);
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
	
	int change = FALSE;
	print_line();
	while(cmd != exit) {
		switch(cmd) {
			case init:
				change = proc_init();
				print_line();
				break;
			case disp:
				proc_disp();
				print_line();
				break;
			case adds:
				proc_adds();
				print_line();
				break;
			case addt:
				change = proc_addt();
				print_line();
				break;
			case dels:
				change = proc_dels();
				print_line();
				break;
			case delt:
				change = proc_delt();
				print_line();
				break;
			case rndm:
				proc_rndm();
				print_line();
				break;
			case clrs:
				change = proc_clrs();
				print_line();
				break;
			case prnt:
				proc_prnt();
				print_line();
				break;
			case usrn:
				username_update = proc_usrn();
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
			case exit:
				//do nothing
				break;
			default:
				break;
		}
		if(change == TRUE) {
			update();
		}

		if(username_update == TRUE) {
			FILE* file_usr = fopen(FILE_USERNAME, "r");
    		fscanf(file_usr, "%s", username);
    		fclose(file_usr);
		}
	

		do {
            printf("| %s> (cmd): ", username);
            char s_command[MAX_STR_SIZE];
            char s_check[CMD_SIZE];
            fgets(s_command, MAX_STR_SIZE, stdin);
            cmd = parse_command(s_command);
        } while(cmd == none);
		print_line();

	}
	printf("|------------------------- END OF TODOLIST -------------------------\n");
	return 0;		
}
