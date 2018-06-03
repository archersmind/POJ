#include <stdio.h>
#include <stdlib.h>

const int M = 12881;
const int N = 3403;

int dp[12885] = {0};

int max (int x, int y) {
    return x > y ? x : y;
}

int main() {
    int i, j;
    int n, m;
    int w[N], d[M];

    scanf ("%d %d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d %d", w[i], d[i]);
    }

    //DP 0-1 pack
    for (i = 1; i <= n; i++) {
        for (j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j-w[i]] + d[i]);
            printf ("dp[%d]=%d\n", j, dp[j]);
        }
    }
    printf ("%d\n", dp[m]);

    return 0;
}