// BOJ 1008 A/B | 구현 | 2025-06-21 23:04:37
#include <stdio.h>

int main()
{
    int a, b;
    double ans;

    scanf("%d %d", &a, &b);
    ans = (double)a / (double)b;

    printf("%.10f", ans);

    return 0;
}