#include "add_todo_helpers.h"
#include <stdio.h>
#include "util.h"
#include <string.h>
#include "print_subject_helpers.h"

int add_todo(const char subject[], const char username[]) {
	FILE* f_nextid = fopen(FILE_NEXTID, "r");
	int todoId;
	fscanf(f_nextid, "%d", &todoId);	
	int nextId = todoId + 1;
	fclose(f_nextid);
	f_nextid = fopen(FILE_NEXTID, "w");
	fprintf(f_nextid, "%d", nextId);
	fclose(f_nextid);


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
