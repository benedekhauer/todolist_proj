#include "clear_subject.h"
#include "util.h"
#include <stdio.h>
#include <string.h>
#include "remove_subject_helpers.h"
#include "clear_subject_helpers.h"

int proc_clrs(void) {

	char username[USERNAME_SIZE];
    FILE* file_usr = fopen(FILE_USERNAME, "r");
    fscanf(file_usr, "%s", username);
    fclose(file_usr);
	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There is no subject to clear.\n");
		return FALSE;
	}

	if(allEmpty() == TRUE) {
		printf("| Bot> All your subjects are already empty.\n");
		return FALSE;
	}
    char unchanged[MAX_STR_SIZE];
    char subject[MAX_STR_SIZE];
    print_nonempty_subjects();
    printf("| Bot> Which subject do you want to clear (remove all todos)?\n");
    printf("| %s> (EXIT to abort, ALL to clear all): ", username);
    fgets(subject, MAX_STR_SIZE, stdin);
	correct(subject);
    strncpy(unchanged, subject, MAX_FILENAME_SIZE);

    for(int i = 0; i < MAX_FILENAME_SIZE + 1; i++) {
        if(subject[i] == '\n') {
            subject[i] = '\0';
            break;
        }
    }

	if(strcmp(subject, ALL_CODE) == 0) {
		clear_all();
		return TRUE;
	}


    if(strcmp(subject, EXIT_CODE) == 0) {
        printf("| Bot> No changes. Aborted.\n");
        return FALSE;
    }


    if(file_exists(unchanged) == TRUE) {
        FILE* toClear = fopen(subject, "w");
		fprintf(toClear, "%s", EMPTY_STRING);
		fclose(toClear);
		printf("| Bot> Subject cleared successfully.\n");
		return TRUE;
    }
    else {
        printf("| Bot> The subject you typed in does not exist.\n");
        printf("| Bot> Failed to clear.\n");
        return FALSE;
    }

}
