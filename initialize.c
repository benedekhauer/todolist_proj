#include "initialize.h"
#include <stdio.h>
#include "util.h"


void initialize_all(void) {	
	generate_all_files();
	generate_username();
}


void generate_all_files(void) {
	FILE* all = fopen(FILE_LIST, "r");
    if(all == NULL) {
        all = fopen(FILE_LIST, "w");
        fprintf(all, "%s", EMPTY_STRING);
    }
    fclose(all);
}

void generate_username(void) {
	FILE* user = fopen(FILE_USERNAME, "r");
    if(user == NULL) {
        user = fopen(FILE_USERNAME, "w");
        fprintf(user, "%s", DEFAULT_USERNAME);
    }
    fclose(user);
}
