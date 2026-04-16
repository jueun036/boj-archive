// BOJ 2010 플러그 | 수학, 구현 | 2019-05-11 20:19:16
#include <stdio.h>

int main()
{
    int n, a, sum, i;

    scanf("%d", &n);

    sum = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        sum += a;
    }

    printf("%d", sum-n+1);

    return 0;
}
