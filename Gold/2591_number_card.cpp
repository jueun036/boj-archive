// BOJ 2591 숫자카드 | DP | 2020-01-04 09:40:57
#include <stdio.h>
#include <string.h>

char st[50];
int D[50];

int main()
{
    int len, i;

    scanf("%s", st);
    len = strlen(st);

    D[0] = 1;

    for (i = 1; i < len; i++) {
        if (st[i] != '0') {
            D[i] += D[i-1];
        }
        int x = (st[i-1]-'0')*10+st[i]-'0';
        if (x <= 34 && x >= 10) {
            if (i == 1) D[i]+=1;
            else D[i] += D[i-2];
        }
    }

    printf("%d", D[len-1]);

    return 0;
}
