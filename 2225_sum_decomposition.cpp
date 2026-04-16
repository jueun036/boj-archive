// BOJ 2225 합분해 | DP | 2019-01-23 22:26:11
#include <stdio.h>

int D[201][201];

int main()
{
    int N, K, i, j, k;

    scanf("%d %d", &N, &K);

    for (i = 0; i <= N; i++) {
        D[1][i] = 1;
    }

    for (i = 1; i <= K; i++) {
        for (j = 0; j <= N; j++) {
            for (k = 0; k <= j; k++) {
                D[i][j] += D[i-1][k];
                D[i][j] %= 1000000000;
            }
        }
    }

    printf("%d", D[K][N]);

    return 0;
}
