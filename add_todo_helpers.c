#include "add_todo_helpers.h"
#include <stdio.h>
#include "util.h"
#include <string.h>
#include "print_subject_helpers.h"

int add_todo(const char subject[], const char username[], int todoId) {
	if(todoId > MAX_TODO_COUNT) {
		printf("| Bot> You cannot add any more todos\n");
		return TRUE;
	}

	print_subject(subject);		

	char todo[MAX_STR_SIZE];
	printf("| Bot: What do you want your todo to be? (< %d chars)\n", MAX_TODO_SIZE);
	do {
		printf("| %s> (%s to abort): ", username, EXIT_CODE);
		fgets(todo, MAX_STR_SIZE, stdin);	
	} while(strlen(todo) > MAX_TODO_SIZE);

	char noNewLine[MAX_STR_SIZE];
	strncpy(noNewLine, todo, MAX_TODO_SIZE);

	correct(noNewLine);

	M_RET_IF_EXIT(noNewLine, FALSE);

	FILE* f_subject = fopen(subject, "a");	
	fprintf(f_subject, "%d:%s", todoId, todo);
	fclose(f_subject);
	printf("| Bot> Todo added successfully.\n");
	printf("| Bot> Do you want to add another todo to %s?\n", subject);

	return confirm(username) ? add_todo(subject, username, generate_id()) : TRUE;
	
}


int generate_id(void) {
	if(allEmpty()) {
		return FIRST_ID;
	}
	int nextUsableId = FIRST_ID;
	while(exists(nextUsableId) == TRUE) {
		nextUsableId++;
	}
	return nextUsableId;
}


int exists(int id) {
	FILE* all_files = fopen(FILE_LIST, "r");
	char subject[MAX_STR_SIZE];
	while(!feof(all_files)) {
		fgets(subject, MAX_STR_SIZE, all_files);
		if(feof(all_files)) {break;}
		correct(subject);
		if(isFileEmpty(subject) == FALSE) {
			FILE* f_subj = fopen(subject, "r");
			int readId;
			char not_needed_rest[MAX_STR_SIZE];
			while(!feof(f_subj)) {
				fscanf(f_subj, "%d", &readId);
				if(feof(f_subj)) {break;}
				fgets(not_needed_rest, MAX_STR_SIZE, f_subj);
				if(readId == id) {
					fclose(all_files);
					fclose(f_subj);
					return TRUE;}
			}
			fclose(f_subj);
		}
	}
	fclose(all_files);
	return FALSE;
}
