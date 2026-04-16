// BOJ 2711 오타맨 고창영 | 구현 | 2019-05-15 21:16:11
#include <stdio.h>
#include <string.h>

char st[100];

int main()
{
    int T, i, j, x, len;

    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d %s", &x, st);
        len = strlen(st);
        for (j = 0; j < len; j++) {
            if (j != x-1) {
                printf("%c", st[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
