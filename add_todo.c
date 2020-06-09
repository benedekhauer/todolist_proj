#include "add_todo.h"
#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_todo_helpers.h"
#include "remove_subject_helpers.h"

void proc_addt(char* username) {

	char unchanged[MAX_STR_SIZE];
	char subject[MAX_STR_SIZE];


	int id = generate_id();
	if(id > MAX_TODO_COUNT) {
		printf("| Bot> You cannot add any more todos.\n");
		return;
	}
	
	if(isFileEmpty(FILE_LIST)) {
		printf("| Bot> You have no subject to add a todo to.\n");
		return;
	}
	M_RET_IF_TRUE(missing(FILE_LIST));	
	print_subjects();
	printf("| Bot> Which subject do you want to add the todo to?\n"); 
	printf("| %s> (%s to abort): ", username, EXIT_CODE);
	fgets(subject, MAX_STR_SIZE, stdin);
	
	strncpy(unchanged, subject, MAX_FILENAME_SIZE);	

	correct(subject);
	M_RET_IF_TRUE(missing(FILE_LIST));


	M_RET_IF_TRUE(strcmp(subject, EXIT_CODE) == 0);
	
	if(file_exists(subject) == TRUE) {
		add_todo(subject, username, id);
	}

	else if(file_exists(subject) == FAILURE) {
		print_hrst_msg();
	}

	else {
		printf("| Bot> The subject you typed in does not exist.\n");
	}
}
