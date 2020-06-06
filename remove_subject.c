#include <stdio.h>
#include "remove_subject.h"
#include "util.h"
#include "remove_subject_helpers.h"
#include <string.h>

int proc_dels(char* username) {
	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There is nothing to delete.\n");
		return FALSE;
	}

	
	printf("| Bot> *Warning*: If you delete a subject,\n");
	printf("|                 all the todos inside are going to be lost.\n");
	printf("| Bot> Do you wish to continue?\n"); 
	
	if(confirm(username) == FALSE) {
		printf("| Bot> No changes.\n");
		return FALSE;
	}
		
	print_subjects();
	char chosen_file[MAX_STR_SIZE];
	printf("| Bot> Which subject do you want to delete?\n");	
	printf("| %s> (%s to abort): ", username, EXIT_CODE);
	fgets(chosen_file, MAX_STR_SIZE, stdin);
	correct(chosen_file);
	if(strcmp(chosen_file, EXIT_CODE) == 0) {
		printf("| Bot> No changes. Aborted.\n");
		return FALSE;
	}


	if(file_exists(chosen_file) == TRUE) {
		delete_file(chosen_file);
		printf("| Bot> Deletion successful of \'%s\'\n", chosen_file);
		return TRUE;
	}
	else {
		printf("| Bot> The subject you typed in does not exist.\n");
		printf("| Bot> Deletion failed.\n");
		return FALSE;
	}
}

