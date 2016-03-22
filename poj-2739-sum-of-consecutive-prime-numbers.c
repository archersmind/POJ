/*
 * =====================================================================================
 *
 *       Filename:  poj-2739-sum-of-consecutive-prime-numbers.c
 *
 *    Description:  Prime numbers
 *
 *        Version:  1.0
 *        Created:  2016年03月21日 21时43分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#define MAX_SIZE 1001

unsigned short res[MAX_SIZE];
unsigned short prime[MAX_SIZE];
unsigned short ans[MAX_SIZE] = {0};

int isPrime(int num) {

    int i;

    if (num == 1) {
        return 0;
    } else if (num == 2) {
        return 1;
    } else if (num % 2 == 0) {
        return 0;
    } else {
        for (i = 3; i < num; i+=2) {
            if (num % i == 0) return 0;
        }
    }

    return 1;
}

void calculate(void) {

    int i, j, sum, count;

    for (i = 1; i < MAX_SIZE; i++) {
        if (isPrime(i)) {
            prime[i] = 1;
        }
    }

    for (i = 1; i < MAX_SIZE; i++) {
        printf ("curr i = %d \n", i);
        sum = 0;
        count = 0;
        for (j = 1; sum < i && j < MAX_SIZE; j++) {
            if (prime[j]) {
                sum += j;
                count++;
                printf ("prime %d sum = %d count = %d\n", j, sum, count);
            }

            if (sum == i) {
                ans[i] = count;
            } else if (sum > i && prime[i]) {
                ans[i] = 1;
            }
        }
    }

    printf ("ans[1] = %d ans[2] = %d \n", ans[1], ans[2]);
    for (i = 0; i < 10; i++) {
        printf ("Ans[%d] = %d \n", i, ans[i]);
    }
}

int main(void) {

    int input;

    calculate();

    while(scanf("%d", &input), input != 0) {

    }

    return 0;

}

