// BOJ 1004 어린 왕자 | 수학(기하) | 2020-10-03 17:54:11
#include <stdio.h>

int cx[100];
int cy[100];
int cr[100];
int check1[100];
int check2[100];

int cal(int a, int b)
{
    if (a > b) return (a - b) * (a - b);
    return (b - a) * (b - a);
}

int main()
{
    int T, N, i, j, k, v, ans;
    int x1, x2, y1, y2;

    scanf("%d", &T);

    for (i = 1; i <= T; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &N);
        for (j = 1; j <= N; j++) {
            scanf("%d %d %d", &cx[j], &cy[j], &cr[j]);
        }
        for (j = 1; j <= N; j++) {
            v = cal(cx[j], x1) + cal(cy[j], y1);
            if (v < cr[j] * cr[j]) {
                check1[j] = 1;
            }
            v = cal(cx[j], x2) + cal(cy[j], y2);
            if (v < cr[j] * cr[j]) {
                check2[j] = 1;
            }
        }
        ans = 0;
        for (j = 1; j <= N; j++) {
            if (check1[j] == 1 && check2[j] == 0) ans++;
            else if (check1[j] == 0 && check2[j] == 1) ans++;
            check1[j] = check2[j] = 0;
        }

        printf("%d\n", ans);
    }
}
