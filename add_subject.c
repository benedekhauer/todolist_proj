#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_subject.h"
#include "add_subject_helpers.h"
#include "remove_subject_helpers.h"
#include "initialize.h"

int proc_adds(char* username) {
	char filename[MAX_STR_SIZE];
	
	print_subjects();
	do {
		printf("| Bot> Enter subject (max %d chars, only letters and numbers).\n", MAX_FILENAME_SIZE-1);
		printf("| %s> (%s to abort): ", username, EXIT_CODE);
		fgets(filename, MAX_STR_SIZE, stdin);
	} while(isAccepted(filename) == FALSE || strlen(filename) > MAX_FILENAME_SIZE);
		
	correct(filename);
	
	M_RET_IF_EXIT(filename);
	M_RET_IF_TRUE(violation(filename));
	
	
	FILE* all = fopen(FILE_LIST, "a");	
	M_PRINT_HRST_RET(all);
	
	fprintf(all, "%s", filename);
	fprintf(all, "\n");
	fclose(all);
		

	FILE* new = fopen(filename, "w");
	add_to_gitignore(filename);
	printf("| Bot> Creation of \'%s\' successful!\n", filename);
	fclose(new);
	return;
}
