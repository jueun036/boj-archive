// BOJ 1717 집합의 표현 | 자료구조, 유니온파인드 | 2018-11-03 11:55:25
#include <stdio.h>

int par[1000001];

int check(int x)
{
    if (par[x] == x) return x;
    return par[x] = check(par[x]);
}
void uni(int a, int b)
{
    int ka, kb;

    ka = check(a);
    kb = check(b);
    par[kb] = ka;
}
int main()
{
    int n, m, x, a, b, i;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        par[i] = i;
    }

    for (i = 1; i <= m; i++) {
        scanf("%d %d %d", &x, &a, &b);
        if (x == 0) {
            uni(a, b);
        }
        else {
            if (check(a) == check(b)) printf("YES\n");
            else printf("NO\n");
        }
    }

    return 0;
}
