#include "random_todo.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proc_rndm(void) {
	srand(time(0));
	if(isFileEmpty(FILE_LIST) == TRUE) {
		printf("| Bot> There are no subjects.\n");
		return;
	}

	if(allEmpty() == TRUE) {
		printf("| Bot> All subjects are empty.\n");
		return;
	}

	printf("| Bot> Info: The randomizer selects the top todo of a random subject.\n");

	int nbNonEmpty = line_count(FILE_NE);
	

	int randomLine = rand() % nbNonEmpty;


	FILE* f_ne = fopen(FILE_NE, "r");
	FILE* f_rand_subj;
	char randomSubj[MAX_STR_SIZE];
	char randomTodo[MAX_STR_SIZE];
	char dummy;
	int id;
	for(int i = 0; i < nbNonEmpty; i++) {
		fgets(randomSubj, MAX_STR_SIZE, f_ne);
		if(i ==	randomLine) {
			correct(randomSubj);
			f_rand_subj = fopen(randomSubj, "r");
			fscanf(f_rand_subj, "%d", &id);
			fscanf(f_rand_subj, "%c", &dummy);	
			fgets(randomTodo, MAX_STR_SIZE, f_rand_subj);
			break;
		}
	}
	fclose(f_ne);
	fclose(f_rand_subj);
	printf("| Bot> Random todo:\n|       Subject: %s\n|       Todo: %s", randomSubj, randomTodo);
}
