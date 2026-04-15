// BOJ 1012 유기농 배추 | DFS/BFS | 2018-11-02 22:29:41
#include <stdio.h>

int n, m, F[51][51];

void number(int x, int y)
{
    if (x < 0 || x > n || y < 0 || y > m) return;
    if (F[x][y] != 1) return;
    F[x][y] = 0;

    number(x-1, y);
    number(x, y+1);
    number(x+1, y);
    number(x, y-1);
}
int main()
{
    int T, o, x, y, c;
    int i, j, k;

    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d %d %d", &n, &m, &o);
        for (j = 1; j <= o; j++) {
            scanf("%d %d", &x, &y);
            F[x][y] = 1;
        }
        c = 0;
        for (j = 0; j <= n; j++) {
            for (k = 0; k <= m; k++) {
                if (F[j][k] == 1) {
                    c++;
                    number(j, k);
                }
            }
        }

        printf("%d\n", c);
    }

    return 0;
}