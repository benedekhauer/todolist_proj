#include <stdio.h>
#include <string.h>
#include "util.h"
#include "remove_todo.h"
#include "remove_todo_helpers.h"

int proc_delt(char* username) {

	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> Your subject list is empty.\n");
		return FALSE;
	}
	
	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are empty.\n");
		return FALSE;
	}

	char subject[MAX_STR_SIZE];

	print_nonempty_subjects();
	
	printf("| Bot> In which subject should I delete a todo?\n");
	print_line();
	printf("| %s> (subject, %s to abort): ", username, EXIT_CODE);
	fgets(subject, MAX_STR_SIZE, stdin);
	correct(subject);

	if(strcmp(subject, EXIT_CODE) == 0) {
		printf("| Bot> No changes.\n");
		return FALSE;
	}

	if(file_exists(subject) == FALSE) {
		printf("| Bot> The subject you want to delete from does not exist.\n");
		return FALSE;
	}
	if(isFileEmpty(subject) ==  TRUE) {
		printf("| Bot> The file you want to delete from is empty.\n");
		return FALSE;
	}
	return delete_todo(subject, username);
	
}
