#include <stdio.h>
#include <string.h>
#include "util.h"
#include "remove_todo.h"
#include "remove_todo_helpers.h"

void proc_delt(char* username) {

	M_RET_IF_TRUE(missing(FILE_LIST));
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> Your subject list is empty.\n");
		return;
	}
	
	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are empty.\n");
		return;
	}

	char subject[MAX_STR_SIZE];

	print_nonempty_subjects();
	
	printf("| Bot> In which subject should I delete a todo?\n");
	print_line();
	printf("| %s> (subject, %s to abort): ", username, EXIT_CODE);
	fgets(subject, MAX_STR_SIZE, stdin);
	correct(subject);


	M_RET_IF_EXIT(subject);
	M_RET_IF_TRUE(missing(subject));

	if(file_exists(subject) == FALSE) {
		printf("| Bot> The subject you want to delete from does not exist.\n");
		return;
	}
	if(isFileEmpty(subject) ==  TRUE) {
		printf("| Bot> The file you want to delete from is empty.\n");
		return;
	}
	delete_todo(subject, username);
	
}
