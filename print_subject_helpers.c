#include <stdio.h>
#include "util.h"
#include "print_subject_helpers.h"
#include <string.h>

void print_subject(const char subject[]) {
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
	int nb_todos = get_nb_todos(subject);
	print_count_line(nb_todos);
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
	fclose(f_subj);
	printf("\n");
}

void print_count_line(int nb_todos) {
	int nbdigits = get_digits(nb_todos);
	switch(nbdigits) {
		case 1: printf("|  #  %d todos %35s\n", nb_todos, HASH); break;
		case 2: printf("|  #  %d todos %34s\n", nb_todos, HASH); break;
		case 3: printf("|  #  %d todos %33s\n", nb_todos, HASH); break;	
		case 4: printf("|  #  %d todos %32s\n", nb_todos, HASH); break;
		case 5: printf("|  #  %d todos %31s\n", nb_todos, HASH); break;
		default: printf("|  #  %d todos %30s\n", nb_todos, HASH); break;
	}
	printf("|  # ");
	for(int i = 0; i < 42; i++) {
		printf("=");
	}
	printf(" #\n");

}








