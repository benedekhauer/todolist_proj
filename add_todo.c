#include "add_todo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_todo_helpers.h"
#include "remove_subject_helpers.h"

void proc_addt(void) {
	char username[USERNAME_SIZE];
	FILE* file_usr = fopen(FILE_USERNAME, "r");
	fscanf(file_usr, "%s", username);
	fclose(file_usr);

	char unchanged[MAX_STR_SIZE];
	char subject[MAX_STR_SIZE];
	
	if(isFileEmpty(FILE_LIST)) {
		printf("| Bot> You have no subject to add a todo to.\n");
		return;
	}
	
	print_subjects();
	printf("| Bot> Which subject do you want to add the todo to?\n"); 
	printf("| %s> (EXIT to abort): ", username);
	fgets(subject, MAX_STR_SIZE, stdin);
	
	strncpy(unchanged, subject, MAX_FILENAME_SIZE);	

	correct(subject);



	if(strcmp(subject, EXIT_CODE) == 0) {
		printf("| Bot> No changes. Aborted.\n");
		return;
	}
	
	
	if(file_exists(subject) == TRUE) {
		add_todo(subject, username);
		return;
	}
	else {
		printf("| Bot> The subject you typed in does not exist.\n");
		printf("| Bot> Failed to add todo.\n");
		return;
	}
}
