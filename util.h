#pragma once
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define FALSE 0
#define TRUE 1
#define ZERO 0
#define FIRST_ID 1

#define MAX_TODO_COUNT 999999

#define EXIT_CODE "X"
#define ALL_CODE "ALL"

#define EXEC_FILE "todolist"

#define DEFAULT_USERNAME "You"
#define FILE_LIST "all_files.txt"
#define FILE_NE "nonempties.txt"
#define FILE_USERNAME "username.txt"
#define FILE_SWAP "swap.txt"
#define MAKEFILE "Makefile"


#define MAX_STR_SIZE 10000
#define MAX_FILENAME_SIZE 21
#define MAX_TODO_SIZE 40
#define USERNAME_SIZE 10
#define SUBJECT_TITLE_SIZE 46

#define EMPTY_STRING ""
#define HASH "#"

#define M_FREE(ptr) {if((ptr)!=NULL){free(ptr);ptr=NULL;}}

#define M_RET_IF_EXIT(str) {if((strcmp(str, EXIT_CODE)) == 0) {return;}}
#define M_RET_IF_TRUE(val) {if((val) == TRUE) {return;}}

#define M_RET_IF_FALSE(val) {if((val) == FALSE) {return;}}
#define M_RET_FAIL_IF_NULL(val) {if((val) == NULL) {return FAILURE;}}


#define M_RET_IF_NULL(p) {if((p) == NULL) {return;}}

#define M_PRINT_HRST_RET(ptr) \
	{if(ptr == NULL) {printf("Files missing. Run 'hrst' to reset everything.\n");return;}}

int missing(const char[]);

void print_hrst_msg(void);

void generate_files(void);

void print_line(void);

char* get_username(void);

void print_subjects(void);

int get_nb_todos(const char[]);

int get_digits(int);

int isFileEmpty(const char[]);

char parse_answer(const char[]);

int confirm(const char[]);

void print_nonempty_subjects(void);

int allEmpty(void);

void correct(char[]);

int file_exists(const char[]);

void print_subject_name(const char[], int);

int line_count(char[]);

int file_exists_in_nonempties(char[]);
