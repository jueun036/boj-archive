// BOJ 2653 안정된 집단 | 구현, 그리디 | 2018-12-01 00:12:16
#include <stdio.h>
#include <vector>

using namespace std;
vector<int>edge[101];

int g[101][101], ch[101];

int main()
{
    int n, i, j, k, c = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        if (ch[i] != 0) continue;
        for (j = 1; j <= n; j++) {
            if (g[i][j] == 0) {
                edge[c].push_back(j);
                ch[j] = i;
            }
        }
        for (j = 0; j < edge[c].size(); j++) {
            int x = edge[c][j];
            for (k = 1; k <= n; k++) {
                if (ch[k] == i && g[x][k] == 1) {
                    printf("0");
                    return 0;
                }
                if (ch[k] != i && g[x][k] == 0) {
                    printf("0");
                    return 0;
                }
            }
        }
        if (edge[c].size() == 1) {
            printf("0");
            return 0;
        }
        c++;
    }

    printf("%d\n", c);

    for (i = 0; i < c; i++) {
        for (j = 0; j < edge[i].size(); j++) {
            printf("%d ", edge[i][j]);
        }
        printf("\n");
    }

    return 0;
}
