// BOJ 1068 트리 | 트리, DFS | 2018-11-03 10:56:44
#include <stdio.h>
#include <vector>

using namespace std;

int T[51], n, m, k, c;

vector<int>edge[51];

int tree(int x)
{
    int i, v, cnt = 0;

    if (x == m) return 0;
    for (i = 0; i < edge[x].size(); i++) {
        v = tree(edge[x][i]);
        cnt += v;
    }
    if (cnt == 0) c++;
    return 1;
}

int main()
{
    int i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &T[i]);
        if (T[i] == -1) k = i;
        edge[T[i]].push_back(i);
    }

    scanf("%d", &m);

    tree(k);

    printf("%d", c);

    return 0;
}
