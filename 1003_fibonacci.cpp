// BOJ 1003 피보나치 함수 | DP | 2019-07-17 17:36:13
#include <stdio.h>

int D[50][5], a[2000];

int main()
{
    int t, i, mx = 0;

    scanf("%d", &t);

    D[0][1] = 1; D[0][2] = 0;
    D[1][1] = 0; D[1][2] = 1;

    for (i = 1; i <= t; i++) {
        scanf("%d", &a[i]);
        if (a[i] > mx) mx = a[i];
    }

    for (i = 2; i <= mx; i++) {
        D[i][1] = D[i-1][1]+D[i-2][1];
        D[i][2] = D[i-1][2]+D[i-2][2];
    }

    for (i = 1; i <= t; i++) {
        printf("%d %d\n", D[a[i]][1], D[a[i]][2]);
    }
    return 0;
}