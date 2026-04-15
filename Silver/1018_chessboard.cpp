// BOJ 1018 체스판 다시 칠하기 | 브루트포스 | 2020-10-03 10:52:30
#include <stdio.h>

int chess[100][100];

int main()
{
    int N, M, i, j, k, l, cnt1, cnt2, ans = 999;
    char st[100];

    scanf("%d %d", &N, &M);

    for (i = 1; i <= N; i++) {
        scanf("%s", &st);
        for (j = 0; j < M; j++) {
            if (st[j] == 'W') chess[i][j+1] = 1;
            else chess[i][j+1] = 0;
        }
    }

    for (i = 1; i <= N; i++) if (i <= N-7) {
        for (j = 1; j <= M; j++) if (j <= M-7) {
            cnt1 = cnt2 = 0;
            for (k = i; k <= i + 7; k++) {
                for (l = j; l <= j + 7; l++) {
                    if ((k - i) % 2 == (l - j) % 2) {
                        if (chess[k][l] == 0) cnt1++;
                        else cnt2++;
                    }
                    else {
                        if (chess[k][l] == 0) cnt2++;
                        else cnt1++;
                    }
                }
            }
            if (cnt1 < cnt2 && ans > cnt1) {
                ans = cnt1;
            }
            else if (cnt1 >= cnt2 && ans > cnt2) {
                ans = cnt2;
            }
        }
    }

    printf("%d", ans);

    return 0;
}