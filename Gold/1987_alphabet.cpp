// BOJ 1987 알파벳 | 그래프 탐색, DFS, 백트래킹 | 2026-04-12 04:35:31
#include <iostream>
#include <string>
#include <climits>
using namespace std;

int r, c;
string alpha[30];
int check[100] = {0};
int go_y[4] = {-1, 0, 1, 0};
int go_x[4] = {0, 1, 0, -1};
int maxx = INT_MIN;


void dfs(int y, int x, int cnt) {
    if (cnt > maxx) maxx = cnt;

    for (int i = 0; i < 4; i++) {
        int yy = y + go_y[i];
        int xx = x + go_x[i];
        if (yy < 0 || yy >= r || xx < 0 || xx >= c) continue;
        if (check[alpha[yy][xx] - 'A'] == 1) continue;
        check[alpha[yy][xx] - 'A'] = 1;
        dfs(yy, xx, cnt + 1);
        check[alpha[yy][xx] - 'A'] = 0;
    }
}

int main() {
    scanf("%d %d", &r, &c);

    for (int i = 0; i < r; i++) {
        cin >> alpha[i];
    }

    check[alpha[0][0] - 'A'] = 1;
    dfs(0, 0, 1);

    printf("%d", maxx);

    return 0;
}
