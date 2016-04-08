/*
 * =====================================================================================
 *
 *       Filename:  poj-2248-additional-chains.c
 *
 *    Description:  DFS problem 
 *
 *        Version:  1.0
 *        Created:  2016年04月08日 16时36分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Wang
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* MAX_LEN = log(100) + 1 */
#define MAX_LEN 11

int num[MAX_LEN] = {0};
int ans[MAX_LEN] = {0};
int input;
int length;

void DFS(int deepth) {
    int i;

    if (deepth > length)
        return; // pruning

    if (num[deepth - 1] == input) {

        if (deepth < length) {
            length = deepth;
            for (i = 0; i < deepth; i++) {
                ans[i] = num[i];
            }
        }
        return;
    }

    for (i = deepth - 1; i >= 0; i--) {
        num[deepth] = num[deepth - 1] + num[i];
        if (num[deepth] > input)
            continue; // pruning
        DFS(deepth + 1);
    }

}

int main(void) {

    int j;
    num[0] = 1;
 
    while (scanf("%d", &input) && (input != 0)) {
    
        length = MAX_LEN;
        DFS(1);
        for (j = 0; j < length; j++) {
            printf ("%d ", ans[j]);
        }
        printf ("\n");
    }

    return 0;
}
