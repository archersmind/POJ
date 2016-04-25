/*
 * =====================================================================================
 *
 *       Filename:  poj-1691-painting-board.c
 *
 *    Description:  Another DFS porblem but with Topological theory
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
int deg[20]; // degree from the graph theory
int map[16][16]; // if connected between two rectangles

void buildMap() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (rects[i].loRy == rects[j].upLy &&
                    !(rects[i].upLx > rects[j].loRx
                        || rects[i].loRx < rects[j].upLx)) {
                deg[j]++;
                map[i][j] = 1;
            }
        }
    }
}

void DFS(int deep, int sum, int color) {

    //printf ("deep = %d sum = %d color = %d ans = %d and n = %d\n", \
            deep, sum, color, ans, n);
    if (sum > ans) return; // pruning
    if (deep == n) {
        ans = sum; 
        return;
    }

    int i,j;
    for (i = 0; i < n; i++) {
        if (!visit[i] && deg[i] == 0) {
            visit[i] = 1; 
            for (j = 0; j < n; j++) { // delete edge from i to j
                if (map[i][j])        // then in degree from i to j shoule be --
                    deg[j]--;
            }

            if (rects[i].color == color) {
                DFS(deep + 1, sum, color);
            } else {
                DFS(deep + 1, sum + 1, rects[i].color);
            }

            // back tracing
            for (j = 0; j < n; j++) {
                if (map[i][j])
                    deg[j]++;
            }
            visit[i] = 0;
        }
    }
}

int main(void) {

    int numofCases;
    scanf("%d", &numofCases);

    while(numofCases--) {
        scanf ("%d", &n);
        memset(deg, 0, sizeof(deg));
        memset(map, 0, sizeof(map));
        memset(visit, 0, sizeof(visit));

        int i;
        for (i = 0; i < n; i++) {
            scanf("%d %d %d %d %d",
                    &rects[i].upLy,
                    &rects[i].upLx,
                    &rects[i].loRy,
                    &rects[i].loRx,
                    &rects[i].color);
        }
        buildMap();
        ans = 20; // MAX brush count
        DFS(0, 0, 0);
        printf ("%d\n", ans);
    }

    return 0;
}
