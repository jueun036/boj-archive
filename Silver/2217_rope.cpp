// BOJ 2217 로프 | 그리디, 정렬 | 2018-06-17 16:44:29
#include <stdio.h>

int r[100001], im[100001];

void f(int s, int e)
{
    if (s == e) return;
    int m = (s+e)/2, p1 = s, p2 = m+1, i;

    f(s, m);
    f(m+1, e);

    for (i = s; i <= e; i++) {
        if (p1 == m+1) im[i] = r[p2++];
        else if (p2 == e+1) im[i] = r[p1++];
        else if (r[p1] < r[p2]) im[i] = r[p1++];
        else im[i] = r[p2++];
    }

    for (i = s; i <= e; i++) r[i] = im[i];
}

int main()
{
    int n, i, max = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    f(1, n);

    for (i = 1; i <= n; i++) {
        if (max < r[i] * (n-i+1)) {
            max = r[i]*(n-i+1);
        }
    }

    printf("%d", max);
    return 0;
}
