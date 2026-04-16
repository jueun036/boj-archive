// BOJ 1927 최소 힙 | 우선순위 큐, 힙 | 2018-12-06 22:22:59
#include <stdio.h>

int h[100001], c;

void change(int &a,int &b)
{
    int o = a;
    a = b;
    b = o;
}

void pop(int x)
{
    if (x*2 > c) return;
    if (x*2+1 > c) {
        if (h[x] > h[x*2]) {
            change(h[x*2], h[x]);
            pop(x*2);
        }
    }
    else {
        if (h[x] > h[x*2] || h[x] > h[x*2+1]) {
            if (h[x*2] > h[x*2+1]) {
                change(h[x*2+1], h[x]);
                pop(x*2+1);
            }
            else {
                change(h[x*2], h[x]);
                pop(x*2);
            }
        }
        else return;
    }
}
void push(int x)
{
    if (x != 1) {
        if (h[x/2] > h[x]) {
            change(h[x/2], h[x]);
            push(x/2);
        }
    }

}
int main()
{
    int n, i, a;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%d", &a);
        if (a == 0) {
            if (c == 0) printf("0\n");
            else {
                change(h[1], h[c]);
                printf("%d\n", h[c]);
                h[c] = 0;
                c--;
                pop(1);
            }
        }
        else {
            c++;
            h[c] = a;
            push(c);
        }
    }

    return 0;
}
