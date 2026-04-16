// BOJ 2583 영역 구하기 | 그래프 탐색, BFS, DFS | 2018-11-08 23:26:47
#include <stdio.h>

int s[101][101], o[101], m, n, nu = 1;

void one(int x1, int y1, int x2, int y2)
{
    int i, j;

    for (i = x1; i < x2; i++) {
        for (j = y1; j < y2; j++) {
            s[i][j] = 1;
        }
    }
}
void number(int x, int y, int nu)
{
    if (x < 0 || y < 0 || x > n-1 || y > m-1) return;
    if (s[x][y] != 0) return;
    else s[x][y] = nu;
    number(x-1, y, nu);
    number(x+1, y, nu);
    number(x, y-1, nu);
    number(x, y+1, nu);
}
void change()
{
    int i, j;

    for (i = 2 ; i < nu; i++) {
        for (j = i+1; j <= nu; j++) {
            if (o[i] > o[j]) {
                int p = o[i];
                o[i] = o[j];
                o[j] = p;
            }
        }
    }
}

int main()
{
    int k, i, j, x1, y1, x2, y2;

    scanf("%d %d %d", &m, &n, &k);

    for (i = 1; i <= k; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        one(x1, y1, x2, y2);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == 0) {
                nu++;
                number(i, j, nu);
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            o[s[i][j]]++;
        }
    }

    change();

    printf("%d\n", nu-1);
    for (i = 2; i <= nu; i++) {
        printf("%d ", o[i]);
    }
    return 0;
}