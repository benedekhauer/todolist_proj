#include "remove_subject_helpers.h"
#include <stdio.h>
#include "util.h"
#include <string.h>

void delete_file(char filename[]) {
	remove(filename);
	FILE* all_files = fopen(FILE_LIST, "r");
	FILE* swap = fopen(FILE_SWAP, "w");
	char line[MAX_STR_SIZE];
	char dummy[MAX_STR_SIZE];
	while(!feof(all_files)) {
		fgets(line, MAX_STR_SIZE, all_files);
		strncpy(dummy, line, MAX_STR_SIZE);
		correct(dummy);
		if(feof(all_files)) {break;}
		if(strcmp(dummy,filename) != 0) {
			fprintf(swap, "%s", line);
		}
	}
	fclose(all_files);
	fclose(swap);
	remove(FILE_LIST);
	rename(FILE_SWAP, FILE_LIST);
	FILE* newSwap = fopen(FILE_SWAP, "w");
	fprintf(newSwap, "%s", EMPTY_STRING);
	fclose(newSwap);
	return;
}
