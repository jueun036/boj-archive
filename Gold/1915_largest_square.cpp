// BOJ 1915 가장 큰 정사각형 | DP | 2019-01-31 00:20:33
#include <stdio.h>

int a[1001][1001], D[1001][1001];

int mn(int a, int b, int c)
{
    int x;

    if(a < b) x = a;
    else x = b;

    if (x > c) x = c;

    return x;
}
int main()
{
    int n, m, i, j, mx = 0;
    char ch[1001];

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        scanf("%s", &ch);
        for (j = 0; j < m; j++) {
            a[i][j+1] = ch[j]-48;
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                if (a[i-1][j] == 1 && a[i-1][j-1] == 1 && a[i][j-1] == 1) {
                    int minn = mn (D[i-1][j], D[i-1][j-1], D[i][j-1]);
                    D[i][j] = minn+1;
                }
                else D[i][j] = 1;
            }
            else {
                D[i][j] = 0;
            }
            if (mx < D[i][j]) mx = D[i][j];
        }
    }

    printf("%d", mx*mx);

    return 0;
}

