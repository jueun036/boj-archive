// BOJ 2133 타일 채우기 | DP | 2018-10-22 00:04:31
#include <stdio.h>

int D[31][4];

int main()
{
    int n, i;

    scanf("%d", &n);

    D[0][1] = 1;
    D[1][3] = 0;
    D[1][2] = 1;
    D[1][1] = 0;

    for (i = 2; i <= n; i++) {
        D[i][3] = D[i-1][2];
        D[i][2] = D[i-1][1]+D[i-1][3];
        D[i][1] = D[i-2][1]+D[i][3]*2;
    }

    printf("%d", D[n][1]);

    return 0;
}
