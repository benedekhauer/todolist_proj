#include <stdio.h>
#include "print_subject.h"
#include <string.h>
#include "util.h"
#include "print_subject_helpers.h"

void proc_prnt(void) {

	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> You have not subject to print.\n");
		return;
	}

	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are empty.\n");
		return;
	}
	char username[USERNAME_SIZE];
    FILE* file_usr = fopen(FILE_USERNAME, "r");
    fscanf(file_usr, "%s", username);
    fclose(file_usr);

	char chosen_file[MAX_STR_SIZE];

	print_nonempty_subjects();

	printf("| Bot> Enter the subject you want to display.\n");
	printf("| %s> (Subject, %s to exit): ", username, EXIT_CODE);
	fgets(chosen_file, MAX_STR_SIZE, stdin);
	correct(chosen_file);
	if(strcmp(chosen_file, EXIT_CODE) == 0) {
		return;
	}
	print_line();
	print_subject(chosen_file);
	return;

}
