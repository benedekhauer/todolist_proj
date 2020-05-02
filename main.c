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

int main(void) {
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
	
	int change = 0;
	print_line();
	while(cmd != exit) {
		switch(cmd) {
			case init:
				proc_init();
				print_line();
				change = 1;
				break;
			case adds:
				proc_adds();
				print_line();
				break;
			case addt:
				proc_addt();
				print_line();
				change = 1;
				break;
			case dels:
				proc_dels();
				print_line();
				change = 1;
				break;
			case delt:
				proc_delt();
				print_line();
				change = 1;
				break;
			case rndm:
				proc_rndm();
				print_line();
				break;
			case clrs:
				proc_clrs();
				print_line();
				change = 1;
				break;
			case prnt:
				proc_prnt();
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
		if(change == 1) {
			update();
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
