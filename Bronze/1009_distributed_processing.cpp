// BOJ 1009 분산 처리 | 수학 | 2018-06-24 15:04:53
#include <stdio.h>

int main()
{
    int n, i, j, x, a, b;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        x = 1;
        for (j = 1; j <= b; j++) {
            x *= a;
            x %= 10;
        }
        if (x == 0) printf("10\n");
        else printf("%d\n", x);
    }

    return 0;
}