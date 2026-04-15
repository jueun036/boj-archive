// BOJ 1110 더하기 사이클 | 구현 | 2018-02-15 12:53:00
#include <stdio.h>

int main()
{
    int n, s[101], c = 0, i ;

    scanf("%d", &n);

    s[0] = n / 10;
    s[1] = n % 10;

    for (i = 0; ; i++) {
        s[i + 2] = (s[i] + s[i + 1]) % 10;
        c++;
        if (i != 0) {
            if (s[i] == s[0] && s[i + 1] == s[1]) break;
        }
    }

    printf("%d", c - 1);

    return 0;
}
