// BOJ 2636 치즈 | 그래프 탐색, BFS, 시뮬레이션 | 2019-11-15 22:37:30
#include <stdio.h>

int s[200][200], ch, c, n, m;

void two(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m) return;
    if (s[x][y] > 0) return;
    s[x][y] = 2;

    two(x-1, y);
    two(x+1, y);
    two(x, y-1);
    two(x, y+1);
}

void cheese()
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i][j] == 1) {
                if (s[i-1][j] == 2 || s[i+1][j] == 2 || s[i][j-1] == 2 || s[i][j+1] == 2) {
                    s[i][j] = 0;
                    c++;
                }
            }
        }
    }
}
void zero()
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i][j] == 2) s[i][j] = 0;
        }
    }
}
int main()
{
    int i, j, x = 0, a;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            scanf("%d", &s[i][j]);
            if (s[i][j] == 1) ch++;
        }
    }

    while(ch- c > 0) {
        a = ch-c;
        two(1, 1);
        cheese();
        zero();
        x++;
    }
    printf("%d\n%d", x, a);
    return 0;
}
