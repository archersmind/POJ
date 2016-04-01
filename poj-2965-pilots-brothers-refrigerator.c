/*
 * =====================================================================================
 *
 *       Filename:  poj-2965-pilots-brothers-refrigerator.c
 *
 *    Description:  POJ 2965
 *
 *        Version:  1.0
 *        Created:  2016年03月30日 16时05分35秒
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

int currentStatus = 0x0000;

// Temp Path
int tempPath[17] = {0};
// Answer Path
int ansPath[17] = {0};

int ansFilpCount = 16;

// Filp methods
int methods[16] = {0xF888, 0xF444, 0xF222, 0xF111,
                   0x8F88, 0x4F44, 0x2F22, 0x1F11,
                   0x88F8, 0x44F4, 0x22F2, 0x11F1,
                   0x888F, 0x444F, 0x222F, 0x111F};

int filp(int input, int nMethod) {
    return input^methods[nMethod];
}

// pos: current pos of the lock 0~15
// level: deep of the bfs search
void bfs(int pos, int level) {

    int i;
    // complete
    if (currentStatus == 0x0000) {

        if (ansFilpCount > level)
            ansFilpCount = level;        

        for (i = 1; i <= ansFilpCount; i++) {
            ansPath[i] = tempPath[i]; 
        }

        return;
    }

    if (pos >= 16)
        return;

    // Keep searching on next pos
    bfs(pos + 1, level);

    currentStatus = filp(currentStatus, pos);
    // record the temp path
    tempPath[level + 1] = pos;

    // Next pos and Next level
    bfs(pos + 1, level + 1);

    currentStatus = filp(currentStatus, pos);
}

int main(void) {

    int i, j;
    char lock;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%c", &lock);
            if (lock == '+') {
                currentStatus = currentStatus^(1 << (16 - (4 * i + j + 1)));
            }
        }
        // Consume the `Enter`
        getchar();
    }

    bfs(0, 0);

    printf ("%d\n", ansFilpCount);
    for (i = 1; i <= ansFilpCount; i++) {

        int x, y;
        if ((ansPath[i] + 1) % 4 == 0)
            x = 4;
        else x= (ansPath[i] + 1) % 4;

        if ((ansPath[i] + 1) % 4 == 0)
            y = (ansPath[i] + 1) / 4;
        else y = ((ansPath[i] + 1) / 4) + 1;

        printf ("%d %d\n", y, x);
    }

    return 0;
}
