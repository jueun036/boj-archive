// BOJ 1912 연속합 | DP | 2019-03-06 21:57:29
#include <stdio.h>

int a[200000], D[200000];

int main()
{
    int n, i;
    long long mx = -999999999999;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= n; i++) {
        D[i] = a[i];
        if (D[i-1]+a[i] > D[i]) {
            D[i] = D[i-1]+a[i];
        }
        if (D[i] > mx) mx = D[i];
    }

    printf("%lld", mx);

    return 0;
}
