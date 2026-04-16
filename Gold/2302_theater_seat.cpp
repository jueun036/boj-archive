// BOJ 2302 극장 좌석 | DP | 2019-01-30 23:44:23
#include <stdio.h>

int VIP[41], D[41][2];

int main()
{
    int n, m, i, a;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d", &a);
        VIP[a] = 1;
    }

    D[1][0] = 1;

    for (i = 2; i <= n; i++) {
        D[i][0] = D[i-1][0]+D[i-1][1];
        if (VIP[i] == 1) D[i][1] = 0;
        else if (VIP[i-1] == 1) D[i][1] = 0;
        else D[i][1] = D[i-1][0];
    }

    printf("%d", D[n][0]+D[n][1]);

    return 0;
}
