// BOJ 2602 돌다리 건너기 | DP | 2019-02-08 15:31:35
#include <stdio.h>
#include <string.h>

int D[3][30][200];
char st1[30], devil[200], angel[200];

int main()
{
    int len1, len2, i, j, k;

    scanf("%s %s %s", st1, devil, angel);

    len1 = strlen(st1);
    len2 = strlen(devil);

    for (i = 0; i < len2; i++) {
        if (st1[0] == devil[i]) {
            D[0][0][i] = 1;
        }
        if (st1[0] == angel[i]) {
            D[1][0][i] = 1;
        }
    }

    for (i = 0; i < len1; i++) {
        for (j = 0; j < len2; j++) {
            if (st1[i] == devil[j]) {
                for (k = j+1; k < len2; k++) {
                    if (st1[i+1] == angel[k]) {
                        D[1][i+1][k] += D[0][i][j];
                    }
                }
            }
        }
        for (j = 0; j < len2; j++) {
            if (st1[i] == angel[j]) {
                for (k = j+1; k < len2; k++) {
                    if (st1[i+1] == devil[k]) {
                        D[0][i+1][k] += D[1][i][j];
                    }
                }
            }
        }
    }

    int ans = 0;
    for (i = 0; i < len2; i++) {
        if (st1[len1-1] == devil[i]) {
            ans += D[0][len1-1][i];
        }
        if (st1[len1-1] == angel[i]) {
            ans += D[1][len1-1][i];
        }
    }

    printf("%d", ans);

    return 0;
}
