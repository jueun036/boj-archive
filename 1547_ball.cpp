// BOJ 1547 공 | 구현 | 2018-06-10 16:27:07
#include <stdio.h>

int main()
{
    int n, i, a, b, h = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d", &a, &b);
        if (h == a) h = b;
        else if (h == b) h = a;
    }

    printf("%d", h);

    return 0;
}
