/*
 * =====================================================================================
 *
 *       Filename:  poj-2406-power-strings.c
 *
 *    Description:  KMP problem 
 *                  http://www.matrix67.com/blog/archives/115
 *
 *        Version:  1.0
 *        Created:  2016年03月18日 15时52分22秒
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

    while (scanf("%s", input) && strcmp (input, ".")) {

        size_t len = strlen(input);
        int results = 0;

        kmp(input, len);

        if (pattern[len] == 0) {
            results = 1;
        } else {
            results = (len % (len - pattern[len]) == 0) ? len / (len - pattern[len]): 1;
        }

        printf ("%d\n", results);

        memset(input, '\0', sizeof(input));
        memset(pattern, 0, sizeof(pattern));
    }

    return 0;
}
