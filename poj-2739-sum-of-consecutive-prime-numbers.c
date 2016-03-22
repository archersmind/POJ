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
 * Some positive integers can be represented by a sum of one or more consecutive
 * prime numbers. How many such representations does a given positive integer
 * have? For example, the integer 53 has two representations 5 + 7 + 11 + 13 + 17
 * and 53. The integer 41 has three representations 2+3+5+7+11+13, 11+13+17, and
 * 41. The integer 3 has only one representation, which is 3. The integer 20 has
 * no such representations. Note that summands must be consecutive prime 
 * numbers, so neither 7 + 13 nor 3 + 5 + 5 + 7 is a valid representation for the
 * integer 20. 
 * Your mission is to write a program that reports the number of representations
 * for the given positive integer.
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#define MAX_SIZE 11000

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

    int i, j, k, sum, count, numOfPrimes;

    for (i = 1, j = 1; i < MAX_SIZE; i++) {
        if (isPrime(i)) {
            prime[j++] = i;
        }
    }

    numOfPrimes = j - 1;

    for (i = 2; i < MAX_SIZE; i++) {
        for (j = 1, count = 0; j <= numOfPrimes; j++) {
            for (k = j, sum = 0; k <= numOfPrimes && sum < i; k++) {
                sum += prime[k];
            }

            if (sum == i) {
                count++;
            }
        }
        ans[i] = count;
    }
}

int main(void) {

    int input;

    calculate();

    while(scanf("%d", &input), input != 0) {
        printf ("%d\n", ans[input]);
    }

    return 0;
}
