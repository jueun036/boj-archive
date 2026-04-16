// BOJ 2473 세 용액 | 투 포인터, 정렬 | 2019-11-16 19:02:51
#include <stdio.h>

long long int a[5100];
long long int im[5100];

void sort(long long int s, long long int e)
{
    if (s == e) return;
    long long int m, c1, c2, i;
    m = (s+e)/2; c1 = s; c2 = m+1;
    sort(s, m); sort(m+1, e);

    for (i = s; i <= e; i++) {
        if ((c1 <= m && c2 <= e && a[c1] < a[c2]) || (c1 <= m && c2 > e)) {
            im[i] = a[c1++];
        }
        else im[i] = a[c2++];
    }

    for (i = s; i <= e; i++) {
        a[i] = im[i];
    }
}

long long int pl(long long int x, long long int y, long long int z)
{
    long long int sum;
    sum = x+y+z;
    if (sum < 0) return -sum;
    return sum;
}

int main()
{
    long long int N, i, j, sum1, sum2, k, f, ans1, ans2, ans3, mn;

    scanf("%lld", &N);

    for (i = 1; i <= N; i++) {
        scanf("%lld", &a[i]);
    }

    sort(1, N);

    mn = 999999999999999;

    for (i = 1; i <= N-2; i++) {
        k = N;
        f = 0;
        for (j = i+1; j <= N-1; j++) {
            if (f == 1 || j >= k) break;
            while(j < k) {
                sum1 = pl(a[i], a[j], a[k]);
                sum2 = pl(a[i], a[j], a[k-1]);
                if (sum1 > sum2) {
                    k--;
                    if (j == k) {
                        f = 1;
                        break;
                    }
                    if (sum2 < mn) {
                        mn = sum2;
                        ans1 = a[i];
                        ans2 = a[j];
                        ans3 = a[k];
                    }
                }
                else {
                    if (sum1 < mn) {
                        mn = sum1;
                        ans1 = a[i];
                        ans2 = a[j];
                        ans3 = a[k];
                    }
                    break;
                }
            }
        }
    }

    printf("%lld %lld %lld", ans1, ans2, ans3);

    return 0;
}
