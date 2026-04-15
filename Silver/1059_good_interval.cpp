// BOJ 1059 좋은 구간 | 수학, 브루트포스 | 2020-10-03 12:48:29
#include <stdio.h>

int a[1100];

int main()
{
    int L, N, i, j, k, mx, mn;

    scanf("%d", &L);

    for (i = 1; i <= L; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &N);

    mx = 0; mn = 9999;
    for (i = 1; i <= L; i++) {
        if (a[i] <= N) {
            if (mx < a[i]) mx = a[i];
        }
        if (a[i] >= N) {
            if (mn > a[i]) mn = a[i];
        }
    }
    int canS = N - (mx + 1) + 1;
    int canE = (mn - 1) - N + 1;
    if (canS < 0)canS = 0;
    if (canE < 0)canE = 0;
    int ans = canS * canE - 1;
    if (ans < 0) ans = 0;
    printf("%d",ans);

    return 0;
}