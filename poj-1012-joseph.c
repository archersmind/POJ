#include <stdio.h>

int ANS[14] = {0};

int test(int k, int m) {
    int i, t = 0;
    int curr = 2 * k;

    for (i = 1; i <= k; i++) {
        t = (t + m - 1) % curr;
        curr--;
        if (t < k) {
            return 0;
        }
    }

    return 1;
}

void marking(void) {
    int k, m;
    for (k = 1; k < 14; k++) {
        for (m = k + 1; ;m++) {
            if (test(k, m) == 1) {
                ANS[k - 1] = m;
                break;
            }
        }
    }
}

int main(void) {

    int input;

    marking();
    while (scanf("%d", &input) && input) {
        printf ("%d\n", ANS[input - 1]);
    }
    return 0;
}
