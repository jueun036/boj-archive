// BOJ 1085 직사각형에서 탈출 | 수학 | 2018-05-12 13:27:49
#include <stdio.h>

int main()
{
    int x, y, w, h, a, b, min = 999999999;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    a = w-x;
    b = h-y;

    if (a > x) {
        min = x;
    }
    else {
        min = a;
    }

    if (min > b) min = b;
    if (min > y) min = y;

    printf("%d", min);

    return 0;
}
