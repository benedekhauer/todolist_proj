#include <stdio.h>
#include "remove_subject.h"
#include "util.h"
#include "remove_subject_helpers.h"
#include <string.h>

void proc_dels(char* username) {

	M_RET_IF_TRUE(missing(FILE_LIST));	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There is nothing to delete.\n");
		return;
	}

	
	printf("| Bot> *Warning*: If you delete a subject,\n");
	printf("|                 all the todos inside are going to be lost.\n");
	printf("| Bot> Do you wish to continue?\n"); 

	M_RET_IF_FALSE(confirm(username));	
		
	print_subjects();
	char chosen_file[MAX_STR_SIZE];
	printf("| Bot> Which subject do you want to delete?\n");	
	printf("| %s> (%s to abort): ", username, EXIT_CODE);
	fgets(chosen_file, MAX_STR_SIZE, stdin);
	correct(chosen_file);

	M_RET_IF_EXIT(chosen_file);

	if(file_exists(chosen_file) == TRUE) {
		M_RET_IF_TRUE(missing(chosen_file));
		delete_file(chosen_file);
		printf("| Bot> Deletion successful of \'%s\'\n", chosen_file);
	}
	else {
		printf("| Bot> The subject you typed in does not exist.\n");
	}
}

