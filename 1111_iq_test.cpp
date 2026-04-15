// BOJ 1111 IQ Test | 구현, 수학 | 2026-04-13 12:34:53
#include <iostream>
#include <cstdio>
using namespace std;

int n;
int num[100];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    if (n <= 2) {
        if (n == 2 && num[0] == num[1]) printf("%d", num[0]);
        else printf("A");
        return 0;
    }

    if (num[0] == num[1]) {
        for (int i = 0; i < n - 1; i++) {
            if (num[i] != num[i + 1]) {
                printf("B");
                return 0;
            }
        }
        printf("%d", num[0]);
        return 0;
    }

    if ((num[1] - num[2]) % (num[0] - num[1]) != 0) {
        printf("B");
        return 0;
    }

    int a, b;
    a = (num[1] - num[2]) / (num[0] - num[1]);
    b = num[1] - a * num[0];

    for (int i = 0; i < n - 1; i++) {
        if (num[i] * a + b != num[i + 1]) {
            printf("B");
            return 0;
        }
    }
    printf("%d", num[n - 1] * a + b);

    return 0;
}
