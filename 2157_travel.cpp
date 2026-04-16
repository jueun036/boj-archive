// BOJ 2157 여행 | DP | 2019-02-09 11:44:28
#include <stdio.h>

int way[400][400], D[400][400];

int main()
{
    int N, M, K, i, j, k, a, b, c, mx1, mx2;

    scanf("%d %d %d", &N, &M, &K);

    for (i = 1; i <= K; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (way[a][b] < c && b > a) way[a][b] = c;
    }

    mx2 = 0;

    for (i = 1; i <= M-1; i++) for (j = 1; j <= N; j++) D[i][j] = -1;
    for (i = 1; i <= N; i++) {
        if (way[1][i] >= 1) {
            D[1][i] = way[1][i];
            if (i == N && mx2 < D[1][i]) mx2 = D[1][i];
        }
    }

    for (i = 2; i <= M-1; i++) {
        for (j = i; j <= N; j++) {
            mx1 = 0;
            for (k = 1; k < j; k++) {
                if (way[k][j] >= 1 && D[i-1][k] != -1) {
                    if (mx1 < D[i-1][k]+way[k][j]) mx1 = D[i-1][k]+way[k][j];
                }
            }
            if (mx1 == 0) D[i][j] = -1;
            else D[i][j] = mx1;
            if (j == N && mx2 < D[i][j]) mx2 = D[i][j];
        }
    }

    printf("%d", mx2);

    return 0;
}
