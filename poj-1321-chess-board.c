/*
 * =====================================================================================
 *
 *       Filename:  poj-1321-chess-board.c
 *
 *    Description:  POJ 1321
 *                  Another DFS problem
 *
 *        Version:  1.0
 *        Created:  2016年04月01日 17时07分09秒
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

// column which has be placed with chess piece
// 1: Placed
// 0: not placed
int columnPlaced[9] = {0};
int chessBoard[9][9] = {0};

int counter = 0;

// inputNum: number of rows of the chessBoard
// numChessPieces: number of chess pieces need to be placed
int inputNum, numChessPieces;

// row: The Row we're in
// n: How many pieces has been placed
void DFS(int row, int n) {

    int i;

    if (n == numChessPieces) {
        counter++;
        return;
    }

    if (row > inputNum) {
        return;
    }

    for (i = 0; i < inputNum; i++) {
        if (chessBoard[row][i] && !columnPlaced[i]) {
            columnPlaced[i] = 1;
            DFS(row + 1, n + 1);
            columnPlaced[i] = 0;
        }
    }

    DFS(row + 1, n);
}

int main(void) {

    int i, j;
    char temp;

    while (scanf("%d %d", &inputNum, &numChessPieces) != EOF) {
        // consume the `Enter`
        getchar();
        if (inputNum == -1 && numChessPieces == -1)
            break;

        memset(chessBoard, 0, sizeof(chessBoard));
        memset(columnPlaced, 0, sizeof(columnPlaced));

        counter = 0;

        for (i = 0; i < inputNum; i++) {
            for (j = 0; j < inputNum; j++) {
                scanf("%c", &temp);
                if (temp == '#') {
                    // `#` where can place a piece
                    chessBoard[i][j] = 1;
                }
            }
            // comsume the `Enter`
            getchar();
        }

        DFS(0, 0);
        printf ("%d\n", counter);
    }

    return 0;
}

