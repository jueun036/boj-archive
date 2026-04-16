// BOJ 2023 신기한 소수 | 백트래킹, 수학 | 2019-12-27 01:15:23
#include <stdio.h>

int num[100];
int im[100];
int cnt[10];

int check(int x)
{
    int i, f = 0;

    for (i = 2; i * i <= x; i++) {
        if (x % i == 0) f = 1;
    }

    if (f == 1) return 0;
    return 1;
}

int main()
{
    int N, i, j, k, be, ne;

    scanf("%d", &N);

    im[1] = 2;
    im[2] = 3;
    im[3] = 5;
    im[4] = 7;
    be = 4;

    for (i = 2; i <= N; i++) {
        ne = 0;
        for (j = 1; j <= be; j++) {
            for (k = 0; k <= 9; k ++) {
                if (check(im[j]*10+k) == 1) {
                    num[++ne] = im[j]*10+k;
                }
            }
        }
        for (j = 1; j <= ne; j++) {
            im[j] = num[j];
        }
        be = ne;
    }

    for (i = 1; i <= be; i++) {
        printf("%d\n", im[i]);
    }

    return 0;
}
