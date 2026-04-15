// BOJ 1309 동물원 | DP | 2018-10-30 23:06:16
#include <stdio.h>

int D[100001][4];

int main()
{
    int n, i, j;

    scanf("%d", &n);

    D[1][1] = 1;
    D[1][2] = 1;
    D[1][3] = 1;

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            if (j == 1) {
                D[i][j] = D[i-1][1]+D[i-1][2]+D[i-1][3];
            }
            else if (j == 2) {
                D[i][j] = D[i-1][1]+D[i-1][3];
            }
            else {
                D[i][j] = D[i-1][1]+D[i-1][2];
            }
        }
        D[i][1] %= 9901;
        D[i][2] %= 9901;
        D[i][3] %= 9901;
    }

    printf("%d", (D[n][1]+D[n][2]+D[n][3]) % 9901);

    return 0;
}
