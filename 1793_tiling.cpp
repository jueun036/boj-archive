// BOJ 1793 타일링 | DP | 2019-03-02 10:55:22
#include <stdio.h>

char D1[100], D2[100], D3[100], D4[100];
int c1, c2, c3, c4;

void x()
{
    int i, num, pl = 0;

    for (i = c1; i >= 1; i--) {
        num = (D1[i]-'0')*2;
        D3[i] = (num+pl)%10+'0';
        pl = (num+pl)/10;
    }
    if (pl != 0) {
        D3[0] = pl+'0';
        c3 = c1+1;
    }
    else c3 = c1;
}
void plu()
{
    int i, big, num1, num2, pl = 0, minu;

    if (c2 < c3) {
        minu = c3-c2; big = c3;
    }
    else minu = c2-c3; big = c2;

    for (i = big; i >= 1; i--) {
        if (c2 < c3) {
            if (i-minu >= 1) num1 = D2[i-minu]-'0';
            else num1 = 0;
            num2 = D3[i]-'0';
        }
        else {
            num1 = D2[i]-'0';
            if (i-minu >= 1) num2 = D3[i-minu]-'0';
            else num2 = 0;
        }
        D4[i] = (num1+num2+pl)%10+'0';
        pl = (num1+num2+pl)/10;
    }
    if (pl != 0) {
        D4[0] = pl+'0';
        c4 = big+1;
    }
    else c4 = big;

}
int main()
{
    int n, i, j;

    D1[1] = '1'; D2[1] = '3'; c1 = c2 = 1;
    D1[0] = '0'; D3[0] = '0';

    while(scanf("%d", &n) != EOF) {
        if (n == 0) printf("1\n");
        else if (n == 1) printf("1\n");
        else if (n == 2) printf("3\n");
        else {
            D1[1] = '1'; D2[1] = '3'; c1 = c2 = 1;
            D1[0] = '0'; D3[0] = '0';
            for (i = 3; i <= n; i++) {
                D1[0] = '0'; D2[0] = '0'; D3[0] = '0'; D4[0] = '0';
                x();
                if (D3[0] != '0') {
                    for (j = c3; j >= 1; j--) D3[j] = D3[j-1];
                }
                plu();
                if (D4[0] != '0') {
                    for (j = c4; j >= 1; j--) D4[j] = D4[j-1];
                }
                for (j = 1; j <= c2; j++) D1[j] = D2[j];
                for (j = 1; j <= c4; j++) D2[j] = D4[j];
                c1 = c2;
                c2 = c4;
            }
            for (i = 1; i <= c4; i++) {
                printf("%c", D4[i]);
            }
            printf("\n");
        }
    }

    return 0;
}

