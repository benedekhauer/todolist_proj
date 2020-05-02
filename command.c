#include <stdio.h>
#include "command.h"
#include "util.h"
#include <string.h>

#define NAME_INIT "init"
#define NAME_ADDS "adds"
#define NAME_ADDT "addt"
#define NAME_DELS "dels"
#define NAME_DELT "delt"
#define NAME_RNDM "rndm"
#define NAME_CLRS "clrs"
#define NAME_PRNT "prnt"
#define NAME_HELP "help"
#define NAME_EXIT "exit"

int isValid(command c) {
	if(c == init || c == adds || c == addt || c == dels || c == delt || 
	   c == rndm || c == clrs || c == prnt || c == help || c == exit) {
		return TRUE;
	}
	return FALSE;
}

int print_commands(void) {
	FILE* cmds = fopen(FILE_CMD, "r");
	if(cmds == NULL) {
		return FAILURE;
	}
	char line[CMD_LINE_SIZE];
	while(!feof(cmds)) {
		fgets(line, CMD_LINE_SIZE, cmds);
		if(!feof(cmds)) {
			printf("%s", line);
		}
	}
	fclose(cmds);
	return SUCCESS;
}

void print_command(command cmd) {
	switch(cmd) {
		case init: printf("init\n");return;
		case adds: printf("adds\n");return;
		case addt: printf("addt\n");return;
		case dels: printf("dels\n");return;
		case delt: printf("delt\n");return;
		case rndm: printf("rndm\n");return;
		case clrs: printf("clrs\n");return;
		case prnt: printf("prnt\n");return;
		case help: printf("help\n");return;
		case exit: printf("exit\n"); return;
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
	else if(strcmp(str, NAME_ADDS) == 0) {return adds;}
	else if(strcmp(str, NAME_ADDT) == 0) {return addt;}
	else if(strcmp(str, NAME_DELS) == 0) {return dels;}
	else if(strcmp(str, NAME_DELT) == 0) {return delt;}
	else if(strcmp(str, NAME_RNDM) == 0) {return rndm;}
	else if(strcmp(str, NAME_CLRS) == 0) {return clrs;}
	else if(strcmp(str, NAME_PRNT) == 0) {return prnt;}
	else if(strcmp(str, NAME_HELP) == 0) {return help;}
	else if(strcmp(str, NAME_EXIT) == 0) {return exit;}
	else {return none;}	
}
















