#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_subject.h"
#include "add_subject_helpers.h"
#include "remove_subject_helpers.h"
void proc_adds(void) {
	char filename[MAX_STR_SIZE];
	const char* username = get_username();
	
	do {
		printf("| Bot> Enter subject (max %d chars, only letters and numbers).\n", MAX_FILENAME_SIZE-1);
		printf("| %s> (%s to abort): ", username, EXIT_CODE);
		fgets(filename, MAX_STR_SIZE, stdin);
	} while(isAccepted(filename) == FALSE || strlen(filename) > MAX_FILENAME_SIZE);
		
	correct(filename);
	
	if(strcmp(filename, EXIT_CODE) == 0) {
		return;
	}
	
	if(strcmp(filename, ALL_CODE) == 0) {
		printf("| Bot> ### Failed. The name of a subject cannot be \'%s\'\n", ALL_CODE);
	}
	
	if(strcmp(filename, EXEC_FILE) == 0) {
		printf("| Bot> ### Failed. The name of your subject cannot be \'%s\'\n", EXEC_FILE);
		return;
	}

	if(strcmp(filename, MAKEFILE) == 0) {
		printf("| Bot> ### Failed. The name of your subject cannot be \'%s\'\n", MAKEFILE);
		return;
	}

	if(file_exists(filename) == TRUE) {
		printf("| Bot> ### Creation of %s failed (subject already exists).\n", filename);
		return;
	}

	FILE* all = fopen(FILE_LIST, "a");
	fprintf(all, "%s", filename);
	fprintf(all, "\n");
	fclose(all);
		

	FILE* new = fopen(filename, "w");
	printf("| Bot> Creation of \'%s\' successful!\n", filename);
	fclose(new);
	return;
}
