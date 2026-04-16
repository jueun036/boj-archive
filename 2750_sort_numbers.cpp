// BOJ 2750 수 정렬하기 | 정렬 | 2019-01-27 21:04:12
#include <stdio.h>

int a[1001], im[1001];

void change(int &a, int &b)
{
    int o = a; a = b; b = o;
}
void sort(int s, int e)
{
    if (s == e) return;
    int m, c1, c2, i;
    m = (s+e)/2; c1 = s; c2 = m+1;
    sort(s, m);
    sort(m+1, e);

    for (i = s; i <= e; i++) {
        if (c1 <= m && c2 > e || c1 <= m && c2 <= e && a[c1] < a[c2]) {
            im[i] = a[c1];
            c1++;
        }
        else {
            im[i] = a[c2];
            c2++;
        }
    }

    for (i = s; i <= e; i++) {
        a[i] = im[i];
    }
}

int main()
{
    int N, i;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &a[i]);
    }

    sort(1, N);

    for (i = 1; i <= N; i++) {
        printf("%d\n", a[i]);
    }

    return 0;
}
