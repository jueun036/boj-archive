// BOJ 1963 소수 경로 | 그래프 탐색, BFS, 에라토스테네스의 체 | 2019-12-23 22:28:40
#include <stdio.h>

int num[10100];
int q[10100];
int chk[10100];

int check(int x)
{
    int i, f = 0;

    for (i = 2; i * i <= x; i++) {
        if (x % i == 0) f = 1;
    }

    if (f == 1) return 0;
    return 1;
}

void bfs(int a)
{
    int i, j, x, s, e, o;

    q[1] = a;
    s = e = 1;
    num[a] = 0;
    chk[a] = 1;

    while(s <= e) {
        x = q[s++];
        for (i = 10000; i >= 10; i /= 10) {
            for (j = 0; j <= 9; j++) if (j != 0 || i != 10000) {
                o = (x/i)*i;
                o += x%(i/10)+(i/10)*j;
                if (chk[o] == 0 && check(o) == 1) {
                    num[o] = num[x]+1;
                    q[++e] = o;
                }
                chk[o] = 1;
            }
        }
    }
}

int main()
{
    int t, i, j, a, b;

    scanf("%d", &t);

    for (i = 1; i <= t; i++) {
        scanf("%d %d", &a, &b);
        for (j = 1000; j <= 9999; j++) {
            chk[j] = 0;
            num[j] = -1;
        }
        bfs(a);
        if (num[b] == -1) printf("Impossible\n");
        else printf("%d\n", num[b]);

    }

    return 0;
}
