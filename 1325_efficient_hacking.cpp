// BOJ 1325 효율적인 해킹 | 그래프, BFS, DFS | 2018-11-26 23:11:25
#include <stdio.h>
#include <vector>

using namespace std;
vector<int>edge[10001];

int ch[10001], cnt[10001];

void computer(int c)
{
    int i, x;

    ch[c] = 1;

    for (i = 0; i < edge[c].size(); i++) {
        x = edge[c][i];
        if (ch[x] == 1) continue;
        computer(x);
    }
}
int main()
{
    int n, m, i, j;
    int c1, c2, max = 0;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &c1, &c2);
        edge[c2].push_back(c1);
    }

    for (i = 1; i <= n; i++) {
        computer(i);
        for (j = 1; j <= n; j++) {
            cnt[i] += ch[j];
            ch[j] = 0;
        }
        if (cnt[i] > max) max = cnt[i];
    }

    for (i = 1; i <= n; i++) {
        if (max == cnt[i]) printf("%d ", i);
    }

    return 0;
}
