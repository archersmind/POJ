/*
 * =====================================================================================
 *
 *       Filename:  poj-1691-painting-board.c
 *
 *    Description:  Another DFS porblem
 *
 *        Version:  1.0
 *        Created:  04/23/2016 04:04:24 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Rect {
    int upLx, upLy;  //coordinate of upper left
    int loRx, loRy;  //coordinate of lower right
    int color;       //color of the Rect
} Rect;

struct Rect rects[16];

int main(void) {

    int numofCases;
    int i;
    scanf("%d", &numofCases);

    while(numofCases--) {
        for (i = 0; i < numofCases; i++) {
            scanf("%d %d %d %d %d",
                    &rects[i].upLy,
                    &rects[i].upLx,
                    &rects[i].loRy,
                    &rects[i].loRx,
                    &rects[i].color); 
        } 
    }
    return 0;
}

