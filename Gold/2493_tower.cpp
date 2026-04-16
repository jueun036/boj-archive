// BOJ 2493 탑 | 스택 | 2019-03-02 11:41:52
#include <stdio.h>

int a[600000], S1[600000], S2[600000], c;

void out()
{
    S1[c] = 0;
    S2[c] = 0;
    c--;
}

void in(int a, int i)
{
    c++;
    S1[c] = a;
    S2[c] = i;
}
int main()
{
    int n, i;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        while(1) {
            if (c == 0 || S1[c] > a[i]) {
                in(a[i], i);
                break;
            }
            else {
                out();
            }
        }
        printf("%d\n", S2[c-1]);
    }

    return 0;
}
