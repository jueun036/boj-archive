// BOJ 2206 벽 부수고 이동하기 | 그래프 탐색, BFS | 2026-04-12 03:31:19
#include <iostream>
#include <string>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int> > q;
int n, m;
string a[1100];
int step[1100][1100][2];
int go_y[4] = {-1, 0, 1, 0};
int go_x[4] = {0, 1, 0, -1};

int main() {
    int i, j, x, y;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            step[i][j][0] = -1;
            step[i][j][1] = -1;
        }
    }

    q.push({0, 0, 0});
    step[0][0][0] = 1;
    while (!q.empty()) {
        auto [y, x, broken] = q.front();
        q.pop();
        int xx, yy;
        for (int i = 0; i < 4; i++) {
            yy = y + go_y[i];
            xx = x + go_x[i];
            if (yy < 0 || yy >= n || xx < 0 || xx >= m) continue;
            if (a[yy][xx] == '0') {
                if (step[yy][xx][broken] != -1) continue;
                step[yy][xx][broken] = step[y][x][broken] + 1;
                q.push({yy, xx, broken});
            } else {
                if (broken == 1) continue;
                if (step[yy][xx][1] != -1) continue;
                step[yy][xx][1] = step[y][x][broken] + 1;
                q.push({yy, xx, 1});
            }
        }
    }

    int ans1 = step[n - 1][m - 1][0];
    int ans2 = step[n - 1][m - 1][1];

    if (ans1 == -1 && ans2 == -1) printf("-1");
    else if (ans1 == -1) printf("%d", ans2);
    else if (ans2 == -1) printf("%d", ans1);
    else printf("%d", min(ans1, ans2));

    return 0;
}
