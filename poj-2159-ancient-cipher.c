/*
 * =====================================================================================
 *
 *       Filename:  poj-2159-ancient-cipher.c
 *
 *    Description:  POJ 2159
 *
 *        Version:  1.0
 *        Created:  2016年03月21日 16时30分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int main(){
    char str1[105], str2[105];
    int i, num1[26], num2[26];
    while(scanf("%s %s", str1, str2) != EOF){
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        for(i = 0; i < strlen(str1); i ++){
            num1[str1[i]-'A'] ++;
            num2[str2[i]-'A'] ++;
        }
        sort(num1, num1 + 26);
        sort(num2, num2 + 26);
        bool flag = true;
        for(i = 0; i < 26 && flag; i ++)
            if(num1[i] != num2[i])
                flag = false;
        if(flag)  printf("YES\n");
        else  printf("NO\n");
    }
    return 0;
}
