// BOJ 2579 계단 오르기 | DP | 2018-08-18 10:05:46
#include <stdio.h>

int s[301], d[301][5];

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 2; j++) {
            if (j == 1) {
                if (d[i-2][1] > d[i-2][2]) d[i][j] = d[i-2][1]+s[i];
                else d[i][j] = d[i-2][2]+s[i];
            }
            else {
                d[i][j] = d[i-1][1]+s[i];
            }
        }
    }

    if (d[n][1] > d[n][2]) {
        printf("%d", d[n][1]);
    }
    else {
        printf("%d", d[n][2]);
    }

    return 0;
}
