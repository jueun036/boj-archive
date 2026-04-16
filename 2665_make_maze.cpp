// BOJ 2665 미로만들기 | 그래프 탐색, BFS, 다익스트라 | 2019-12-31 22:17:36
#include <stdio.h>

int room[200][200];
int s[10100];
int e[10100];
int q[300][10100][5];
int cnt[300][300];
int xx[5] = {0, -1, 0, 1, 0};
int yy[5] = {0, 0, 1, 0, -1};

int main()
{
    int N, i, j, f, ncnt, nowx, nowy;
    char st[110];

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%s", st);
        for (j = 0; j < N; j++) {
            room[i][j+1] = st[j]-'0';
            cnt[i][j+1] = -1;
        }
    }

    q[0][++e[0]][0] = 1;
    q[0][e[0]][1] = 1;
    cnt[1][1] = 0;

    for (i = 1; i <= 10000; i++) s[i] = 1;

    while(1) {
        f = 0;
        for (i = 0; i <= 200; i++) if (s[i] <= e[i]) {
            ncnt = i;
            f = 1;
            break;
        }
        if (f == 0) break;
        nowx = q[ncnt][s[ncnt]][0];
        nowy = q[ncnt][s[ncnt]++][1];
        for (i = 1; i <= 4; i++) {
            int xxx = nowx + xx[i];
            int yyy = nowy + yy[i];
            if (cnt[xxx][yyy] != -1) continue;
            if (xxx <= 0 || yyy <= 0 || xxx > N || yyy > N) continue;
            if (room[xxx][yyy] == 0) {
                cnt[xxx][yyy] = ncnt+1;
                q[ncnt+1][++e[ncnt+1]][0] = xxx;
                q[ncnt+1][e[ncnt+1]][1] = yyy;
            }
            else {
                cnt[xxx][yyy] = ncnt;
                q[ncnt][++e[ncnt]][0] = xxx;
                q[ncnt][e[ncnt]][1] = yyy;
            }
        }
    }

    printf("%d", cnt[N][N]);

    return 0;
}
