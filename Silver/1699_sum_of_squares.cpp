// BOJ 1699 제곱수의 합 | DP | 2018-10-24 23:29:34
#include <stdio.h>
#include <math.h>

int D[100001];

int main()
{
    int n, i, j, min = 999999;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        min = 9999;
        for (j = 1; j <= sqrt(i); j++) {
            if (min > D[i-j*j]+1) {
                min = 1+D[i-j*j];
            }
        }
        D[i] = min;
    }

    printf("%d", D[n]);

    return 0;
}
