// BOJ 2588 곱셈 | 구현, 수학 | 2019-05-13 21:38:44
#include <stdio.h>

int x[5];

int main()
{
    int a, b, i;

    scanf("%d %d", &a, &b);

    int s = b;
    for (i = 1; i <= 3; i++) {
        x[i] = b % 10;
        b /= 10;
    }

    for (i = 1; i <= 3; i++) {
        printf("%d\n", x[i]*a);
    }

    printf("%d", a*s);

    return 0;
}
