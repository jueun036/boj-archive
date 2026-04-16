// BOJ 2675 문자열 반복 | 구현 | 2018-03-29
#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, s, j, o, len;
    char ch[21];

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %s", &s, ch);
        len = strlen(ch);

        for (j = 0; j < len; j++) {
            for (o = 1; o <= s; o++) {
                printf("%c", ch[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
