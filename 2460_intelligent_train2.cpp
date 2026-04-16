// BOJ 2460 지능형 기차 2 | 구현, 시뮬레이션 | 2019-06-29 09:31:15
#include <stdio.h>

int p[20];

int main()
{
    int i, sum = 0, a, b;

    for (i = 1; i <= 10; i++) {
        scanf("%d %d", &a, &b);
        p[i] = b-a;
    }

    int mx = 0;
    for (i = 1; i <= 10; i++) {
        sum += p[i];
        if (sum > 10000) sum = 10000;
        if (sum > mx) mx = sum;
    }

    printf("%d", mx);

    return 0;
}
