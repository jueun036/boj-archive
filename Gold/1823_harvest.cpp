// BOJ 1823 수확 | DP | 2026-04-13 13:29:09
#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int n;
int v[2005];
long long int d[2005][2005] = {0};

int main() {
    int s, e;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= 1; j--) {
            if (i > j) continue;
            if (i == 1 || j == n) {
                if (i == 1 && j == n) continue;
                else if (i == 1) d[i][j] = d[i][j + 1] + (v[j + 1] * (i + n - j - 1));
                else if (j == n) d[i][j] = d[i - 1][j] + (v[i - 1] * (i + n - j - 1));
            } else {
                if (d[i - 1][j] + (v[i - 1] * (i - 1 + n - j)) > d[i][j + 1] + (v[j + 1] * (i + n - j - 1)))
                    d[i][j] = d[i - 1][j] + (v[i - 1] * (i - 1 + n - j));
                else d[i][j] = d[i][j + 1] + (v[j + 1] * (i + n - j - 1));
            }
        }
    }

    long long int maxx = LONG_LONG_MIN;
    for (int i = 1; i <= n; i++) {
        if (maxx < d[i][i] + v[i] * n) maxx = d[i][i] + v[i] * n;
    }

    printf("%lld", maxx);

    return 0;
}
