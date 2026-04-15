// BOJ 1058 친구 | 그래프, BFS | 2020-10-03 18:16:34
#include <stdio.h>
#include <string.h>

char st[100];
int a[100][100];
int check[100][100];

int main()
{
    int N, i, j, k, len, ans, cnt;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%s", st);
        len = strlen(st);
        for (j = 0; j < len; j++) {
            if (st[j] == 'Y') a[i][j + 1] = 1;
        }
    }

    ans = 0;
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (a[i][j] == 1) {
                check[i][j] = 1;
                for (k = 1; k <= N; k++) if (k != i) {
                    if (a[j][k] == 1) check[i][k] = 1;
                }
            }
        }
        cnt = 0;
        for (j = 1; j <= N; j++) if (check[i][j] == 1) cnt++;
        if (cnt > ans) ans = cnt;
    }

    printf("%d", ans);

    return 0;
}