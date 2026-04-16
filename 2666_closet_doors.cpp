// BOJ 2666 벽장문의 이동 | DP | 2019-02-10 20:13:17
#include <stdio.h>

int a[30], D[30][30][30], open[1];

int mins(int a, int b)
{
    if (a > b) return a-b;
    return b-a;
}
int main()
{
    int n, i, j, k, op1, op2, m;

    scanf("%d %d %d %d", &n, &op1, &op2, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i <= m; i++) {
        for (j = 1; j <= n; j++) for (k = 1; k <= n; k++) D[i][j][k] = -1;
    }

    D[0][op1][op2] = 0;
    D[0][op2][op1] = 0;

    for (i = 1; i <= m; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= n; k++) {
                if (D[i-1][j][k] != -1) {
                    if (D[i][a[i]][k] == -1 || D[i][a[i]][k] > D[i-1][j][k]+mins(a[i], j)) {
                        D[i][a[i]][k] = D[i-1][j][k]+mins(a[i], j);
                        D[i][k][a[i]] = D[i-1][j][k]+mins(a[i], j);
                    }
                    if (D[i][j][a[i]] == -1 || D[i][j][a[i]] > D[i-1][j][k]+mins(a[i], k)) {
                        D[i][j][a[i]] = D[i-1][j][k]+mins(a[i], k);
                        D[i][a[i]][j] = D[i-1][j][k]+mins(a[i], k);
                    }
                }
            }
        }
    }

    int mn = 99999;

    for (i = 1; i <= n; i++) {
        if (mn > D[m][a[m]][i] && D[m][a[m]][i] != -1) mn = D[m][a[m]][i];
        if (mn > D[m][i][a[m]] && D[m][i][a[m]] != -1) mn = D[m][i][a[m]];
    }

    printf("%d", mn);

    return 0;
}
