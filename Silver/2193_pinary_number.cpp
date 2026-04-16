// BOJ 2193 이친수 | DP | 2018-08-03 10:49:41
#include <stdio.h>

long long int dpz[91] = {0, 0, 1, 1, 2}, dpo[91] = {0, 1, 0, 1, 1};

int main()
{
    int n, i;

    scanf("%d", &n);

    if (n >= 5) {
        for (i = 5; i <= n; i++) {
            dpz[i] = dpz[i-1]+dpo[i-1];
            dpo[i] = dpz[i-1];
        }
    }
    printf("%lld", dpz[n]+dpo[n]);

    return 0;
}
