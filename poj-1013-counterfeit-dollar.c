/*
 * =====================================================================================
 *
 *       Filename:  poj-1013-counterfeit-dollar.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年03月16日 11时28分16秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct status {
    int possiblyTrue;
    int possiblyLight;
    int possiblyHeavy;
} status[13];

int main(void) {

    int times;
    int i, j, k, ans;
    scanf("%d", &times);

    char left[12] = {'\0'};
    char right[12] = {'\0'};
    char judge[12] = {'\0'};

    while (times--) {

        memset(status, 0, sizeof(status));

        for (i = 0; i < 3; i++) {

            scanf("%s %s %s", left, right, judge);

            // If even, then every coins on each side is true
            if (strncmp(judge, "even", strlen(judge)) == 0) {
                for (j = 0; j < strlen(left); j++) {
                    status[left[j] - 'A'].possiblyTrue = 1;
                    status[right[j] - 'A'].possiblyTrue = 1;
                }
            // If up(right side), then every coin on right suspected to be counterfeited(lighter)
            // in contrast, every coin on left suspected to be counterfeited(heavier)
            // Coins not on the balance is true
            } else if (strncmp(judge, "up", strlen(judge)) == 0) {
                for (j = 0; j < strlen(left); j++) {
                    status[right[j]- 'A'].possiblyLight = 1;
                    status[left[j] - 'A'].possiblyHeavy = 1;
                }

                for (j = 0; j <= 'L' - 'A'; j++) {

                    char temp = 'A' + j;
                    int found = 0;
                    for (k = 0; k < strlen(left); k++) {
                        if (temp == left[k]) {
                            found = 1;
                            break;
                        }
                    }

                    for (k = 0; k< strlen(right); k++) {
                        if (temp == right[k]) {
                            found = 1;
                            break;
                        }
                    }
                    
                    if(!found) {
                        status[j].possiblyTrue = 1;
                    }
                }

            } else {
                for (j = 0; j < strlen(left); j++) {
                    status[right[j] - 'A'].possiblyHeavy = 1;
                    status[left[j]- 'A'].possiblyLight = 1;
                }           

                for (j = 0; j <= 'L' - 'A'; j++) {

                    char temp = 'A' + j;
                    int found = 0;
                    for (k = 0; k < strlen(left); k++) {
                        if (temp == left[k]) {
                            found = 1;
                            break;
                        }
                    }

                    for (k = 0; k< strlen(right); k++) {
                        if (temp == right[k]) {
                            found = 1;
                            break;
                        }
                    }
                    
                    if(!found) {
                        status[j].possiblyTrue = 1;
                    }
                }
            }
        }

        // Result
        for (k = 0; k <= 'L' - 'A'; k++) {
            if (status[k].possiblyTrue || (status[k].possiblyHeavy && status[k].possiblyLight)) {
                continue;
            }

            ans = k;
        }

        if (status[ans].possiblyLight) {
            printf("%c is the counterfeit coin and it is light.\n", 'A' + ans);
        } else {
            printf("%c is the counterfeit coin and it is heavy.\n", 'A' + ans);
        }
    }

    return 0;
}

