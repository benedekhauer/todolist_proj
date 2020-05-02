#include <stdio.h>
#include <string.h>
#include "util.h"
#include "add_subject_helpers.h"

int isAscii(char c) {
	if(c == '\n' || c == '\0') { return TRUE;}
	if(c >= 48 && c <= 57) {return TRUE;}
	if(c >= 65 && c <= 90) {return TRUE;}
	if(c >= 97 && c <= 122) {return TRUE;}
	return FALSE;
}


int isAccepted(char str[]) {
	if (str[0] == '\n' || str[0] == '\0') {return FALSE;}
	for(int i = 0; i < MAX_FILENAME_SIZE && str[i] != '\0'; i++) {
		if((isAscii(str[i])) == FALSE) {return FALSE;}
	}
	//str[MAX_FILENAME_SIZE] = '\0';
	return TRUE;
}

int file_exists_already(char filename[]) {
	FILE* file = fopen(FILE_LIST, "r");
	char scannedLine[MAX_FILENAME_SIZE];
	while(!feof(file)) {
		fgets(scannedLine, MAX_FILENAME_SIZE, file);
		
		for(int i = 0; i < MAX_FILENAME_SIZE; i++) {
			if(scannedLine[i] == '\n') {
				scannedLine[i] = '\0';
				break;
			}
		}
		
		if(strcmp(scannedLine,filename) == 0) {
			fclose(file);
			return TRUE;
		}
	}
	fclose(file);
	return FALSE;
}

