#include "random_todo.h"
#include "util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void proc_rndm(void) {
	M_RET_IF_TRUE(missing(FILE_LIST));
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

	FILE* nonempties = fopen(FILE_NE, "w");
	FILE* all_files = fopen(FILE_LIST, "r");
	char line[MAX_STR_SIZE];
	char corrected[MAX_STR_SIZE];
	int nbNonEmpty = 0;
	while(!feof(all_files)) {
		fgets(line, MAX_STR_SIZE, all_files);
		if(feof(all_files)) {break;}
		strncpy(corrected, line, MAX_STR_SIZE);
		correct(corrected);
		if(isFileEmpty(corrected) == FALSE) {
			fprintf(nonempties, "%s", line);
			nbNonEmpty += 1;
		}
	}


	int randomLine = rand() % nbNonEmpty;
	fclose(nonempties);
	fclose(all_files);

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
			M_RET_IF_TRUE(missing(randomSubj));
			f_rand_subj = fopen(randomSubj, "r");
			fscanf(f_rand_subj, "%d", &id);
			fscanf(f_rand_subj, "%c", &dummy);	
			fgets(randomTodo, MAX_STR_SIZE, f_rand_subj);
			break;
		}
	}
	fclose(f_ne);
	remove(FILE_NE);
	fclose(f_rand_subj);
	printf("| Bot> Random todo:\n|       Subject: %s\n|       Todo: %s", randomSubj, randomTodo);
}
