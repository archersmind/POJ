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

int ans;
int n; // number of rectangles for each case

int visit[20];
int mark[100][100];

// pos: current rect pos 1~N
// colorCnt: how many color brushes used
// rectCnt: rectangle count 1~N
void DFS(int pos, int colorCnt, int rectCnt) {

    if (rectCnt == numofCases) {
        if (ans > colorCnt) ans = colorCnt;
        return;
    }

    visit[pos] = 1;

    int i;
    for (i = r; i < n; i++) {
        
    } 
}

int main(void) {

    int i;
    int numofCases;
    scanf("%d", &numofCases);

    while(numofCases--) {
        scanf ("%d", &n);
        memset(mark, 0, sizeof(mark));
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d %d",
                    &rects[i].upLy,
                    &rects[i].upLx,
                    &rects[i].loRy,
                    &rects[i].loRx,
                    &rects[i].color); 
        } 
    } return 0; } 
