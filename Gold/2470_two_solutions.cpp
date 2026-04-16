// BOJ 2470 두 용액 | 투 포인터, 정렬 | 2019-07-11 23:30:31
#include <stdio.h>

long long a[100100], im[100100];

void sort(int s, int e)
{
    if (s == e) return;
    int m, c1, c2, i;
    m = (s+e)/2; c1 = s; c2 = m+1;
    sort(s, m); sort(m+1, e);

    for (i = s; i <= e; i++) {
        if ((c1 <= m && c2 <= e && a[c1] <= a[c2]) || (c1 <= m && c2 > e)) {
            im[i] = a[c1++];
        }
        else im[i] = a[c2++];
    }

    for (i = s; i <= e; i++) a[i] = im[i];
}

int f(int a)
{
    if (a < 0) return -a;
    return a;
}
int main()
{
    int n, i, s, e;
    long long ansa, ansb, mn;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    sort(1, n);

    s =  1; e = n; mn = 999999999999;
    while(1) {
        if (s >= e) break;
        if (f(a[s]+a[e]) < mn) {
            mn = f(a[s]+a[e]);
            ansa = a[s]; ansb = a[e];
        }
        if (a[s]+a[e] < 0) s++;
        else e--;
    }

    if (ansa > ansb) printf("%lld %lld", ansb, ansa);
    else printf("%lld %lld", ansa, ansb);

    return 0;
}
