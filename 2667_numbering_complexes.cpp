// BOJ 2667 단지번호붙이기 | 그래프 탐색, DFS, BFS | 2018-11-01 23:43:45
#include <stdio.h>

int A[26][26], x, o[1000], a = 1, n;

void number(int x, int y, int d)
{
    if (x < 1 || y < 1 || x > n || y > n) return;
    if (A[x][y] != 1) return;
    else {
        A[x][y] = d;
    }

    number(x+1, y, d);
    number(x-1, y, d);
    number(x, y+1, d);
    number(x, y-1, d);
}
void change()
{
    int i, j;

    for (i = 2; i < a; i++) {
        for (j = i+1; j <= a; j++) {
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
    int i, j;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%1d", &A[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (A[i][j] == 1) {
                a++;
                number(i, j, a);
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            o[A[i][j]]++;
        }
    }

    change();
    printf("%d\n", a-1);
    for (i = 2; i <= a; i++) {
        printf("%d\n", o[i]);
    }
    return 0;
}
