#include "add_todo_helpers.h"
#include <stdio.h>
#include "util.h"
#include <string.h>
#include "print_subject_helpers.h"

int add_todo(const char subject[], const char username[]) {
	int todoId = generate_id();

	print_subject(subject);		

	FILE* f_subject = fopen(subject, "a");
	
	char todo[MAX_STR_SIZE];
	printf("| Bot: What do you want your todo to be? (< %d chars)\n", MAX_TODO_SIZE);
	do {
		printf("| %s> (%s to abort): ", username, EXIT_CODE);
		fgets(todo, MAX_STR_SIZE, stdin);	
	} while(strlen(todo) > MAX_TODO_SIZE);

	char noNewLine[MAX_STR_SIZE];
	strncpy(noNewLine, todo, MAX_TODO_SIZE);

	correct(noNewLine);

	if(strcmp(noNewLine, EXIT_CODE) == 0) {
		fclose(f_subject);
		return FALSE;
	}
		
	fprintf(f_subject, "%d:%s", todoId, todo);
	fclose(f_subject);
	printf("| Bot> Todo added successfully.\n");
	printf("| Bot> Do you want to add another todo to %s?\n", subject);

	return confirm(username) ? add_todo(subject, username) : TRUE;
	
}


int generate_id(void) {
	if(allEmpty()) {
		return FIRST_ID;
	}
	int nextUsableId = 2;
	while(exists(nextUsableId) == TRUE) {
		nextUsableId++;
	}
	return nextUsableId;
}


int exists(int id) {
	FILE* f_nonempties = fopen(FILE_NE, "r");
	char subject[MAX_STR_SIZE];
	while(!feof(f_nonempties)) {
		fgets(subject, MAX_STR_SIZE, f_nonempties);
		if(feof(f_nonempties)) {break;}
		correct(subject);
		FILE* f_subj = fopen(subject, "r");
		int readId;
		char not_needed_rest[MAX_STR_SIZE];
		while(!feof(f_subj)) {
			fscanf(f_subj, "%d", &readId);
			if(feof(f_subj)) {break;}
			fgets(not_needed_rest, MAX_STR_SIZE, f_subj);
			if(readId == id) {return TRUE;}
		}
	}
	return FALSE;
}
