// BOJ 1890 점프 | DP | 2019-01-12 09:56:50
#include <stdio.h>

int A[101][101], check[101][101];
long long D[101][101];

int main()
{
    int n, i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    check[1][1] = 1;
    D[1][1] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (check[i][j] == 1 && A[i][j] != 0) {
                if (i+A[i][j] <= n) {
                    check[i+A[i][j]][j] = 1;
                    D[i+A[i][j]][j] += D[i][j];
                }
                if (j+A[i][j] <= n) {
                    check[i][j+A[i][j]] = 1;
                    D[i][j+A[i][j]] += D[i][j];
                }
            }
        }
    }

    printf("%lld", D[n][n]);

    return 0;
}
