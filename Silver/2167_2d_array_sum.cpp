// BOJ 2167 2차원 배열의 합 | 누적 합 | 2018-09-29 10:05:55
#include <stdio.h>

int a[301][301], D[301][301];

int main()
{
    int n, m, k, i, j;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            D[i][j] = D[i][j-1]+a[i][j];
        }
    }

    scanf("%d", &k);

    int x1, x2, y1, y2, sum;

    for (i = 1; i <= k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sum = 0;
        for (j = x1; j <= x2; j++) {
            sum += D[j][y2]-D[j][y1-1];
        }
        printf("%d\n", sum);
    }

    return 0;
}
