#include <stdio.h>
#include <string.h>
#include "reset.h"
#include "util.h"
#include "remove_subject_helpers.h"
#include "initialize.h"

int proc_init(char* username) {

	printf("| Bot> ** WARNING ** All subjects and todos will be deleted.\n");
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
        return FALSE;
    }

	generate_all_files();
	FILE* all_files = fopen(FILE_LIST, "r");
	char line[MAX_STR_SIZE];
	char dummy[MAX_STR_SIZE];
	while(!feof(all_files)) {
        fgets(line, MAX_STR_SIZE, all_files);
        strncpy(dummy, line, MAX_STR_SIZE);
        correct(dummy);
        if(feof(all_files)) {break;}
        delete_file(dummy);
    }
	fclose(all_files);
	FILE* f_ne = fopen(FILE_NE, "w");
	fprintf(f_ne, "%s", EMPTY_STRING);
	fclose(f_ne);
	printf("| Bot> Reset complete.\n");
	return TRUE;
}


