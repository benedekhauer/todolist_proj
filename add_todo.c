#include "add_todo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_todo_helpers.h"
#include "remove_subject_helpers.h"

int proc_addt(char* username) {

	char unchanged[MAX_STR_SIZE];
	char subject[MAX_STR_SIZE];


	int id = generate_id();
	if(id > MAX_TODO_COUNT) {
		printf("| Bot> You cannot add any more todos.\n");
		return FALSE;
	}
	
	if(isFileEmpty(FILE_LIST)) {
		printf("| Bot> You have no subject to add a todo to.\n");
		return FALSE;
	}
	
	print_subjects();
	printf("| Bot> Which subject do you want to add the todo to?\n"); 
	printf("| %s> (%s to abort): ", username, EXIT_CODE);
	fgets(subject, MAX_STR_SIZE, stdin);
	
	strncpy(unchanged, subject, MAX_FILENAME_SIZE);	

	correct(subject);



	if(strcmp(subject, EXIT_CODE) == 0) {
		printf("| Bot> No changes. Aborted.\n");
		return FALSE;
	}
	
	if(file_exists(subject) == TRUE) {
		return add_todo(subject, username, id);
	}


	else {
		printf("| Bot> The subject you typed in does not exist.\n");
		printf("| Bot> Failed to add todo.\n");
		return FALSE;
	}
}
