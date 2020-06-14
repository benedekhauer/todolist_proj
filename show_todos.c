#include "show_todos.h"
#include <stdio.h>
#include "util.h"
#include "print_subject_helpers.h"


void proc_show(void) {
	M_RET_IF_TRUE(missing(FILE_LIST));
	FILE* f_all = fopen(FILE_LIST, "r");
	char line[MAX_STR_SIZE];
	
	while(!feof(f_all)) {
		fgets(line, MAX_STR_SIZE, f_all);
		correct(line);
		if(!feof(f_all) && missing(line) == FALSE && isFileEmpty(line) == FALSE) {
			print_subject(line);
			printf("|\n");
		}
		else {
			break;
		}
	}
	fclose(f_all);
}
