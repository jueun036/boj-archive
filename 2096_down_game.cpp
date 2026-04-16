// BOJ 2096 내려가기 | DP, 슬라이딩 윈도우 | 2019-01-20 21:32:07
#include <stdio.h>

int A[100001][4], Dn1[4], Dn2[4], Dx1[4], Dx2[4];

int main()
{
    int n, i, j, k, mn, mx;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= 3; j++) {
            if (j == 1) {
                if (Dn1[1] < Dn1[2]) Dn2[j] = Dn1[1]+A[i][j];
                else Dn2[j] = Dn1[2] + A[i][j];
                if (Dx1[1] > Dx1[2]) Dx2[j] = Dx1[1]+A[i][j];
                else Dx2[j] = Dx1[2] + A[i][j];
            }
            else if (j == 2) {
                mn = 99999999;
                mx = -1;
                for (k = 1; k <= 3; k++) {
                    if (mn > Dn1[k]) mn = Dn1[k];
                    if (mx < Dx1[k]) mx = Dx1[k];
                }
                Dn2[j] = mn+A[i][j];
                Dx2[j] = mx+A[i][j];
            }
            else {
                if (Dn1[2] < Dn1[3]) Dn2[j] = Dn1[2]+A[i][j];
                else Dn2[j] = Dn2[3]+A[i][j];
                if (Dx1[2] > Dx1[3]) Dx2[j] = Dx1[2]+A[i][j];
                else Dx2[j] = Dx2[3]+A[i][j];
            }
        }
        for (j = 1; j <= 3; j++) {
            Dn1[j] = Dn2[j];
            Dx1[j] = Dx2[j];
        }
    }

    mn = 999999999;
    mx = -1;
    for (i = 1; i <= 3; i++) {
        if (mn > Dn1[i]) mn = Dn1[i];
        if (mx < Dx1[i]) mx = Dx1[i];
    }

    printf("%d %d", mx, mn);

    return 0;
}
