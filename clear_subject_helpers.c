#include "clear_subject_helpers.h"
#include <stdio.h>
#include "util.h"
#include "initialize.h"

void clear_all(void) {
	FILE* all_files = fopen(FILE_LIST, "r");
	FILE* to_clear;
    char line[MAX_FILENAME_SIZE];
    while(!feof(all_files)) {
        fgets(line, MAX_FILENAME_SIZE, all_files);
    	correct(line);
		to_clear = fopen(line, "w");
		fprintf(to_clear, "%s", EMPTY_STRING);
		fclose(to_clear);
	}
    fclose(all_files);
	printf("| Bot> All cleared successfully.\n");
}

