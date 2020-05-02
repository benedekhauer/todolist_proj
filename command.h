#define CMD_LINE_SIZE 27
#define CMD_SIZE 4

typedef enum {
	init = 0,
	adds = 1,
	addt = 2,
	dels = 3,
	delt = 4,
	rndm = 5,
	clrs = 6,
	prnt = 7,
	help = 8,
	exit = 9,
	none = 10
} command;

// checks if command exists
int isValid(command c);

// prints commands
int print_commands(void);

// prints command
void print_command(command c);

// parses command from string
command parse_command(char[]);
