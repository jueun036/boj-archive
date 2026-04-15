// BOJ 1005 ACM Craft | DP | 2020-09-19 12:51:32
#include <stdio.h>
#include <vector>

using namespace std;
vector<int> s[1100];
int time[1100];
int con[1100];
int zero[1100];
int ant[1100];

int main()
{
    int T, N, K, W, i, j, k, zs, ze, ans, no, a, b;

    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d %d", &N, &K);
        for (j = 1; j <= N; j++) {
            scanf("%d", &time[j]);
        }
        for (j = 1; j <= K; j++) {
            scanf("%d %d", &a, &b);
            con[b]++;
            s[a].push_back(b);
        }
        scanf("%d", &W);
        ze = 0;
        for (j = 1; j <= N; j++) {
            if (con[j] == 0) {
                zero[++ze] = j;
                ant[j] = time[j];
            }
        }
        zs = 0;
        while (zs < ze) {
            no = zero[++zs];
            for (j = 0; j < s[no].size(); j++) {
                b = s[no][j];
                con[b]--;
                if (ant[b] < ant[no]+time[b]) ant[b] = ant[no] + time[b];
                if (con[b] <= 0) zero[++ze] = b;
            }
        }

        printf("%d\n", ant[W]);
        for (j = 1; j <= N; j++) {
            ant[j] = con[j] = 0;
            s[j].clear();
        }
    }

    return 0;
}