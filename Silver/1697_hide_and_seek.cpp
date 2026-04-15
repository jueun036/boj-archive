// BOJ 1697 숨바꼭질 | BFS, 그래프 | 2018-08-03 10:09:22
#include <stdio.h>

int q[199999], ch[200001];

int main()
{
    int n, k, a, b, c, d, s, e;

    scanf("%d %d", &n, &k);
    if (n == k) {
        printf("0");
        return 0;
    }
    q[1] = n;
    ch[n] = 1;
    s = 1;
    e = 2;

    while(s < e) {
        a = q[s]-1;
        b = q[s]+1;
        c = q[s]*2;
        d = q[s];
        if (a >= 0 && ch[a] == 0) {
            q[e] = a;
            ch[a] = ch[d]+1;
            if (a == k) {
                printf("%d", ch[d]);
                break;
            }
            e++;
        }
        if (b < 200001 && ch[b] == 0) {
            q[e] = b;
            ch[b] = ch[d]+1;
            if (b == k) {
                printf("%d", ch[d]);
                break;
            }
            e++;
        }
        if (c < 200001 && ch[c] == 0) {
            q[e] = c;
            ch[c] = ch[d]+1;
            if (c == k) {
                printf("%d", ch[d]);
                break;
            }
            e++;
        }
        s++;
    }

    return 0;
}
