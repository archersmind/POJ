#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str1[10];
char str2[10];
char str3[10];

int  markers[128];
int  visited[10];
int  strint[128];

int ans;

int getnum(char *str) {
    int i;
    int num = 0;

    //printf ("num = %d getnum for %s len = %d\n", num, str, strlen(str));
    for (i = 0; i < strlen(str); i++) {
        num *= 10;
        num += strint[str[i]];
    }

    //printf ("str (%s) to num(%d)\n", str, num);
    return num;
}

void DFS(int letter) {
    int i;
    int num1, num2, num3;

    if (letter == ((int)'E' + 1)) {
        // rule out leading zero cases
        if ((strint[str1[0]] == 0) && (strlen(str1) > 1)) return;
        if ((strint[str2[0]] == 0) && (strlen(str2) > 1)) return;
        if ((strint[str3[0]] == 0) && (strlen(str3) > 1)) return;

        num1 = getnum(str1);
        num2 = getnum(str2);
        num3 = getnum(str3);
        
        if ((num1 + num2) == num3) ans++;
        //printf ("%d + %d = %d\n", num1, num2, num3);
        if ((num1 - num2) == num3) ans++;
        //printf ("%d - %d = %d\n", num1, num2, num3);
        if ((num1 * num2) == num3) ans++;
        //printf ("%d * %d = %d\n", num1, num2, num3);
        if ((num2 != 0) && (num2 * num3) == num1) ans++;
        //printf ("%d / %d = %d\n", num1, num2, num3);
        
        return;
    }

    if (!markers[letter]) {
        DFS(letter + 1);
        return;
    }
    
    for (i = 0; i <= 9; i++) {
    
        if (visited[i])
            continue;
        visited[i] = 1;
        strint[letter] = i;
        DFS(letter + 1);
        visited[i] = 0;  // backtrack
    }
}


int main(void) {

    int cases;
    int i;

    scanf("%d", &cases);
    while(cases--) {
        ans = 0;
        memset(str1, 0, sizeof(str1));
        memset(str2, 0, sizeof(str2));
        memset(str3, 0, sizeof(str3));

        memset(markers, 0, sizeof(markers));
        memset(visited, 0, sizeof(visited));

        scanf("%s %s %s", str1, str2, str3);
        //printf ("strlen(str1) = %d strlen(str2) = %d strlen(str3) = %d\n",
        //        strlen(str1), strlen(str2), strlen(str3));

        for (i = 0; i < strlen(str1); i++) {
            markers[str1[i]] = 1;
        }

        for (i = 0; i < strlen(str2); i++) {
            markers[str2[i]] = 1;
        }

        for (i = 0; i < strlen(str3); i++) {
            markers[str3[i]] = 1;
        }

        DFS((int)'A');
        printf ("%d\n", ans);
    }

    return 0;
}
