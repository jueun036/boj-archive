// BOJ 2606 바이러스 | 그래프 탐색, DFS, BFS | 2018-08-03 09:14:05
#include <stdio.h>

int o[12101], u[12101], ch[101], q[101];

int main()
{
    int n, m, i, s, e, c = 0;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &o[i], &u[i]);
    }

    q[1] = 1;
    ch[1] = 1;
    s = 1;
    e = 2;

    while(s < e) {
        for (i = 1; i <= m; i++) {
            if (o[i] == q[s] && ch[u[i]] == 0) {
                q[e] = u[i];
                ch[u[i]] = 1;
                e++;
            }
            if (u[i] == q[s] && ch[o[i]] == 0) {
                q[e] = o[i];
                ch[o[i]] = 1;
                e++;
            }
        }
        s++;
    }

    for (i = 2; i <= n; i++) {
        if (ch[i] == 1) c++;
    }

    printf("%d", c);

    return 0;
}
