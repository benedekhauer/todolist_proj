#include <stdio.h>
#include "command.h"
#include "util.h"
#include <string.h>
#include "initialize.h"

#define NAME_INIT "init"
#define NAME_DISP "disp"
#define NAME_ADDS "adds"
#define NAME_ADDT "addt"
#define NAME_DELS "dels"
#define NAME_DELT "delt"
#define NAME_MVTP "mvtp"
#define NAME_RNDM "rndm"
#define NAME_CLRS "clrs"
#define NAME_PRNT "prnt"
#define NAME_SHOW "show"
#define NAME_USRN "usrn"
#define NAME_INFO "info"
#define NAME_HELP "help"
#define NAME_QUIT "quit"

int isValid(command c) {
	if(c == init || c == disp || c == adds || c == addt || c == dels || c == delt || 
	   c == mvtp || c == rndm || c == clrs || c == prnt || c == show || c == usrn || 
	   c == info || c == help || c == quit) {
		return TRUE;
	}
	return FALSE;
}

void print_commands(void) {
	printf("|\n");
    printf("|   ######## COMMANDS #########\n");
    printf("|   #  Reset :           init #\n");
    printf("|   #  Show subjects:    disp #\n");
    printf("|   #  Add subject :     adds #\n");
    printf("|   #  Add todo :        addt #\n");
    printf("|   #  Delete subject:   dels #\n");
    printf("|   #  Delete todo:      delt #\n");
    printf("|   #  Move todo to top: mvtp #\n");
    printf("|   #  Random todo:      rndm #\n");
    printf("|   #  Clear subject:    clrs #\n");
    printf("|   #  Print subject:    prnt #\n");
	printf("|   #  Show all todos:   show #\n");
    printf("|   #  Change username:  usrn #\n");
    printf("|   #  Useful info:      info #\n");
    printf("|   #  Show commands:    help #\n");
    printf("|   #  Exit:             quit #\n");
    printf("|   ###########################\n");
    printf("|\n");
}

void print_command(command cmd) {
	switch(cmd) {
		case init: printf("init\n");return;
		case disp: printf("disp\n");return;
		case adds: printf("adds\n");return;
		case addt: printf("addt\n");return;
		case dels: printf("dels\n");return;
		case delt: printf("delt\n");return;
		case mvtp: printf("mvtp\n");return;
		case rndm: printf("rndm\n");return;
		case clrs: printf("clrs\n");return;
		case prnt: printf("prnt\n");return;
		case show: printf("show\n");return;
		case usrn: printf("usrn\n");return;
		case info: printf("info\n");return;
		case help: printf("help\n");return;
		case quit: printf("quit\n"); return;
		default: printf("none\n");return;
	}
}

command parse_command(char read[]) {
	char str[CMD_SIZE];
	for(int i = 0; i < CMD_SIZE; i++) {
		str[i] = read[i];
	}
	if(read[CMD_SIZE] != '\n') {return none;}
	if(strcmp(str, NAME_INIT) == 0) {return init;}
	else if(strcmp(str, NAME_DISP) == 0) {return disp;}
	else if(strcmp(str, NAME_ADDS) == 0) {return adds;}
	else if(strcmp(str, NAME_ADDT) == 0) {return addt;}
	else if(strcmp(str, NAME_DELS) == 0) {return dels;}
	else if(strcmp(str, NAME_DELT) == 0) {return delt;}
	else if(strcmp(str, NAME_MVTP) == 0) {return mvtp;}
	else if(strcmp(str, NAME_RNDM) == 0) {return rndm;}
	else if(strcmp(str, NAME_CLRS) == 0) {return clrs;}
	else if(strcmp(str, NAME_PRNT) == 0) {return prnt;}
	else if(strcmp(str, NAME_SHOW) == 0) {return show;}
	else if(strcmp(str, NAME_USRN) == 0) {return usrn;}
	else if(strcmp(str, NAME_INFO) == 0) {return info;}
	else if(strcmp(str, NAME_HELP) == 0) {return help;}
	else if(strcmp(str, NAME_QUIT) == 0) {return quit;}
	else {return none;}	
}
