// BOJ 2480 주사위 세개 | 구현, 수학 | 2019-07-04
#include <stdio.h>

int ch[7];

int main()
{
    int i, a, x, num;

    for (i = 1; i <= 3; i++) {
        scanf("%d", &a);
        ch[a]++;
    }

    for (i = 1; i <= 6; i++) {
        if (ch[i] == 3) {
            x = i;
            num = 3;
            break;
        }
        else if (ch[i] == 2) {
            x = i;
            num = 2;
            break;
        }
        else if (ch[i] == 1) {
            x = i;
            num = 1;
        }
    }

    if (num == 3) printf("%d", 10000+x*1000);
    else if (num == 2) printf("%d", 1000+x*100);
    else printf("%d", x*100);

    return 0;
}
