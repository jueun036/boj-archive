// BOJ 2056 작업 | DP, 위상 정렬 | 2020-09-07 20:52:00
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> edge[10100];

int time[10100];
int con[10100];
int zero[10100];
int ans[10100];

int main()
{
    int N, M, a, i, j, k, s, e, mx;

    scanf("%d", &N);

    s = e = 0;
    for (i = 1; i <= N; i++) {
        scanf("%d %d", &time[i], &M);
        for (j = 1; j <= M; j++) {
            scanf("%d", &a);
            edge[a].push_back(i);
        }
        con[i] = M;
        if (con[i] == 0) {
            zero[++e] = i;
            ans[i] = time[i];
        }
    }

    while (s <= e) {
        ++s;
        for (i = 0; i < edge[zero[s]].size(); i++) {
            int o = edge[zero[s]][i];
            if (ans[o] < ans[zero[s]]) ans[o] = ans[zero[s]];
            con[o]--;
            if (con[o] == 0) {
                ans[o] += time[o];
                zero[++e] = o;
            }
        }
    }

    mx = 0;
    for (i = 1; i <= N; i++) {
        if (mx < ans[i]) mx = ans[i];
    }

    printf("%d", mx);

    return 0;
}