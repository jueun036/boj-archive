// BOJ 1629 곱셈 | 수학, 분할정복 | 2019-04-27 10:46:33
#include <stdio.h>

long long x(long long a, long long b, long long c)
{
    if (b == 1) return a%c;
    long long o = x(a, b/2, c);
    if (b % 2 == 1) {
        return (((o*o)%c)*a) % c;
    }
    return (o*o) % c;
}

int main()
{
    long long A, B, C;

    scanf("%lld %lld %lld", &A, &B, &C);

    printf("%lld", x(A, B, C));

    return 0;
}
