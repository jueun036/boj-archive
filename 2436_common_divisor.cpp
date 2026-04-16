// BOJ 2436 공약수 | 수학, 정수론 | 2019-11-08 22:18:38
#include <stdio.h>

long long int gcd(int a, int b)
{
    if (a%b == 0) return b;
    return gcd(b, a%b);
}

int main()
{
    long long int A, B, x, ansa, ansb, ansf = 0, G, i, mn = 99999999999999999;

    scanf("%lld %lld", &A, &B);

    x = A*B;

    for (i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (i > x / i) G = gcd(i, x/i);
            else G = gcd(x/i, i);
            if (G == A && i+x/i < mn) {
                ansa = i;
                ansb = x/i;
                mn = i+x/i;
                ansf = 1;
            }
        }
    }

    if (ansf == 1) {
        if (ansa < ansb) printf("%lld %lld", ansa, ansb);
        else printf("%lld %lld", ansb, ansa);
    }

    return 0;
}
