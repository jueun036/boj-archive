// BOJ 2530 인공지능 시계 | 구현, 수학 | 2019-05-18 11:22:39
#include <stdio.h>

int main()
{
    int a, b, c, d;
    int ansa, ansb, ansc, sum;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    sum = a*3600+b*60+c+d;

    ansc = sum % 60;
    sum /= 60;
    ansb = sum % 60;
    ansa = (sum / 60)% 24;

    printf("%d %d %d", ansa, ansb, ansc);

    return 0;
}
