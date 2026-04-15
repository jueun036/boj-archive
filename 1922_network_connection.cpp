// BOJ 1922 네트워크 연결 | 최소 스패닝 트리 | 2019-01-27 21:13:28
#include <stdio.h>
#include <vector>

using namespace std;
vector<int>con[100001];

int edge[100001][4], im[100001][4], check[1001];

void change(int &a, int &b)
{
    int o = a; a = b; b = o;
}
void sort(int s, int e)
{
    if (s == e) return;
    int m, c1, c2, i;
    m = (s+e)/2; c1 = s; c2 = m+1;
    sort(s, m);
    sort(m+1, e);

    for (i = s; i <= e; i++) {
        if (c1 <= m && c2 > e || c1 <= m && c2 <= e && edge[c1][3] < edge[c2][3]) {
            im[i][1] = edge[c1][1];
            im[i][2] = edge[c1][2];
            im[i][3] = edge[c1][3];
            c1++;
        }
        else {
            im[i][1] = edge[c2][1];
            im[i][2] = edge[c2][2];
            im[i][3] = edge[c2][3];
            c2++;
        }
    }

    for (i = s; i <= e; i++) {
        edge[i][1] = im[i][1];
        edge[i][2] = im[i][2];
        edge[i][3] = im[i][3];
    }
}
void dfs(int s)
{
    int i;

    check[s] = 1;
    for (i = 0; i < con[s].size(); i++) {
        int x = con[s][i];
        if (check[x] == 0) {
            dfs(x);
        }
    }
}
int main()
{
    int N, M, i, j;
    long long sum = 0;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= M; i++) {
        scanf ("%d %d %d", &edge[i][1], &edge[i][2], &edge[i][3]);
    }
    sort(1, M);

    for (i = 1; i <= M; i++) {
        dfs(edge[i][1]);
        if (check[edge[i][2]] == 0) {
            con[edge[i][1]].push_back(edge[i][2]);
            con[edge[i][2]].push_back(edge[i][1]);
            sum += edge[i][3];
        }
        for (j = 1; j <= N; j++) check[j] = 0;
    }

    printf("%lld", sum);

    return 0;
}
