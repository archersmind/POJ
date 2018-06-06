#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WEIGHT 10001
#define MAX_NUM_COINS 501 // max number of various coins
#define MAX_VALUE 10000000

int dp[MAX_WEIGHT];  // index indicates the weight value indicates the amount of money
int p[501] = {0};    // p is value of the coin
int w[501] = {0};    // w is the weight of the coin

int min(int i, int j) {
    return i > j ? j : i;
}

int main() {
    int T;    // number of test cases
    int E, F; // For the weight calculation of the piggy bank
    int pw;   // Weight of the piggy bank
    int n;   // Number of various coins

    scanf ("%d", &T);
    while (T) {
        int i = 0;
        int j = 0;
        for (i = 0; i < MAX_WEIGHT; i++) {
            dp[i] = MAX_VALUE;
        }
        dp[0] = 0;

        scanf ("%d%d", &E, &F);
        pw = F - E;
        scanf ("%d", &n);
        for (i = 0; i < n; i++) {
            scanf ("%d%d", &p[i], &w[i]);
        }

        for (i = 0; i < n; i++) {
            for (j = w[i]; j <= pw; j++) {
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
            }
        }        
        if (dp[pw] == MAX_VALUE) {
            printf("This is impossible.\n");
        } else {
           printf("The minimum amount of money in the piggy-bank is %d.\n",dp[pw]); 
        }
        T--;
    }

    return 0;
}