// BOJ 1100 하얀 칸 | 구현 | 2018-05-06 14:35:11
#include <stdio.h>

int chs[10][10];

int check(int x, int y, int c)
{
    if (x % 2 != 0 && y % 2 != 0) {
        c += chs[x][y];
    }
    else if (x % 2 == 0 && y % 2 == 0) {
        c += chs[x][y];
    }
    if (x == 8 && y == 8) return c;
    else if (y == 8) return check (x + 1, 1, c);
    else return check(x, y + 1, c);
}

int main()
{
    int i, j, x;
    char ch[9];

    for (i = 1; i <= 8; i++) {
        scanf("%s", ch);
        for (j = 0; j <= 7; j++) {
            if (ch[j] == '.') chs[i][j+1] = 0;
            else chs[i][j+1] = 1;
        }
    }

    x = check(1, 1 , 0);
    printf("%d", x);

    return 0;
}