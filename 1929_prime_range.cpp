// BOJ 1929 소수 구하기 | 수학, 에라토스테네스의 체 | 2018-02-25 15:07:40
#include <stdio.h>

int s[4000001] = {1};

int main()
{
    int a, b, i, j;

    scanf("%d %d", &a, &b);
    for (i = 2; i <= b; i++) s[i] = 1;
    for (i = 2; i <= b; i++) {
        if (s[i] != 0) {
            for (j = i*2; j <= b; j+=i) {
                s[j] = 0;
            }
            if (i >= a) printf("%d\n", i);
        }
    }

    return 0;
}
