// BOJ 1904 01타일 | DP | 2018-10-31 22:56:52
#include <stdio.h>

int D[1000001];

int main()
{
    int n, i;

    scanf("%d", &n);

    D[1] = 1;
    D[2] = 2;

    for (i = 3; i <= n; i++) {
        D[i] = D[i-1]+D[i-2];
        D[i] %= 15746;
    }

    printf("%d", D[n]);

    return 0;
}
