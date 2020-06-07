#include "initialize.h"
#include <stdio.h>
#include "util.h"


void initialize_all(void) {	
	generate_commands();
	generate_all_files();
	generate_info();
	generate_username();
	generate_nonempties();
}


void generate_commands(void) {
	FILE* commands = fopen(FILE_CMD, "r");
    if(commands == NULL) {
        commands = fopen(FILE_CMD, "w");
        fprintf(commands, "|\n");
        fprintf(commands, "|   ######## COMMANDS #########\n");
        fprintf(commands, "|   #  Reset :           init #\n");
        fprintf(commands, "|   #  Show subjects:    disp #\n");
        fprintf(commands, "|   #  Add subject :     adds #\n");
        fprintf(commands, "|   #  Add todo :        addt #\n");
        fprintf(commands, "|   #  Delete subject:   dels #\n");
        fprintf(commands, "|   #  Delete todo:      delt #\n");
        fprintf(commands, "|   #  Move todo to top: mvtp #\n");
        fprintf(commands, "|   #  Random todo:      rndm #\n");
        fprintf(commands, "|   #  Clear subject:    clrs #\n");
        fprintf(commands, "|   #  Print subject:    prnt #\n");
        fprintf(commands, "|   #  Change username:  usrn #\n");
        fprintf(commands, "|   #  Useful info:      info #\n");
        fprintf(commands, "|   #  Show commands:    help #\n");
        fprintf(commands, "|   #  Exit:             exit #\n");
        fprintf(commands, "|   ###########################\n");
        fprintf(commands, "|\n");
    }
    fclose(commands);
}
void generate_all_files(void) {
	FILE* all = fopen(FILE_LIST, "r");
    if(all == NULL) {
        all = fopen(FILE_LIST, "w");
        fprintf(all, "%s", EMPTY_STRING);
    }
    fclose(all);
}
void generate_info(void) {
	FILE* info = fopen(FILE_INFO, "r");
    if(info == NULL) {
        info = fopen(FILE_INFO, "w");
        fprintf(info,"|\n");
        fprintf(info,"|    ################ INFORMATION ################\n");
        fprintf(info,"|    # You can arrange your todolist by typing   #\n");
        fprintf(info,"|    # commands (type help for all commands).    #\n");
        fprintf(info,"|    # A subject is like a folder, and it can    #\n");
        fprintf(info,"|    # contain todos that you type in.           #\n");
        fprintf(info,"|    # Initially, everything is empty, so you    #\n");
        fprintf(info,"|    # will have to create all your subjects.    #\n");
        fprintf(info,"|    #                                           #\n");
        fprintf(info,"|    # WARNING: For the program to function,     #\n");
        fprintf(info,"|    # do not delete any files or you will need  #\n");
        fprintf(info,"|    # to reset your lists and lose data.        #\n");
        fprintf(info,"|    # ----------------------------------------- #\n");
        fprintf(info,"|    # ENJOY!                   - Benedek Hauer  #\n");
        fprintf(info,"|    #############################################\n");
        fprintf(info,"|\n");

    }
    fclose(info);
}
void generate_username(void) {
	FILE* user = fopen(FILE_USERNAME, "r");
    if(user == NULL) {
        user = fopen(FILE_USERNAME, "w");
        fprintf(user, "%s", DEFAULT_USERNAME);
    }
    fclose(user);
}
void generate_nonempties(void) {
	FILE* ne = fopen(FILE_NE, "r");
    if(ne == NULL) {
        ne = fopen(FILE_NE, "w");
        fprintf(ne, "%s", EMPTY_STRING);
    }
    fclose(ne);
}
