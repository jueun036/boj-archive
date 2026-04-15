// BOJ 1188 음식 평론가 | 수학, 정수론 | 2019-10-05 10:26:31
#include <stdio.h>

int main()
{
    int N, M, i, cnt = 0;

    scanf("%d %d", &N, &M);

    for (i = 0; i <= N*M; i += N) {
        if (i % M != 0) cnt++;
    }

    printf("%d", cnt);

    return 0;
}
