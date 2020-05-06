#include "information.h"
#include <stdio.h>
#include "util.h"

void proc_info(void) {
	FILE* f_info = fopen(FILE_INFO, "r");
	char line[MAX_STR_SIZE];
	while(!feof(f_info)) {
		fgets(line, MAX_STR_SIZE, f_info);
		if(feof(f_info)) {return;}
		printf("%s", line);
	}
}
