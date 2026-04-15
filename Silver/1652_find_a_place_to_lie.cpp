// BOJ 1652 누울 자리를 찾아라 | 구현, 문자열 | 2018-06-17 15:01:14
#include <stdio.h>

char s[101][101];

int main()
{
    int n, i, j, o, c, x, y;

    x = y = c = o = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf(" %c", &s[i][j]);
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (j == n) {
                if (s[i][j] == '.') c++;
                if (s[j][i] == '.') o++;
                if (c >= 2) x++;
                if (o >= 2) y++;
            }
            else {
                if (s[i][j] == '.') c++;
                else {
                    if (c >= 2) x++;
                    c = 0;
                }
                if (s[j][i] == '.') o++;
                else {
                    if (o >= 2) y++;
                    o = 0;
                }
            }
        }
        c = 0;
        o = 0;
    }

    printf("%d %d", x, y);

    return 0;
}
