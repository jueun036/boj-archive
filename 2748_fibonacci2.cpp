// BOJ 2748 피보나치 수 2 | DP | 2020-09-05 15:01:12
#include <stdio.h>

long long int a[100];

int main()
{
    long long int N, i;

    scanf("%lld", &N);

    a[1] = 1; a[2] = 1;
    for (i = 3; i <= N; i++) {
        a[i] = a[i-1]+a[i-2];
    }

    printf("%lld", a[N]);

    return 0;
}
