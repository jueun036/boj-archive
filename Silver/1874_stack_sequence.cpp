// BOJ 1874 스택 수열 | 자료구조, 스택 | 2019-03-03 17:13:52
#include <stdio.h>

int a[200000], S1[200000], S2[200000], c1, ans[300000], c2;

void in1(int x)
{
    S1[++c1] = x;
}
void in2(int x)
{
    S2[++c2] = x;
}
void out()
{
    S1[c1--] = 0;
}
int main()
{
    int n, i, ca = 1;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    i = 1;
    int ansc = 0;
    while (i <= n) {
        if (S1[c1] == a[ca]) {
            in2(S1[c1]);
            out();
            ans[++ansc] = 1;
            ca++;
        }
        else {
            in1(i);
            i++;
            ans[++ansc] = 0;
        }
    }

    if (c1 != 0) {
        for (i = c1; i >= 1; i--) {
            in2(S1[c1]);
            out();
            ans[++ansc] = 1;
        }
    }
    int f = 0;
    for (i = 1; i <= n; i++) {
        if (S2[i] != a[i]) {
            f = 1;
            break;
        }
    }

    if (f == 0) {
        for (i = 1; i <= ansc; i++) {
            if (ans[i] == 0) printf("+\n");
            else printf("-\n");
        }
    }
    else printf("NO");

    return 0;
}
