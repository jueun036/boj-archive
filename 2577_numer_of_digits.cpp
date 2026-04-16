// BOJ 2577 숫자의 개수 | 구현, 수학 | 2018-03-03 22:17:00
#include <stdio.h>

int main()
{
    int a, b, c, x, s[20], co[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, o = 0, i;

    scanf("%d %d %d", &a, &b, &c);

    x = a*b*c;

    do {
        s[o] = x % 10;
        o++;
        x = x / 10;
    } while (x > 0);

    for (i = 0; i < o; i++) {
        co[s[i]]++;
    }

    for (i = 0; i < 10; i++) {
        printf("%d\n", co[i]);
    }

    return 0;
}
