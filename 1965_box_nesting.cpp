// BOJ 1965 상자넣기 | DP, LIS | 2018-10-25 21:56:14
#include <stdio.h>

int B[1001], D[1001];

int main()
{
    int n, i, j, max1, max2 = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &B[i]);
    }

    D[n] = 1;
    for (i = n-1; i >= 1; i--) {
        max1 = 0;
        for (j = i; j <= n; j++) {
            if (B[i] < B[j]) {
                if (max1 < D[j]) {
                    max1 = D[j];
                }
            }
        }
        D[i] = max1+1;
        if (max2 < D[i]) {
            max2 = D[i];
        }
    }

    printf("%d", max2);

    return 0;
}
