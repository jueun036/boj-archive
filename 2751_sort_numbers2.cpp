// BOJ 2751 수 정렬하기 2 | 정렬 | 2019-07-03 18:17:36
#include <stdio.h>

int a[1000100], im[1000100];

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

int main()
{
    int n, i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(1, n);

    for (i = 1; i <= n; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
