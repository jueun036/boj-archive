// BOJ 2514 자동 분무기 | 문자열, 그리디 | 2019-11-16 21:22:25
#include <stdio.h>

int a[10][10];
int inx[10];
int iny[10];
int ansx[10];
int ansy[10];
int ans[10][10];

int main()
{
    int M, K, i, j, insum = 0, anssum = 0;

    scanf("%d %d", &M, &K);

    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            scanf("%d", &a[i][j]);
            a[i][j] -= M;
            insum += a[i][j];
            inx[i] += a[i][j];
            iny[j] += a[i][j];
        }
    }

    anssum = insum/15;

    for (i = 1; i <= 8; i++) {
        ansx[i] = (inx[i]-anssum)/7;
        ansy[i] = (iny[i]-anssum)/7;
    }

    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            ans[i][j] = ansx[i]+ansy[j]-a[i][j];
        }
    }

    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            if (ans[i][j] < 0) printf("- ");
            else if (ans[i][j] == 0) printf(". ");
            else printf("+ ");
        }
        printf("\n");
    }

    return 0;
}
