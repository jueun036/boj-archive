// BOJ 1038 감소하는 수 | 브루트포스, 백트래킹 | 2019-02-28 22:41:23
#include <stdio.h>

int D[15][1000001],cou[15];

int main()
{
    int n, i, j, k, ten, c = 9, ci;

    scanf("%d", &n);
    ten = 10;
    for (i = 0; i <= 9; i++) D[1][i] = i;
    if (n < 10) printf("%d", n);
    else {
        cou[1] = 10;
        for (i = 2; i <= 10; i++) {
            ci = 0;
            for (j = 0; j <= 9; j++) {
                for (k = 0; k < cou[i-1]; k++) {
                    if (D[i-1][k]/(ten/10) < j) {
                        D[i][ci] = j*ten+D[i-1][k];
                        ci++;
                        c++;
                        if (c == n) {
                            if (n == 1022) printf("9876543210");
                            else printf("%d", D[i][ci-1]);
                            return 0;
                        }
                    }
                    else break;
                }
            }
            cou[i] = ci;
            ten *= 10;
        }
        if (c < n) printf("-1");
    }

    return 0;
}
