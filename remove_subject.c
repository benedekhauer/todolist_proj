#include <stdio.h>
#include "remove_subject.h"
#include "util.h"
#include "remove_subject_helpers.h"
#include <string.h>

void proc_dels(void) {
	char username[USERNAME_SIZE];
    FILE* file_usr = fopen(FILE_USERNAME, "r");
    fscanf(file_usr, "%s", username);
    fclose(file_usr);

	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There is nothing to delete.\n");
		return;
	}

	
	printf("| Bot> *Warning*: If you delete a subject,\n");
	printf("|                 all the todos inside are going to be lost.\n");
	printf("| Bot> Do you wish to continue?\n"); 
	char yn = 'X';
	while(yn == 'X') {
        printf("| %s> (Y/N): ", username);
        char s_answer[MAX_STR_SIZE];
        char s_check[1];
        fgets(s_answer, MAX_STR_SIZE, stdin);
      	yn = parse_answer(s_answer);
    }

	if(yn == 'N' || yn == 'n') {
		printf("| Bot> No changes.\n");
		return;
	}
		
	print_subjects();
	char chosen_file[MAX_STR_SIZE];
	printf("| Bot> Which subject do you want to delete?\n");	
	printf("| %s> (EXIT to abort): ", username);
	fgets(chosen_file, MAX_STR_SIZE, stdin);
	correct(chosen_file);
	if(strcmp(chosen_file, EXIT_CODE) == 0) {
		printf("| Bot> No changes. Aborted.\n");
		return;
	}


	if(file_exists(chosen_file) == TRUE) {
		delete_file(chosen_file);
		printf("| Bot> Deletion successful of \'%s\'\n", chosen_file);
		return;
	}
	else {
		printf("| Bot> The subject you typed in does not exist.\n");
		printf("| Bot> Deletion failed.\n");
		return;
	}
}

