// BOJ 2475 검증수 | 구현, 수학 | 2018-04-06 23:49:08
#include <stdio.h>

int main()
{
    int s[6], i, sum = 0;

    for (i = 1; i <= 5; i++) {
        scanf("%d", &s[i]);
        sum += s[i] * s[i];
    }

    printf("%d", sum % 10);

    return 0;
}
