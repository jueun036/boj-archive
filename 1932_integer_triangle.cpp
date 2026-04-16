// BOJ 1932 정수 삼각형 | DP | 2019-01-21 14:42:37
#include <stdio.h>

int T[501][501], D[501][501];

int main()
{
    int n, i, j, mx;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            scanf("%d", &T[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            if (j == 1) D[i][j] = D[i-1][j]+T[i][j];
            else if (i == j) D[i][j] = D[i-1][j-1]+T[i][j];
            else {
                if (D[i-1][j-1] > D[i-1][j]) D[i][j] = D[i-1][j-1]+T[i][j];
                else D[i][j] = D[i-1][j]+T[i][j];
            }
        }
    }

    mx = -1;
    for (i = 1; i <= n; i++) {
        if (mx < D[n][i]) mx = D[n][i];
    }

    printf("%d", mx);

    return 0;
}
