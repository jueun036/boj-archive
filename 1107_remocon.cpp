// BOJ 1107 리모컨 | 브루트포스, 구현 | 2019-12-15 15:54:23
#include <stdio.h>

int check[20];
int dp1[1000100];
int dp2[1000100];

int chk(int x)
{
    int f = 0, c = 0;

    while(1) {
        c++;
        if (check[x%10] == 1) f = 1;
        x /= 10;
        if (x <= 0) break;
    }

    if (f == 1) return -1;
    else return c;
}

int main()
{
    int N, M, i, a, o;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= M; i++) {
        scanf("%d", &a);
        check[a] = 1;
    }

    dp1[100] = 0;
    dp2[100] = 0;
    if (N > 100) {
        for (i = 101; i <= N; i++) {
            o = chk(i);
            if (o == -1) {
                if (dp1[i-1] == -1) dp1[i] = -1;
                else dp1[i] = dp1[i-1]+1;
            }
            else {
                if (dp1[i-1]+1 < o && dp1[i-1] != -1) dp1[i] = dp1[i-1]+1;
                else dp1[i] = o;
            }
        }
        dp2[1000001] = -1;
        for (i = 1000000; i >= N; i--) {
            o = chk(i);
            if (o == -1) {
                if (dp2[i+1] == -1) dp2[i] = -1;
                else dp2[i] = dp2[i+1]+1;
            }
            else {
                if (dp2[i+1]+1 < o && dp2[i+1] != -1) dp2[i] = dp2[i+1]+1;
                else dp2[i] = o;
            }
        }

        if (dp1[N] < dp2[N] || dp2[N] == -1) printf("%d", dp1[N]);
        else printf("%d", dp2[N]);
    }
    else if (N == 100) printf("0");
    else {
        if (check[0] == 1) dp1[0] = -1;
        else dp1[0] = 1;
        for (i = 1; i <= N; i++) {
            o = chk(i);
            if (o == -1) {
                if (dp1[i-1] == -1) dp1[i] = -1;
                else dp1[i] = dp1[i-1]+1;
            }
            else {
                if (dp1[i-1]+1 < o && dp1[i-1] != -1) dp1[i] = dp1[i-1]+1;
                else dp1[i] = o;
            }
        }
        for (i = 99; i >= N; i--) {
            o = chk(i);
            if (o == -1) {
                if (dp2[i+1] == -1) dp2[i] = -1;
                else dp2[i] = dp2[i+1]+1;
            }
            else {
                if (dp2[i+1]+1 < o && dp2[i+1] != -1) dp2[i] = dp2[i+1]+1;
                else dp2[i] = o;
            }
        }
        if (dp1[N] < dp2[N] && dp1[N] != -1) printf("%d", dp1[N]);
        else printf("%d", dp2[N]);
    }

    return 0;
}
