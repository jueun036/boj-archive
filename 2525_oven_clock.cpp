// BOJ 2525 오븐 시계 | 구현, 수학 | 2019-05-13 23:09:42
#include <stdio.h>

int main()
{
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    int sum = 60*a+b+c;

    if(sum/60 >= 24) printf("%d %d", sum/60-24, sum%60);
    else printf("%d %d", sum/60, sum%60);

    return 0;
}
