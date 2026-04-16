// BOJ 1744 수 묶기 | 그리디 | 2019-12-15 17:37:51
#include <stdio.h>

int plu[10100];
int miu[10100];
int im[10100];

void so(int a[], int s, int e)
{
    if (s == e) return;
    int m, c1, c2, i;
    m = (s+e)/2; c1 = s; c2 = m+1;
    so(a, s, m); so(a, m+1, e);

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
    int N, i, a, sum = 0, mc = 0, pc = 0;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &a);
        if (a <= 0) miu[++mc] = a;
        else plu[++pc] = a;
    }

    if (pc > 0) so(plu, 1, pc);
    if (mc > 0) so(miu, 1, mc);

    for (i = 1; i <= mc-1; i += 2) sum += miu[i]*miu[i+1];
    if (mc % 2 != 0) sum += miu[mc];
    for (i = pc; i >= 2; i -= 2) {
        if (plu[i] == 1 || plu[i-1] == 1) sum += plu[i]+plu[i-1];
        else sum += plu[i]*plu[i-1];
    }
    if (pc % 2 != 0) sum += plu[1];

    printf("%d", sum);

    return 0;
}
