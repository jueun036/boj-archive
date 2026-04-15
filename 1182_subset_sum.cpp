// BOJ 1182 부분수열의 합 | 백트래킹, 브루트포스 | 2018-05-13 16:05:53
#include <stdio.h>

int s[30], is[30], n, p;
int cnt = 0;

void o(int c)
{
    int i, sum = 0;

    if (c == n) {
        for (i = 0; i < n; i++) {
            if (is[i] == 1) {
                sum += s[i];
            }
        }
        if (sum == p) cnt++;
        return;
    }

    for (i = 0; i <= 1; i++) {
        is[c] = i;
        o(c+1);
    }
}

int main()
{
    int i;
    scanf("%d %d", &n, &p);

    for (i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }
    o(0);
    if (p == 0) cnt  = cnt - 1;
    printf("%d", cnt);
    return 0;
}
