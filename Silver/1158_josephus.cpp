// BOJ 1158 요세푸스 문제 | 자료구조, 큐 | 2018-07-10 22:38:01
#include <stdio.h>

int s[5001], o[5001];

int main()
{
    int n, m, c = 0, cnt = 0, f = 0, i;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= n; i++) {
        s[i] = i;
    }

    while(1) {
        for (i = 1; i <= n; i++) if (s[i] != 0){
            c++;
            if (c == m) {
                cnt++;
                o[cnt] = s[i];
                s[i] = c = 0;
                if (cnt == n)  {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 1) break;
    }

    printf("<");
    for (i = 1; i < n; i++) {
        printf("%d, ", o[i]);
    }
    printf("%d>", o[n]);

    return 0;
}
