#include <stdio.h>
#include <string.h>
#include "util.h"
#include "remove_todo_helpers.h"
#include "print_subject_helpers.h"

void move_to_top(char subject[], char* username) {
	print_full_subject(subject);
	int move_id;
	printf("| Bot> Enter the number of the todo you want to move to the top.\n");
	print_line();
	char line[MAX_STR_SIZE];
	int matched = 0;


	do {
		printf("| %s> (%s to exit): ", username, EXIT_CODE);
        fgets(line, MAX_STR_SIZE, stdin);
        if(isNumber(line) == TRUE) {
            move_id = atoi(line);
            matched = 1;
        }
        else if(isX(line) == TRUE) {
            return FALSE;
        }
    } while(matched == 0);
	
	if(todoIdExists(subject, move_id) == FALSE) {
        printf("| Bot> The number you entered does not match any todo.\n");
    }
	
	execute(subject, move_id);
	printf("| Bot> Done.\n");

	printf("| Bot> Do you want to continue reorganizing %s ?\n", subject);
	
	if(confirm(username)) {
		move_to_top(subject, username);
	}
}


void execute(char subject[], int move_id) {
	FILE* f_subj = fopen(subject, "r");
	char text[MAX_STR_SIZE];
	char topLine[MAX_STR_SIZE];	

	int currentId;
	while(!feof(f_subj)) {
		fscanf(f_subj, "%d", &currentId);
		if(feof(f_subj)) {
			break;
		}
		fgets(text, MAX_STR_SIZE, f_subj);
		if(currentId == move_id) {
			strncpy(topLine, text, MAX_STR_SIZE);
		}
	}
	fclose(f_subj);
	f_subj = fopen(subject, "r");
	
	FILE* f_swap = fopen(FILE_SWAP, "w");
	fprintf(f_swap, "%d%s", move_id, topLine);
	while(!feof(f_subj)) {
		fscanf(f_subj, "%d", &currentId);
		if(feof(f_subj)) {
			break;
		}
		fgets(text, MAX_STR_SIZE, f_subj);
		if(currentId != move_id) {
			fprintf(f_swap, "%d%s", currentId, text);
		}
	}

	fclose(f_subj);
	fclose(f_swap);
	remove(subject);
	rename(FILE_SWAP, subject);
	FILE* newSwap = fopen(FILE_SWAP, "w");
	fprintf(newSwap, "%s", EMPTY_STRING);
	fclose(newSwap);
}
