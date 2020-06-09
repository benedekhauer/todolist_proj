#include "move_todo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "move_todo_helpers.h"

void proc_mvtp(char* username) {

	M_RET_IF_TRUE(missing(FILE_LIST));	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> Your subjects list is empty.\n");
		return;
	}

	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are empty.\n");
		return;
	}

	char subject[MAX_STR_SIZE];
	print_nonempty_subjects();
	printf("| Bot> Which subject do you want to reorganize?\n");
	print_line();
	printf("| %s> (subject, %s to abort): ", username, EXIT_CODE);
	fgets(subject, MAX_STR_SIZE, stdin);
	correct(subject);

	if(strcmp(subject, EXIT_CODE) == 0) {
		return;
	}
	
	if(file_exists(subject) == FALSE) {
		printf("| Bot> This subject does not exist.\n");
		return;
	}
	if(isFileEmpty(subject) == TRUE) {
		printf("| Bot> This subject has no todos.\n");
		return;
	}
	move_to_top(subject, username);
}
