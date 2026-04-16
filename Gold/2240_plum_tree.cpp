// BOJ 2240 자두나무 | DP | 2019-01-29 21:36:55
#include <stdio.h>

int a[1001], D[1001][31];

int main()
{
    int T, W, i, j;

    scanf("%d %d", &T, &W);

    for (i = 1; i <= T; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 1; i <= T; i++) {
        for(j = 0; j <= W; j++) {
            if (j % 2 == 0) {
                if (a[i] == 1) {
                    if (i-1 < 1) D[i][j] = D[i-1][j]+1;
                    else {
                        if (j-1 < 0) D[i][j] = D[i-1][j]+1;
                        else {
                            if (D[i-1][j-1] > D[i-1][j]+1) D[i][j] = D[i-1][j-1];
                            else D[i][j] = D[i-1][j]+1;
                        }
                    }
                }
                else {
                    if (i-1 < 1) D[i][j] = D[i-1][j];
                    else {
                        if (j-1 < 0) D[i][j] = D[i-1][j];
                        else {
                            if (D[i-1][j-1]+1 > D[i-1][j]) D[i][j] = D[i-1][j-1]+1;
                            else D[i][j] = D[i-1][j];
                        }
                    }
                }
            }
            else {
                if (a[i] == 1) {
                    if (i-1 < 1) D[i][j] = D[i-1][j];
                    else {
                        if (j-1 < 0) D[i][j] = D[i-1][j];
                        else {
                            if (D[i-1][j-1]+1 > D[i-1][j]) D[i][j] = D[i-1][j-1]+1;
                            else D[i][j] = D[i-1][j];
                        }
                    }
                }
                else {
                    if (i-1 < 1) D[i][j] = D[i-1][j]+1;
                    else {
                        if (j-1 < 0) D[i][j] = D[i-1][j]+1;
                        else {
                            if (D[i-1][j-1] > D[i-1][j]+1) D[i][j] = D[i-1][j-1];
                            else D[i][j] = D[i-1][j]+1;
                        }
                    }
                }
            }
        }
    }

    int mx = 0;

    for (i = 0; i <= W; i++) {
        if (mx < D[T][i]) mx = D[T][i];
    }

    printf("%d", mx);

    return 0;
}
