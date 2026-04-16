// BOJ 1966 프린터 큐 | 구현, 큐, 시뮬레이션 | 2018-07-15
#include <stdio.h>
#include <algorithm>
#define M 109
using namespace std;

int n, m, s[M], v[M], ans[M];

int main()
{
    int T, i, j;

    scanf("%d", &T);

    while(T--) {
        scanf("%d %d" ,&n, &m);
        for (i = 0; i < n; i++) {
            scanf("%d", &s[i]);
            v[i] = s[i];
        }
        sort(s, s+n);
        for (j = 0; j < n; j++) ans[j] = 0;
        j = 0;
        for (i = n-1; i >= 0; i--) {
            while(s[i] != v[j] || ans[j]) j=(j+1)%n;
            ans[j] = n-i;
        }
        printf("%d\n", ans[m]);
    }

    return 0;
}
