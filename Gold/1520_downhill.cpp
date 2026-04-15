// BOJ 1520 내리막 길 | DP, DFS | 2026-04-12 20:43:19
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int n, m;
int a[600][600];
int d[600][600];
int go_y[4] = {-1, 0, 1, 0};
int go_x[4] = {0, 1, 0, -1};
vector<tuple<int, int, int> > v;

bool cmp(tuple<int, int, int> x, tuple<int, int, int> y) {
    auto [ia, ja, numa] = x;
    auto [ib, jb, numb] = y;
    return numa > numb;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            v.push_back({i, j, a[i][j]});
        }
    }

    sort(v.begin(), v.end(), cmp);

    d[0][0] = 1;
    for (int i = 0; i < v.size(); i++) {
        auto [y, x, num] = v[i];
        for (int j = 0; j < 4; j++) {
            int yy = y + go_y[j];
            int xx = x + go_x[j];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m || a[yy][xx] <= a[y][x]) continue;
            d[y][x] += d[yy][xx];
        }
    }

    printf("%d", d[n - 1][m - 1]);

    return 0;
}
