/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int input[7] = {0};
char flags[60001] = {0};
int sum = 0;
int counter = 0;

void init() {
	int i;
	sum = 0;
	memset(flags, 0, sizeof(flags));
    flags[0] = 1;
	for (i = 1; i <=6; i++) {
		scanf("%d", &input[i]);
		sum += input[i] * i;
	}
    //printf("sum = %d\n", sum);
	if (sum == 0)
		exit(0);
}


int main(void) {

	int i, j, k;

	while (++counter) {
		init();
		if (sum % 2) {
		    printf ("Collection #%d:\n", counter);
		    printf ("Can't be divided.\n\n");
		    continue;
	    }
		
		//printf("sum=%d\n", sum);
		for (i = 1; i <= 6; i++) {
			if (input[i] == 0) {
				continue;
			}

			for (j = sum/2; j >= 0; j--) {
			    //printf("flags[%d]=%d\n", j, flags[j]);
				if (flags[j] == 1) {
					for (k = 1; k <= input[i]; k++) {
						if (j + k * i > sum/2 || flags[k * i + j] == 1)
							break;
						flags[k * i + j] = 1;
						if (flags[sum/2] == 1)
							break;
					}
				}
			}
		}

		if (flags[sum/2] == 1) {
			printf ("Collection #%d:\n", counter);
			printf ("Can be divided.\n\n");
		} else {
			printf ("Collection #%d:\n", counter);
			printf ("Can't be divided.\n\n");
		}
	}
	return 0;
}