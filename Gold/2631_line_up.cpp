// BOJ 2631 줄세우기 | DP, LIS | 2019-02-01 22:04:12
#include <stdio.h>

int a[201], D[201];

int main()
{
    int n, i, j, ans = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    D[1] = 1;
    for (i = 2; i <= n; i++) {
        int mx = 0;
        for (j = 1; j < i; j++) {
            if (a[i] > a[j]) {
                if (mx < D[j]) mx = D[j];
            }
        }
        D[i] = mx+1;
        if (ans < D[i]) ans = D[i];
    }

    printf("%d", n-ans);

    return 0;
}
