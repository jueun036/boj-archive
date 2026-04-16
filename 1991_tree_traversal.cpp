// BOJ 1991 트리 순회 | 트리, DFS | 2018-11-11 00:03:45
#include <stdio.h>

int L[30], R[30];

void tree1(int s)
{
    if (s == '.') return;

    printf("%c", s);
    tree1(L[s]);
    tree1(R[s]);
}
void tree2(int s)
{
    if (s == '.') return;

    tree2(L[s]);
    printf("%c", s);
    tree2(R[s]);
}
void tree3(int s)
{
    if (s == '.') return;

    tree3(L[s]);
    tree3(R[s]);
    printf("%c", s);
}
int main()
{
    int n, i;
    char v1, v2, v3;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf(" %c %c %c", &v1, &v2, &v3);
        L[v1] = int(v2);
        R[v1] = int(v3);
    }

    tree1('A');
    printf("\n");
    tree2('A');
    printf("\n");
    tree3('A');

    return 0;
}
