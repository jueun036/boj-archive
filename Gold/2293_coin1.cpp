// BOJ 2293 동전 1 | DP | 2019-01-26 10:24:26
#include <stdio.h>

int a[101];
long long F[10001], D[10001];

int main()
{
    int n, k, i, j;

    scanf("%d %d", &n, &k);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    F[0] = 1;

    for (i = 1; i <= n; i++) {
        for (j = 0; j <= k; j++) {
            D[j] += F[j];
            if (j >= a[i]) D[j] += D[j-a[i]];
        }
        for (j = 0; j <= k; j++) {
            F[j] = D[j];
            D[j] = 0;
        }
    }

    printf("%lld", F[k]);

    return 0;
}
