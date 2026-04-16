// BOJ 2482 색상환 | DP, 조합론 | 2019-02-24 22:16:40
#include <stdio.h>

int D[2000][2000];

int main()
{
    int N, K, i, j;

    scanf("%d %d", &N, &K);

    for(i = 1; i <= N; i++) {
        D[0][i] = 1;
        D[1][i] = i;
    }

    for (i = 2; i <= K; i++) {
        for (j = 1; j <= N; j++) {
            if (j == N) D[i][j] = (D[i-1][j-3]+D[i][j-1])%1000000003;
            else D[i][j] = (D[i-1][j-2]+D[i][j-1])%1000000003;
        }
    }

    printf("%d", D[K][N]);

    return 0;
}
