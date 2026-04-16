// BOJ 2616 소형기관차 | DP, 누적 합 | 2019-02-02 11:12:47
#include <stdio.h>

int train[60001], a[60001], D[60001][3];

int mx(int a, int b)
{
    if (a > b) return a;
    return b;
}
int main()
{
    int n, i, x;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &train[i]);
    }

    scanf("%d", &x);

    for (i = 1; i <= x; i++) a[1] += train[i];

    for (i = 2; i <= n-x+1; i++) {
        a[i] = a[i-1]-train[i-1]+train[i+x-1];
    }

    for (i = 1+x; i <= n-(2*x)+1; i++) {
        D[i][0] = mx(a[i-x], D[i-1][0]);
    }

    for (i = n-(2*x)+1; i >= 1+x; i--) {
        D[i][1] = mx(a[i+x], D[i+1][1]);
    }

    int mxx = 0;

    for (i = 1+x; i <= n-(2*x)+1; i++) {
        if (mxx < D[i][0]+D[i][1]+a[i]) mxx = D[i][0]+D[i][1]+a[i];
    }

    printf("%d", mxx);

    return 0;
}
