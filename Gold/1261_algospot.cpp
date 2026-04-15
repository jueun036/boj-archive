// BOJ 1261 알고스팟 | 그래프, BFS, 다익스트라 | 2019-12-21 10:16:35
#include <stdio.h>

int a[200][200];
int s[10100];
int e[10100];
int wall[300][10100][5];
int mp[300][300];
int xx[5] = {0, -1, 0, 1, 0};
int yy[5] = {0, 0, 1, 0, -1};

int main()
{
    int N, M, i, j, f, x;
    char st[110];

    scanf("%d %d", &M, &N);

    for (i = 1; i <= N; i++) {
        scanf("%s", st);
        for (j = 0; j < M; j++) {
            a[i][j+1] = st[j]-'0';
            mp[i][j+1] = -1;
        }
    }

    wall[0][++e[0]][0] = 1;
    wall[0][e[0]][1] = 1;
    mp[1][1] = 0;

    for (i = 1; i <= 10000; i++) s[i] = 1;

    while(1) {
        f = 0;
        for (i = 0; i <= 200; i++) if (s[i] <= e[i]) {
            x = i;
            f = 1;
            break;
        }
        if (f == 0) break;
        int nowx = wall[x][s[x]][0];
        int nowy = wall[x][s[x]][1];
        for (i = 1; i <= 4; i++) {
            int xxx = nowx + xx[i];
            int yyy = nowy + yy[i];
            if (mp[xxx][yyy] != -1) continue;
            if (xxx <= 0 || yyy <= 0 || xxx > N || yyy > M) continue;
            if (a[xxx][yyy] == 1) {
                mp[xxx][yyy] = mp[nowx][nowy]+1;
                wall[x+1][++e[x+1]][0] = xxx;
                wall[x+1][e[x+1]][1] = yyy;
            }
            else {
                mp[xxx][yyy] = mp[nowx][nowy];
                wall[x][++e[x]][0] = xxx;
                wall[x][e[x]][1] = yyy;
            }
        }
        s[x]++;
    }

    printf("%d", mp[N][M]);

    return 0;
}
