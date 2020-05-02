#include "update_helpers.h"
#include <stdio.h>
#include <string.h>
#include "util.h"

void update_nextId(void) {
	
	if(isFileEmpty(FILE_LIST) == TRUE) {
		return;
	}

	if(allEmpty() == TRUE) {
		FILE* f_nextId = fopen(FILE_NEXTID, "w");
		fprintf(f_nextId, "%d", ZERO);
		fclose(f_nextId);
	}
}

void update_nonempties(void) {
	if(isFileEmpty(FILE_LIST) == TRUE) {
		return;
	}	

	FILE* f_nonempties = fopen(FILE_NE, "w");
	char line_subj[MAX_STR_SIZE];
	FILE* all_files = fopen(FILE_LIST, "r");
    char line[MAX_FILENAME_SIZE];
	char corrected[MAX_FILENAME_SIZE];
    while(!feof(all_files)) {
        fgets(line, MAX_FILENAME_SIZE, all_files);
		if(feof(all_files)) {break;}
		strncpy(corrected, line, MAX_FILENAME_SIZE);
        correct(corrected);
        if(isFileEmpty(corrected) == FALSE) {
        	fprintf(f_nonempties, "%s", line);
		}
    }
	fclose(f_nonempties);
	fclose(all_files);

}
