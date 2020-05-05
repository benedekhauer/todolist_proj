#include "add_todo_helpers.h"
#include <stdio.h>
#include "util.h"
#include <string.h>

void add_todo(const char subject[], const char username[]) {
	FILE* f_nextid = fopen(FILE_NEXTID, "r");
	int todoId; // TodoId of the todo that we're about to add
	fscanf(f_nextid, "%d", &todoId);	
	int nextId = todoId + 1;
	fclose(f_nextid);
	f_nextid = fopen(FILE_NEXTID, "w");
	fprintf(f_nextid, "%d", nextId);
	fclose(f_nextid);
	

	FILE* f_subject = fopen(subject, "a");
	
	char todo[MAX_STR_SIZE];
	printf("| Bot: What do you want your todo to be? (< %d chars)\n", MAX_TODO_SIZE);
	do {
		printf("| %s> (EXIT to abort): ", username);
		fgets(todo, MAX_STR_SIZE, stdin);	
	} while(strlen(todo) > MAX_TODO_SIZE);

	char noNewLine[MAX_STR_SIZE];
	strncpy(noNewLine, todo, MAX_TODO_SIZE);

	correct(noNewLine);

	if(strcmp(noNewLine, EXIT_CODE) == 0) {
		printf("| Bot> No changes. Aborted.\n");
		return;
	}
		
	fprintf(f_subject, "%d:%s", todoId, todo);
	fclose(f_subject);
	printf("| Bot> Todo added successfully.\n");
	return;	
}
