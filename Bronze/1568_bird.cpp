// BOJ 1568 새 | 구현, 시뮬레이션 | 2018-06-10 16:49:07
#include <stdio.h>

int main()
{
    int n, x, c = 0, i;

    scanf("%d", &n);

    x = n;
    for (i = 1; ; i++) {
        if (x >= i) {
            x -= i;
            c++;
        }
        else i = 0;
        if (x == 0) break;
    }

    printf("%d", c);

    return 0;
}
