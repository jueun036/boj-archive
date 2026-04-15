// BOJ 1094 막대기 | 비트마스크 | 2018-06-17 15:45:24
#include <stdio.h>

int stick[70] = {0, 64};

int main()
{
    int x, sum = 0, c = 1, mini, i, min = 9999999;

    scanf("%d", &x);

    if (x == 64) {
        printf("1");
        return 0;
    }
    while(1) {
        for (i = 1; i <= c; i++) {
            if (min > stick[i]) {
                min = stick[i];
                mini = i;
            }
        }
        stick[mini] = stick[mini] / 2;

        for (i = 1; i <= c; i++) sum += stick[i];
        if (sum < x) {
            c++;
            stick[c] = stick[mini];
        }
        else if (sum == x){
            printf("%d", c);
            return 0;
        }
        sum = 0;
    }

    return 0;
}