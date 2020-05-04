#define CMD_LINE_SIZE 27
#define CMD_SIZE 4

typedef enum {
	init,
	disp,
	adds,
	addt,
	dels,
	delt,
	rndm,
	clrs,
	prnt,
	help,
	exit,
	none
} command;

// checks if command exists
int isValid(command c);

// prints commands
int print_commands(void);

// prints command
void print_command(command c);

// parses command from string
command parse_command(char[]);
