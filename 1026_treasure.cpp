// BOJ 1026 보물 | 정렬, 그리디 | 2018-02-20 22:47:20
#include <stdio.h>

int a[51], b[51];

void change(int n)
{
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
            if (b[i] < b[j]) {
                int t = b[i];
                b[i] = b[j];
                b[j] = t;
            }
        }
    }
}

int main()
{
    int n, i, sum = 0;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) scanf("%d", &b[i]);
    change(n);

    for (i = 1; i <= n; i++) {
        sum += a[i] * b[i];
    }

    printf("%d", sum);
    return 0;
}