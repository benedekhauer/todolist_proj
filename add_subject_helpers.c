#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_subject_helpers.h"
#include "initialize.h"

int violation(char filename[]) {
	if(strcmp(filename, ALL_CODE) == 0) {
        printf("| Bot> ### Failed. The name of a subject cannot be \'%s\'\n", ALL_CODE);
        return TRUE;
    }

	if(strcmp(filename, EXIT_CODE) == 0) {
		printf("| Bot> ### Failed. The name of a subject cannot be \'%s\'\n", EXIT_CODE);
		return TRUE;
	}

	if(strcmp(filename, HASH) == 0) {
		printf("| Bot> ### Failed. The name of a subject cannot be \'%s\'\n", HASH);
		return TRUE;
	}
    if(strcmp(filename, EXEC_FILE) == 0) {
        printf("| Bot> ### Failed. The name of your subject cannot be \'%s\'\n", EXEC_FILE);
        return TRUE;
    }

    if(strcmp(filename, MAKEFILE) == 0) {
        printf("| Bot> ### Failed. The name of your subject cannot be \'%s\'\n", MAKEFILE);
        return TRUE;
    }

    if(file_exists(filename) == TRUE) {
        printf("| Bot> ### Creation of %s failed (subject already exists).\n", filename);
        return TRUE;
    }
	return FALSE;
}


void add_to_gitignore(char filename[]) {
	
	FILE* gitignore;
	M_RET_IF_NULL(gitignore = fopen(".gitignore", "a"));

	fprintf(gitignore, "%s\n", filename);
	fclose(gitignore);
}

int isAscii(char c) {
	if(c == '\n' || c == '\0') { return TRUE;}
	if(c >= 48 && c <= 57) {return TRUE;}
	if(c >= 65 && c <= 90) {return TRUE;}
	if(c >= 97 && c <= 122) {return TRUE;}
	return FALSE;
}


int isAccepted(char str[]) {
	if (str[0] == '\n' || str[0] == '\0') {return FALSE;}
	for(int i = 0; i < MAX_FILENAME_SIZE && str[i] != '\0'; i++) {
		if((isAscii(str[i])) == FALSE) {return FALSE;}
	}
	return TRUE;
}

