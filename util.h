#define SUCCESS 0
#define FAILURE 1
#define FALSE 0
#define TRUE 1
#define ZERO 0

#define EXIT_CODE "EXIT"
#define ALL_CODE "ALL"

#define EXEC_FILE "main"

#define FILE_LIST "all_files.txt"
#define FILE_NE "nonempties.txt"
#define FILE_NEXTID "next_id.txt"
#define FILE_CMD "commands.txt"
#define FILE_USERNAME "username.txt"
#define FILE_SWAP "swap.txt"
#define MAKEFILE "Makefile"

#define MAX_STR_SIZE 10000
#define MAX_FILENAME_SIZE 21
#define MAX_TODO_SIZE 40
#define USERNAME_SIZE 10
#define SUBJECT_TITLE_SIZE 46

#define EMPTY_STRING ""

void print_line(void);

void print_subjects(void);

int isFileEmpty(char[]);

char parse_answer(char[]);

void print_nonempty_subjects(void);

int allEmpty(void);

void correct(char[]);

int file_exists(char[]);

void print_subject_name(char[], int);

int line_count(char[]);

int file_exists_in_nonempties(char[]);
