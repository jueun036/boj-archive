// BOJ 2003 수들의 합 2 | 투 포인터 | 2019-01-05 10:51:58
#include <stdio.h>

int A[10001], x[10001];

int main()
{
    int n, m, i, s, e, mid, sum, c = 0;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        x[i] = x[i-1]+A[i];
    }

    for (i = 1; i <= n; i++) {
        s = i; e = n;
        while(s <= e) {
            mid = (s+e)/2;
            sum = x[mid]-x[i-1];
            if (sum < m) s = mid+1;
            else if (sum == m) {
                c++;
                break;
            }
            else e = mid-1;
        }
    }

    printf("%d", c);

    return 0;
}
