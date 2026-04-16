// BOJ 2477 참외밭 | 구현, 기하학 | 2019-07-06 14:17:30
#include <stdio.h>

int a[10][5];

int main()
{
    int k, i, s1, s2, big, small;
    int mx1 = 0, mx2 = 0, mx1i, mx2i;

    scanf("%d", &k);

    for (i = 1; i <= 6; i++) {
        scanf("%d %d", &a[i][0], &a[i][1]);
        if (a[i][0] == 1 || a[i][0] == 2) {
            if (mx1 < a[i][1]) {
                mx1 = a[i][1];
                mx1i = i;
            }
        }
        else {
            if (mx2 < a[i][1]) {
                mx2 = a[i][1];
                mx2i = i;
            }
        }
    }

    for (i = 1; i <= 6; i++) {
        int x = i-1, y = i+1;
        if (i == 6) y = 1;
        if (i == 1) x = 6;
        if (a[i][0] == 1 || a[i][0] == 2) {
            if (x != mx2i && y != mx2i && i != mx2i) {
                s1 = a[i][1];
            }
        }
        else {
            if (x != mx1i && y != mx1i && i != mx1i) {
                s2 = a[i][1];
            }
        }
    }

    big = mx1 * mx2; small = s1 * s2;

    printf("%d", (big-small)*k);

    return 0;
}
