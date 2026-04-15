// BOJ 1916 최소비용 구하기 | 다익스트라 | 2019-12-07 00:41:36
#include <stdio.h>
#include <vector>

using namespace std;

struct EG{
    int e,v;
};

struct X
{
    int s, e, v;
} G[320001];

vector<EG>edge[20100];

long long int dist[1100];
int check[20001];
long long int h1[320001];
long long int h2[320001];
int c;

void change(long long int &a, long long int &b)
{
    int o = a; a = b; b = o;
}

void pop(int x)
{
    if (x*2 > c) return;
    if (x*2+1 > c) {
        if (h2[x] < h2[x*2]) return;
        else {
            change(h1[x], h1[x*2]);
            change(h2[x], h2[x*2]);
            pop(x*2);
        }
    }
    else {
        if (h2[x] > h2[x*2] || h2[x] > h2[x*2+1]) {
            if (h2[x*2] > h2[x*2+1]) {
                change(h1[x], h1[x*2+1]);
                change(h2[x], h2[x*2+1]);
                pop(x*2+1);
            }
            else {
                change(h1[x], h1[x*2]);
                change(h2[x], h2[x*2]);
                pop(x*2);
            }
        }
        else return;
    }
}

void push(int x)
{
    if (x == 1) return;
    if (h2[x] < h2[x/2]) {
        change(h1[x], h1[x/2]);
        change(h2[x], h2[x/2]);
        push(x/2);
    }
    else return;
}

int main()
{
    int N, M, i, vec = 0, start, en;

    scanf("%d %d", &N, &M);

    for (i = 1; i <= M; i++) {
        scanf("%d %d %d", &G[i].s, &G[i].e, &G[i].v);
        EG O;
        O.e = G[i].e;
        O.v = G[i].v;
        edge[G[i].s].push_back(O);
    }

    scanf("%d %d", &start, &en);

    for (i = 1; i <= N; i++) {
        dist[i] = 999999999999;
    }

    dist[start] = 0;
    h1[1] = start;
    h2[1] = 0;
    c++;
    push(c);
    int x = start;
    while(c>0) {
        if (check[h1[1]] == 1) {
            change(h1[1], h1[c]);
            change(h2[1], h2[c]);
            c--;
            pop(1);
            continue;
        }
        else x = h1[1];
        check[x] = 1;
        vec++;
        for (i = 0; i < edge[x].size(); i++) {
            long long int aaa = edge[x][i].e, bbb = edge[x][i].v;
            if (check[aaa] == 0 && dist[aaa] > dist[x]+bbb) {
                dist[aaa] = dist[x]+bbb;
                h1[++c] = aaa;
                h2[c] = dist[aaa];
                push(c);
            }
        }
    }

    printf("%lld", dist[en]);

    return 0;
}
