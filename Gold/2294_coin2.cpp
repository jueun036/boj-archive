// BOJ 2294 동전 2 | DP | 2019-03-04 22:35:58
#include <stdio.h>

int a[200], D[20000];

int main()
{
    int N, K, i, j;

    scanf("%d %d", &N, &K);

    for (i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= K; i++) {
        for (j = 1; j <= N; j++) {
            if (i-a[j] >= 0) {
                if (i-a[j] == 0 || D[i-a[j]] != 0) {
                    if (D[i] == 0 || D[i-a[j]]+1 < D[i]) D[i] = D[i-a[j]]+1;
                }
            }
        }
    }

    if (D[K] == 0) printf("-1");
    else printf("%d", D[K]);

    return 0;
}
