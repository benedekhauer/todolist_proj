#include <stdio.h>
#include "change_username.h"
#include "util.h"
#include <string.h>
#include "initialize.h"

int proc_usrn(char* username) {

	char newUsername[MAX_STR_SIZE];

	printf("| Bot> Enter a new username (max %d characters).\n", USERNAME_SIZE);
	
	do {
		printf("| %s> (new username, %s to abort): ", username, EXIT_CODE);
		fgets(newUsername, MAX_STR_SIZE, stdin);

	} while(strlen(newUsername) > USERNAME_SIZE+1);

	for(int i = 0; i < USERNAME_SIZE+1; i++) {
        if(newUsername[i] == '\n') {
            newUsername[i] = '\0';
            break;
        }
    }

		

	if(strcmp(newUsername, EXIT_CODE) == 0) {
		printf("| Bot> No changes.\n");
		return FALSE;
	}

	generate_username();	
	FILE* file_usr = fopen(FILE_USERNAME, "w");
	fprintf(file_usr, "%s\n", newUsername);
	fclose(file_usr);

	printf("| Bot> Username changed to '%s'.\n", newUsername);
	return TRUE;
}
