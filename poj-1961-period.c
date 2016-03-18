/*
 * =====================================================================================
 *
 *       Filename:  poj-1961-period.c
 *
 *    Description:  KMP 
 *
 *        Version:  1.0
 *        Created:  2016年03月18日 22时26分09秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int  pattern[1024 * 1024] = {0};
char input[1024 * 1024] = {'\0'};

void kmp(char input[], size_t len) {

    int i = 0;
    int j = -1;
    pattern[0] = -1; 

    while (i < len) {
        while ((j > -1) && (input[j] != input[i])) {
            j = pattern[j];
        }

        i++;
        j++;
        pattern[i] = j;
    }
}

int main(void) {

    int num;
    int i = 0;
    int j = 1;
    while (scanf("%d", &num) && num) {

        scanf ("%s", input);
        size_t len = strlen(input);

        kmp(input, len);

        printf ("Test case #%d\n", j++);
        for (i = 1; i <= num; i++) {
            if ((i % (i - pattern[i])) == 0 &&
                    pattern[i] != 0) {
                printf ("%d %d\n", i, i / (i - pattern[i]));
            } 
        }
        printf("\n");

        memset(input, '\0', sizeof(input));
        memset(pattern, 0, sizeof(pattern));
    }

    return 0;
}
