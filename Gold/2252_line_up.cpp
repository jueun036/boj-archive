// BOJ 2252 줄 세우기 | 위상 정렬 | 2018-10-20 15:54:09
#include <stdio.h>
#include <vector>
#include <deque>
using namespace std;
int q[100001], A[100001], B[100001], in[100001];

vector<int>edge[100001];
deque<int>Q;

int main()
{
    int n, m, i, j;

    scanf("%d %d", &n, &m);

    for (i = 1; i <= m; i++) {
        scanf("%d %d", &A[i], &B[i]);
        in[B[i]]++;
        edge[A[i]].push_back(B[i]);
    }

    for (i = 1; i <= n; i++) {
        if (in[i] == 0) {
            Q.push_back(i);
        }
    }
    while(!Q.empty()){
        int now = Q.front();Q.pop_front();
        printf("%d ", now);
        for(int j=0;j<edge[now].size();j++){
            int next = edge[now][j];
            in[next]--;
            if(in[next]==0){
                Q.push_back(next);
            }
        }
    }

    return 0;
}
