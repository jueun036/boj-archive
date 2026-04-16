// BOJ 2178 미로 탐색 | 그래프 탐색, BFS | 2020-09-19 09:50:00
#include <stdio.h>

char st[200];
int a[200][200];
int o[80100][5];
int xx[5] = { 0, -1, 0, 1, 0 };
int yy[5] = { 0, 0, 1, 0, -1 };
int cnt[200][200];

int main()
{
    int N, M, i, j, s, e, x, y;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i++) {
        scanf("%s", st);
        for (j = 0; j < M; j++) {
            a[i][j + 1] = st[j] - '0';
        }
    }

    o[1][0] = 1; o[1][1] = 1; s = 0; e = 1; cnt[1][1] = 1;
    while (s < e) {
        x = o[++s][0]; y = o[s][1];
        for (i = 1; i <= 4; i++) {
            if (a[x+xx[i]][y+yy[i]] == 1) {
                if (cnt[x + xx[i]][y + yy[i]] == 0) {
                    cnt[x + xx[i]][y + yy[i]] = cnt[x][y] + 1;
                    o[++e][0] = x + xx[i]; o[e][1] = y + yy[i];
                }
            }
        }
    }

    printf("%d", cnt[N][M]);
    return 0;
}