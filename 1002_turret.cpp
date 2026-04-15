// BOJ 1002 터렛 | 수학 | 2025-03-23 23:31:18
#define _CRT_SECURE_NO_WANRINGS_
#include <stdio.h>
#include <math.h>

int main()
{
    int n, i;
    double dist;
    int x1, x2, y1, y2, r1, r2;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        dist = sqrt(((x2 - x1)*(x2 - x1)) + ((y2 - y1)*(y2-y1)));
        if (x1 == x2 && y1 == y2 && r1 == r2) printf("-1\n");
        else {
            if (dist > r1 && dist > r2) {
                if (dist < r1 + r2) printf("2\n");
                else if (dist == r1 + r2) printf("1\n");
                else printf("0\n");
            }
            else if (r1 > dist && r1 > r2) {
                if (r1 < dist + r2)	printf("2\n");
                else if (r1 == dist + r2) printf("1\n");
                else printf("0\n");
            }
            else {
                if (r2 < dist + r1) printf("2\n");
                else if (r2 == dist + r1) printf("1\n");
                else printf("0\n");
            }
        }
    }

    return 0;
}
