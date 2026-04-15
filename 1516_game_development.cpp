// BOJ 1516 게임 개발 | DP, 위상정렬 | 2020-09-06 20:43:55
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> edge[600];

int time[600];
int con[600];
int zero[600];
int ans[600];

int main()
{
    int N, i, j, k, s, e, a;

    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        scanf("%d", &time[i]);
        for (j = 1; ; j++) {
            scanf("%d", &a);
            if (a == -1) break;
            edge[a].push_back(i);
            con[i]++;
        }
    }

    s = e = 0;
    for (i = 1; i <= N; i++) {
        if (con[i] == 0) {
            zero[++e] = i;
            ans[i] = time[i];
        }
    }

    while (s <= e) {
        s++;
        for (i = 0; i < edge[zero[s]].size(); i++) {
            int o = edge[zero[s]][i];
            if (ans[o] < ans[zero[s]]) ans[o] = ans[zero[s]];
            con[o]--;
            if (con[o] <= 0) {
                zero[++e] = o;
                ans[o] += time[o];
            }
        }
    }

    for (i = 1; i <= N; i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}