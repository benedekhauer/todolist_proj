#include "display_subjects.h"
#include <stdio.h>
#include "util.h"


void proc_disp(void) {
	if(isFileEmpty(FILE_LIST) == TRUE) {
        printf("| Bot> Your subjects list is empty.\n");
        return;
    }

	print_subjects();
}
