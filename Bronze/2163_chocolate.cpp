// BOJ 2163 초콜릿 자르기 | 수학 | 2018-09-30 23:48:20
#include <stdio.h>

int D[301][301];

int main()
{
    int n, m, i, j, k, min;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= 300; i++) {
        D[1][i] = D[i][1] = i-1;
    }

    for (i = 2; i <= n; i++) {
        for (j = 2; j <= m; j++) {
            D[i][j] = D[i][j-1]+D[i][1]+1;
        }
    }

    printf("%d", D[n][m]);

    return 0;
}
