// BOJ 1157 단어 공부 | 문자열, 구현 | 2018-06-09 23:55:33
#include <stdio.h>
#include <string.h>

char ch[1000001];
int c[100];

int main()
{
    int i, len, max = 0, maxi, cnt = 0;

    scanf("%s", ch);
    len = strlen(ch);

    for (i = 0; i <= len; i++) {
        if (ch[i] >= 97) {
            c[ch[i]-32]++;
        }
        else {
            c[ch[i]]++;
        }
    }

    for (i = 65; i <= 90; i++) {
        if (max < c[i]) {
            max = c[i];
            maxi = i;
        }
    }
    for (i = 65; i <= 90; i++) {
        if (max == c[i]) {
            cnt++;
        }
    }
    if (cnt >= 2) printf("?");
    else printf("%c", maxi);
    return 0;
}
