#include "clear_subject.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include "remove_subject_helpers.h"
#include "clear_subject_helpers.h"
#include <stdlib.h>


void proc_clrs(char* username) {

	M_RET_IF_TRUE(missing(FILE_LIST));
	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There is no subject to clear.\n");
		return;
	}

	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are already empty.\n");
		return;
	}
    char unchanged[MAX_STR_SIZE];
    char subject[MAX_STR_SIZE];
    print_nonempty_subjects();
    printf("| Bot> Which subject do you want to clear (remove all todos)?\n");
    printf("| %s> (%s to abort, %s to clear all): ", username, EXIT_CODE, ALL_CODE);
    fgets(subject, MAX_STR_SIZE, stdin);
	correct(subject);
    strncpy(unchanged, subject, MAX_FILENAME_SIZE);

	size_t len = strlen(subject);
    for(int i = 0; i < len; i++) {
        if(subject[i] == '\n') {
            subject[i] = '\0';
            break;
        }
    }

	if(strcmp(subject, ALL_CODE) == 0) {
		clear_all();
		return;
	}

	M_RET_IF_EXIT(subject);


    if(file_exists(unchanged) == TRUE) {
        M_RET_IF_TRUE(missing(unchanged));
		FILE* toClear = fopen(subject, "w");
		fprintf(toClear, "%s", EMPTY_STRING);
		fclose(toClear);
		printf("| Bot> Subject cleared successfully.\n");
    }
    else {
        printf("| Bot> The subject you typed in does not exist.\n");
        printf("| Bot> Failed to clear.\n");
    }

}
