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
    { -1,    0   }, // Move Up
    {  1,    0   }, // Move Down
    {  0,    1   }, // Move Lefe
    {  0,   -1   }  // Move Right
};

void DFS(int x, int y) {
    int i, tempx, tempy;

    tiles[x][y] = '#';
    count++;

    for(i = 0; i < 4; i++) {
        tempx = x + act[i][0];
        tempy = y + act[i][1];
        if ((tempx >= 0 && tempx < h) &&
                (tempy >= 0 && tempy < w) &&
                    tiles[tempx][tempy] == '.') {
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
            for (j = 0; j < w; j++) {
                if (tiles[i][j] == '@') {
                    startx = i;
                    starty = j;
                }
            }
        }
        count = 0;
        DFS(startx, starty);

        printf ("%d\n", count);
    }

    return 0;
}
