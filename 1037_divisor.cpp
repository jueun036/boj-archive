// BOJ 1037 약수 | 수학 | 2018-05-06 14:50:03
#include <stdio.h>

int s[55];

void change(int n)
{
    int i, j, x;

    for (i = 1; i <= n; i++) {
        for (j = i + 1; j <= n; j++) {
            if (s[i] > s[j]) {
                x = s[i];
                s[i] = s[j];
                s[j] = x;
            }
        }
    }
}
int main()
{
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    change(n);
    printf("%d", s[1] * s[n]);

    return 0;
}