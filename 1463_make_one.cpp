// BOJ 1463 1로 만들기 | DP | 2018-06-24 16:52:18
#include <stdio.h>

int D[1000001]={0, 0, 1, 1};
int main()
{
    int n, i, min = 99999;

    scanf("%d", &n);

    for (i = 4; i <= n; i++) {
        min = 99999;
        if (D[i-1] < min) min = D[i-1];
        if (i % 2 == 0) {
            if (D[i/2] < min) min = D[i/2];
        }
        if (i % 3 == 0) {
            if (D[i/3] < min) min = D[i/3];
        }
        D[i] = min+1;
    }

    printf("%d", D[n]);
    return 0;
}
