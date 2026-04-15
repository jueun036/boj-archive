// BOJ 1149 RGB 거리 | DP | 2018-09-29 09:36:03
#include <stdio.h>

int a[1001][4], D[1001][4];

int main()
{
    int n, i, j, k, min;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d %d", &a[i][1], &a[i][2], &a[i][3]);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            min = 99999999;
            for (k = 1; k <= 3; k++) if (k != j) {
                if (min > D[i-1][k]) {
                    min = D[i-1][k];
                }
            }
            D[i][j] = min+a[i][j];
        }
    }
    min = 999999999;
    for (i = 1; i <= 3; i++) {
        if (D[n][i] < min) min = D[n][i];
    }

    printf("%d", min);

    return 0;
}
