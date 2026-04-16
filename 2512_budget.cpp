// BOJ 2512 예산 | 이분 탐색 | 2019-07-13 23:26:48
#include <stdio.h>

int a[100100];

int main()
{
    int n, m, i, mx, bmx = 0, s, e, mid;
    long long sum;

    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);

    s = 0; e = m;
    while (s <= e) {
        sum = 0; mid = (s+e)/2; mx = 0;
        for (i = 1; i <= n; i++) {
            if (mid < a[i]) {
                sum += mid;
                if (mx < mid) mx = mid;
            }
            else {
                sum += a[i];
                if (mx < a[i]) mx = a[i];
            }
        }

        if (sum > m) {
            e = mid-1;
        }
        else {
            s = mid+1;
            if (mx > bmx) bmx = mx;
        }
    }

    printf("%d", bmx);

    return 0;
}
