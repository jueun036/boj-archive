// BOJ 1240 노드사이의 거리 | 그래프, DFS, BFS | 2018-11-17 09:54:30
#include <stdio.h>
#include <vector>

using namespace std;

int ans, v1, ch[1001], flag;

struct xy {
    int x, y;
};

vector<xy>edge[1001];

void f(int v, int sum)
{
    int i;

    ch[v] = 1;

    if (v1 == v) {
        flag = 1;
        ans = sum;
        return;
    }

    for (i = 0; i < edge[v].size(); i++) {
        if (flag == 1) return;
        if(ch[edge[v][i].x] == 1) continue;
        f(edge[v][i].x, sum+edge[v][i].y);
    }
}
int main()
{
    int n, m, v2, x, i, j;

    scanf("%d %d", &n, &m);

    for (i = 1; i < n; i++) {
        scanf("%d %d %d", &v1, &v2, &x);
        edge[v1].push_back({v2, x});
        edge[v2].push_back({v1, x});
    }

    for (i = 1; i <= m; i++) {
        flag = 0;
        scanf("%d %d", &v1, &v2);
        f(v2, 0);
        printf("%d\n", ans);
        for (j = 1; j <= n; j++) {
            ch[j] = 0;
        }
    }

    return 0;
}
