// BOJ 1780 종이의 개수 | 분할정복 | 2019-03-10 22:06:34
#include <stdio.h>

int p[3000][3000], c[3];

void paper(int x1, int y1, int x2, int y2, int si)
{
    int i, j, check, o;

    if (x1 == x2 && y1 == y2) {
        c[p[x1][y1]]++;
        return;
    }
    else {
        o = 0;
        check = p[x1][y1];
        for (i = x1; i <= x2; i++) {
            for (j = y1; j <= y2; j++) {
                if (p[i][j] != check) {
                    o = 1;
                    break;
                }
            }
            if (o == 1) break;
        }
    }
    if (o == 1) {
        paper(x1, y1, x1+si/3-1, y1+si/3-1, si/3);
        paper(x1, y1+si/3, x1+si/3-1, y1+(si/3*2)-1, si/3);
        paper(x1, y1+(si/3*2), x1+si/3-1, y2, si/3);
        paper(x1+si/3, y1, x1+(si/3*2)-1, y1+si/3-1, si/3);
        paper(x1+si/3, y1+si/3, x1+(si/3*2)-1, y1+(si/3*2)-1, si/3);
        paper(x1+si/3, y1+(si/3*2), x1+(si/3*2)-1, y2, si/3);
        paper(x1+(si/3*2), y1, x2, y1+si/3-1, si/3);
        paper(x1+(si/3*2), y1+si/3, x2, y1+(si/3*2)-1, si/3);
        paper(x1+(si/3*2), y1+(si/3*2), x2, y2, si/3);
    }
    else {
        c[check]++;
        return;
    }
}

int main()
{
    int N, i, j;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            scanf("%d", &p[i][j]);
            if (p[i][j] == -1) p[i][j] = 2;
        }
    }

    paper(1, 1, N, N, N);

    printf("%d\n", c[2]);
    for (i = 0; i <= 1; i++) {
        printf("%d\n", c[i]);
    }

    return 0;
}
