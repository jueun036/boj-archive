// BOJ 2668 숫자고르기 | 그래프 탐색, DFS | 2019-12-28 11:50:38
#include <stdio.h>

int N;
int A[200];
int check1[200];
int check2[200];
int ans[200];

int gr(int x, int c, int first)
{
    check2[x] = 1;
    if (A[first] == first) return 1;
    if (x == A[x]) return -1;
    else if (first == A[x]) return c;
    else if (check1[A[x]] == 1 || check2[A[x]] == 1 || A[x] > N) return -1;
    else {
        return gr(A[x], c+1, first);
    }
}

int main()
{
    int i, j, sum = 0;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    for (i = 1; i <= N; i++) {
        if (check1[i] == 1) continue;
        int o = gr(i, 1, i);
        if (o != -1) {
            sum += o;
            for (j = 1; j <= N; j++) {
                if (check2[j] == 1) {
                    ans[j] = 1;
                    check1[j] = 1;
                }
            }
        }
        for (j = 1; j <= N; j++) check2[j] = 0;
    }

    printf("%d\n", sum);

    for (i = 1; i <= N; i++) {
        if (ans[i] == 1) printf("%d\n", i);
    }

    return 0;
}
