/*
 * @file file_helpers.h
 */

void add_to_gitignore(char[]);

// checks if the character is 0->9, a->z, A->Z, '\n' or '\0'
int isAscii(char);

// checks if name entered is acceptable
int isAccepted(char[]);

//checks if a file already exists
int file_exists_already(char[]);

