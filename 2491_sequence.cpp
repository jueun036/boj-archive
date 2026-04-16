// BOJ 2491 수열 | 구현, DP | 2020-01-04 09:44:50
#include <stdio.h>

int a[100100];

int main()
{
    int N, i, mx1, mx2, c, before;

    mx1 = mx2 = 0;
    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    before = a[1];
    c = 1;
    for (i = 2; i <= N; i++) {
        if (before <= a[i]) {
            before = a[i];
            c++;
        }
        else {
            before = a[i];
            c = 1;
        }
        if (c > mx1) mx1 = c;
    }

    before = a[1];
    c = 1;
    for (i = 2; i <= N; i++) {
        if (before >= a[i]) {
            before = a[i];
            c++;
        }
        else {
            before = a[i];
            c = 1;
        }
        if (c > mx2) mx2 = c;
    }

    if (N == 1) {
        printf("1");
    }
    else {
        if (mx1 > mx2) printf("%d", mx1);
        else printf("%d", mx2);
    }

    return 0;
}
