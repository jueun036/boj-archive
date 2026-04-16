// BOJ 1753 최단경로 | 그래프, 다익스트라 | 2019-01-19 12:15:24
#include <stdio.h>
#include <vector>

using namespace std;
struct ED{
    int v,w;
};
vector<ED>edge[20001];

int check[20001], dist[20001], h1[320001], h2[320001], c;

struct e
{
    int u, v, w;
}way[320001];
void change(int &a, int &b)
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
    int V, E, K, i, vc = 0;

    scanf("%d %d %d", &V, &E, &K);

    for (i = 1; i <= E; i++) {
        scanf("%d %d %d", &way[i].u, &way[i].v, &way[i].w);
        ED tmp;
        tmp.v = way[i].v;
        tmp.w = way[i].w;
        edge[way[i].u].push_back(tmp);
    }

    for (i = 1; i <= V; i++) {
        dist[i] = 220000;
    }

    dist[K] = 0;
    h1[1] = K;
    h2[1] = 0;
    c++;
    push(c);
    int x = K;
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
        vc++;
        for (i = 0; i < edge[x].size(); i++) {
            int nxt = edge[x][i].v, we = edge[x][i].w;
            if (check[nxt] == 0 && dist[nxt] > dist[x]+we) {
                dist[nxt] = dist[x]+we;
                c++;
                h1[c] = nxt;
                h2[c] = dist[nxt];
                push(c);
            }
        }
    }

    for (i = 1; i <= V; i++) {
        if (dist[i] > 200000) printf("INF\n");
        else printf("%d\n", dist[i]);
    }

    return 0;
}
