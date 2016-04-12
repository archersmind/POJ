/*
 * =====================================================================================
 *
 *       Filename:  poj-1979-red-and-black.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2016年04月12日 17时29分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 20

int count = 0;
int w, h;

char tiles[MAX][MAX] = {'\0'};

// Actions Move Up/Down/Left/Right
int act[4][2] = {
    { 0,    -1   }, // Move Up
    { 0,    1   }, // Move Down
    { -1,   0   }, // Move Lefe
    { 1,    0   }  // Move Right
};

void DFS(int x, int y) {
    printf ("DFS x=%d y=%d \n", x, y);
    int i, tempx, tempy;

    tiles[x][y] = '#';
    count++;

    for(i = 0; i < 4; i++) {
        tempx = x + act[i][0];
        tempy = y + act[i][1];
        printf ("tempx = %d tempy = %d \n", tempx, tempy);
        if ((tempx >= 0 && tempx < w) &&
                (tempy >= 0 && tempy < h) &&
                    tiles[tempx][tempy] == '.') {
            printf ("tiles[%d][%d] = %c \n", tempx, tempy, tiles[tempx][tempy]);
            DFS(tempx, tempy);
        }
    }
}


int main(void) {

    int startx, starty;
    int i, j;
    while (scanf("%d %d", &w, &h) && w && h) {

        memset(tiles, 0, sizeof(tiles));

        for (i = 0; i< h; i++) {
            scanf("%s", tiles[i]);
            printf ("tiles[%d] = %s \n", i, tiles[i]);
            for (j = 0; j < w; j++) {
                if (tiles[i][j] == '@') {
                    startx = j;
                    starty = i;
                }
            }
        }
        count = 0;
        printf ("startx = %d starty = %d \n", startx, starty);
        DFS(startx, starty);

        printf ("%d\n", count);
    }

    return 0;
}
