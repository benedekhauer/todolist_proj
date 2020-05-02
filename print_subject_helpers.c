#include <stdio.h>
#include "util.h"
#include "print_subject_helpers.h"
#include <string.h>

void print_subject(char subject[]) {
	if(file_exists(subject) == FALSE) {
		printf("| Bot> This subject does not exist.\n");
		return;
	}

	if(isFileEmpty(subject)) {
		printf("| Bot> This subject is empty.\n");
		return;
	}

	print_subject_name(subject, FALSE);	
	printf("\n");
	FILE* f_subj = fopen(subject, "r");
	int todo_id;
	char dot_dot;
	char todo[MAX_STR_SIZE];
	char dummy[MAX_STR_SIZE];	

	while(!feof(f_subj)) {
		fscanf(f_subj, "%d", &todo_id);
		fscanf(f_subj, "%c", &dot_dot);
		fgets(todo, MAX_STR_SIZE, f_subj);
		strncpy(dummy, todo, MAX_TODO_SIZE);
		for(int i = 0; i < MAX_TODO_SIZE; i++) {
			if(dummy[i] == '\n') {
				dummy[i] = '\0';
				break;
			}
		}
		if(!feof(f_subj)) {
			printf("|  # - %-40s #\n", dummy);
		}
	}
	printf("|  ");
    for(int i = 0; i < SUBJECT_TITLE_SIZE; i++) {
        printf("#");
    }
	printf("\n");
}
