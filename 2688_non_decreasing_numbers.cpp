// BOJ 2688 줄어들지 않아 | DP | 2020-01-03 22:46:46
#include <stdio.h>

long long int cnt[100][20];

int main()
{
    int T, n, i, j;
    long long int ans;

    scanf("%d", &T);

    for (i = 0; i <= 9; i++) cnt[1][i] = 1;
    for (i = 2; i <= 64; i++) {
        cnt[i][0] = 1;
        for (j = 1; j <= 9; j++) {
            cnt[i][j] = cnt[i][j-1]+cnt[i-1][j];
        }
    }

    for (i = 1; i <= T; i++) {
        scanf("%d", &n);
        ans = 0;
        for (j = 0; j <= 9; j++) {
            ans += cnt[n][j];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
