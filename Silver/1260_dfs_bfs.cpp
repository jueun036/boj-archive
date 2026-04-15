// BOJ 1260 DFS와 BFS | 그래프, DFS, BFS | 2018-08-01 12:02:16
#include <stdio.h>

int v, x[1001][1001], ch[1001], q[1001], ch2[1001], n, m, s = 1, e = 1;

void f(int o)
{
    int i;
    ch[o] = 1;
    printf("%d ",o);
    for (i = 1; i <= n; i++) {
        if(x[o][i] == 1 && ch[i] == 0) {
            f(i);
        }
    }
}

void bfs(int v)
{
    int i;
    q[e++]=v;
    ch2[v]=1;
    while(s<e) {
        printf("%d ",q[s]);
        for (i = 1; i <= n; i++) {
            if (x[q[s]][i] == 1 && ch2[i]==0) {
                q[e] = i;
                e++;
                ch2[i]=1;
            }
        }
        s++;
    }
}
int main()
{
    int i, a, b;

    scanf("%d %d %d", &n, &m, &v);

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        x[a][b] = 1;
        x[b][a] = 1;
    }

    ch[v] = 1;
    f(v);
    printf("\n");
    bfs(v);

    return 0;
}
