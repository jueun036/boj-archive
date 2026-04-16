// BOJ 2445 별 찍기 - 8 | 구현 | 2018-05-06 14:00:36
#include <stdio.h>

int star1(int n, int x, int y)
{
    if (x >= y) printf("*");
    else if (n*2+1-x <= y) printf("*");
    else printf(" ");
    if (x == n && y == n*2) return 0;
    else if (y == n*2) {
        printf("\n");
        return star1(n, x+1, 1);
    }
    else return star1(n, x, y+1);
}

int star2 (int n, int x, int y)
{
    if (x >= y) printf("*");
    else if (n*2+1-x <= y) printf("*");
    else printf(" ");
    if (x == 1 && y == 1) return 0;
    else if (y == 1) {
        printf("\n");
        return star2(n, x-1, n*2);
    }
    else return star2(n, x, y-1);
}

int main()
{
    int n;

    scanf("%d", &n);
    if (n == 1) printf("**");
    else {
        star1(n, 1, 1);
        printf("\n");
        star2(n, n-1, n*2);
    }

    return 0;
}
