// BOJ 1010 다리 놓기 | 수학 | 2019-07-18 18:13:43
#include <stdio.h>

int D[40][40];

int main()
{
    int t, a, b, i, j, k, o, sum;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%d %d", &a, &b);
        for (j = 1; j <= b; j++) D[1][j] = j;
        for (j = 2; j <= a; j++) {
            for (k = j; k <= b; k++) {
                sum = 0;
                for (o = j; o <= k; o++) {
                    sum += D[j-1][o-1];
                }
                D[j][k] = sum;
            }
        }
        printf("%d\n", D[a][b]);
    }

    return 0;
}
