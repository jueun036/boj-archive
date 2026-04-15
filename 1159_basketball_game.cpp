// BOJ 1159 농구 경기 | 문자열, 구현 | 2019-07-09
#include <stdio.h>
#include <string.h>

int ans[200], cnt[200];
char st[200][50];

int main()
{
    int n, i, f;

    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        scanf("%s", st[i]);
    }

    for (i = 1; i <= n; i++) {
        cnt[st[i][0]-'a'+1]++;
    }

    f = 0;
    for (i = 1; i <= 26; i++) {
        if (cnt[i] >= 5) f = 1;
    }

    if (f == 1) {
        for (i = 1; i <= 26; i++) {
            if (cnt[i] >= 5) printf("%c", i+'a'-1);
        }
    }
    else printf("PREDAJA");

    return 0;
}
