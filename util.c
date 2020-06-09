#include <stdio.h>
#include "util.h"
#include <string.h>
#include <stdlib.h>
#include "initialize.h"

int missing(const char filename[]) {
	FILE* file = fopen(filename, "r");
	if(file == NULL) {
		print_hrst_msg();
		return TRUE;
	}
	fclose(file);
	return FALSE;
}

void print_hrst_msg(void) {
	printf("| Bot> ### Files missing. Run 'hrst' to reset everything.\n");
}


void print_line(void) {
    printf("|-------------------------------------------------------------------\n");
}
void generate_files(void) {
	initialize_all();
}

void print_subjects(void) {
	M_RET_IF_TRUE(missing(FILE_LIST));	
	FILE* file = fopen(FILE_LIST, "r");
	char line[MAX_STR_SIZE];
	print_line();
	printf("|   ############## SUBJECTS ##############\n");
	do{
		fgets(line, MAX_STR_SIZE, file);
		if(feof(file)) {break;}
		correct(line);
		int nbtodos = get_nb_todos(line);
		int nb_digits = get_digits(nbtodos);
		
		switch(nb_digits) {
			case 1: printf("|   #    %-22s (%d)%7s\n", line, nbtodos, HASH); break;
			case 2: printf("|   #    %-22s (%d)%6s\n", line, nbtodos, HASH); break;
			case 3: printf("|   #    %-22s (%d)%5s\n", line, nbtodos, HASH); break;
			case 4: printf("|   #    %-22s (%d)%4s\n", line, nbtodos, HASH); break;
			case 5: printf("|   #    %-22s (%d)%3s\n", line, nbtodos, HASH); break;
			default: printf("|   #    %-22s (%d)%2s\n", line, nbtodos, HASH); break;
		}

	} while(!feof(file));
	printf("|   ######################################\n");
	print_line();
	fclose(file);
}

int get_nb_todos(const char subject[]) {
	if(missing(subject) == TRUE) {return 0;}
	if(isFileEmpty(subject)) {return 0;}
	FILE* f_subj = fopen(subject, "r");
	int lineCount = 0;
	char line[MAX_STR_SIZE];
	while(!feof(f_subj)) {
		fgets(line, MAX_STR_SIZE, f_subj);
		if(feof(f_subj)) {
			fclose(f_subj);
			return lineCount;}
		lineCount++;
	}
	fclose(f_subj);
	return lineCount;
}

int get_digits(int nb) {
	if(nb < 10) {return 1;}
	else if(nb < 100) {return 2;}
	else if(nb < 1000) {return 3;}
	else if(nb < 10000) {return 4;}
	else if(nb < 100000) {return 5;}
	else {return 6;}
}

char* get_username(void) {
	generate_username();
	char username[USERNAME_SIZE];
    FILE* file_usr = fopen(FILE_USERNAME, "r");
    fscanf(file_usr, "%s", username);
    fclose(file_usr);
	char* toRet = calloc(USERNAME_SIZE, sizeof(char));
	strncpy(toRet, username, USERNAME_SIZE);
	return toRet;
}

int isFileEmpty(const char filename[]) {
	FILE* file = fopen(filename, "r");
	char first;
	if((fscanf(file, "%c", &first)) == EOF) { 
		fclose(file);
		return TRUE;
	}
	fclose(file);
	return FALSE;
}


char parse_answer(const char read[]) {
    char str[1];
    str[0] = read[0];
    if(read[1] != '\n') {return 'X';}
    if(strcmp(str, "Y") == 0 || strcmp(str, "y") == 0) {return 'Y';}
    else if(strcmp(str, "N") == 0 || strcmp(str, "n") == 0) {return 'N';}
    else {return 'X';}
}


int confirm(const char username[]) {
	char yn = 'X';
    while(yn == 'X') {
        printf("| %s> (Y/N): ", username);
        char s_answer[MAX_STR_SIZE];
        char s_check[1];
        fgets(s_answer, MAX_STR_SIZE, stdin);
        yn = parse_answer(s_answer);
    }
	return (yn == 'y' || yn == 'Y') ? TRUE : FALSE;
}


void print_nonempty_subjects(void) {
	M_RET_IF_TRUE(missing(FILE_LIST));
	printf("|   ############## SUBJECTS ##############\n");
	FILE* file = fopen(FILE_LIST, "r");
    char line[MAX_FILENAME_SIZE];
    do{
        fgets(line, MAX_STR_SIZE, file);
        if(feof(file)) {break;}
        correct(line);
		if(isFileEmpty(line) == FALSE) {
			int nbtodos = get_nb_todos(line);
        	int nb_digits = get_digits(nbtodos);

        	switch(nb_digits) {
            	case 1: printf("|   #    %-22s (%d)%7s\n", line, nbtodos, HASH); break;
            	case 2: printf("|   #    %-22s (%d)%6s\n", line, nbtodos, HASH); break;
            	case 3: printf("|   #    %-22s (%d)%5s\n", line, nbtodos, HASH); break;
            	case 4: printf("|   #    %-22s (%d)%4s\n", line, nbtodos, HASH); break;
            	case 5: printf("|   #    %-22s (%d)%3s\n", line, nbtodos, HASH); break;
            	default: printf("|   #    %-22s (%d)%2s\n", line, nbtodos, HASH); break;
        	}
	
		}
    } while(!feof(file));
	
	fclose(file);
	printf("|   ######################################\n");
}

int allEmpty(void) {
	if(missing(FILE_LIST) == TRUE){return TRUE;}
	FILE* all_files = fopen(FILE_LIST, "r");
	char line[MAX_FILENAME_SIZE];
	while(!feof(all_files)) {
		fgets(line, MAX_FILENAME_SIZE, all_files);
		correct(line);
		if(isFileEmpty(line) == FALSE) {
			fclose(all_files);
			return FALSE;
		}
	}
	fclose(all_files);
	return TRUE;
}	

void correct(char filename[]) {
    size_t len = strlen(filename);
	for(int i = 0; i < len; i++) {
        if(filename[i] == '\n') {
            filename[i] = '\0';
            return;
        }
    }
}

int file_exists(const char filename[]) {
	if(missing(FILE_LIST) == TRUE) {return FALSE;}
	FILE* all_files = fopen(FILE_LIST, "r");
    char line[MAX_STR_SIZE];
    while(!feof(all_files)) {
        fgets(line, MAX_STR_SIZE, all_files);
        correct(line);
        if(strcmp(line, filename) == 0) {
            fclose(all_files);
			if(missing(filename) == TRUE){return TRUE;}
            return TRUE;
        }
    }
    fclose(all_files);
    return FALSE;
}

void print_subject_name(const char subject[], int withEndline) {
	char copied[MAX_STR_SIZE];
	strncpy(copied, subject, MAX_STR_SIZE);
	correct(copied);

	long int length = strlen(copied);

	long int magic_number = (SUBJECT_TITLE_SIZE - length - 2)/2;
	printf("|  ");	
	for(int i = 0; i < magic_number; i++) {
		printf("#"); 		
	}
	printf(" ");
	printf("%s", copied);
	printf(" ");
	if(length % 2 != 0) {
		printf("#");
	}
	for(int i = 0; i < magic_number; i++) {
		printf("#");
	}
	if(withEndline == TRUE) {
		printf("\n");
	}
}

