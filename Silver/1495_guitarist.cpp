// BOJ 1495 기타리스트 | DP | 2019-01-31 23:46:25
#include <stdio.h>

int a[101], D[101][1001];

int main()
{
    int N, S, M, i, j;

    scanf("%d %d %d", &N, &S, &M);

    for (i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    D[0][S] = 1;

    for (i = 1; i <= N; i++) {
        for (j = 0; j <= M; j++) {
            if (D[i-1][j] == 1) {
                if (j-a[i] >= 0) D[i][j-a[i]] = 1;
                if (j+a[i] <= M) D[i][j+a[i]] = 1;
            }
        }
    }

    int ans = -1;
    for (i = 0; i <= M; i++) {
        if (D[N][i] == 1) ans = i;
    }

    printf("%d", ans);

    return 0;
}
