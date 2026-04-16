// BOJ 1759 암호 만들기 | 백트래킹, 조합 | 2018-05-13 17:13:26
#include <stdio.h>

char s[20];
int m[20], x[20], l, c;

void change()
{
    int i, j;

    for (i = 1; i <= c; i++) {
        for (j = i+1; j <= c; j++) {
            if (s[i] > s[j]) {
                char p = s[i];
                s[i] = s[j];
                s[j] = p;
            }
        }
    }
}

void o(int co, int mc, int jc)
{
    int i;

    if (co == c+1) {
        if (mc+jc==l&&mc >= 1 && jc >= 2) {
            for (i = 0; i < l; i++) {
                printf("%c", x[i]);
            }
            printf("\n");
        }
        return;
    }

    for (i = 1; i >= 0; i--) {
        if (i == 1) {
            x[mc+jc] = s[co];
            if (m[co] == 1) o(co+1, mc+1, jc);
            else o(co+1, mc, jc+1);
        }
        else {
            o(co+1, mc, jc);
        }
    }
}

int main()
{
    int i;

    scanf("%d %d", &l, &c);

    for (i = 1; i <= c; i++) {
        scanf(" %c", &s[i]);
    }
    change();
    for (i = 1; i <= c; i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') m[i] = 1;
    }
    o(1, 0, 0);

    return 0;
}
