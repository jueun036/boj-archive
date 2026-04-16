// BOJ 2156 포도주 시식 | DP | 2018-09-22 11:18:19
#include <stdio.h>

int s[10001], D[10001][3];

int main()
{
    int n, i, j, k, max1, max2 = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }

    for (i = 1; i <= n; i++) { max1 = 0;
        for (k = 0; k <= 2; k++) if (max1 < D[i-2][k]) max1 = D[i-2][k];
        if (max1 < D[i-1][0]) max1 = D[i-1][0];
        for (j = 0; j <= 2; j++) {
            if (j == 2) {
                D[i][j] = D[i-1][1]+s[i];
            }
            else {
                if (j == 0) D[i][j] = max1;
                else D[i][j] = max1+s[i];
            }
            if (max2 < D[i][j]) max2 = D[i][j];
        }
    }
    printf("%d", max2);

    return 0;
}
