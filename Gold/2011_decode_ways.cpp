// BOJ 2011 암호코드 | DP | 2019-01-26 11:18:42
#include <stdio.h>
#include <string.h>

int sn[5001], D[5001];
char st[5001];

int main()
{
    int i, len;

    scanf("%s", st+1);
    len = strlen(st+1);

    for (i = 1; i <= len; i++) {
        sn[i] = st[i]-48;
    }
    D[0] = 1;
    for (i = 1; i <= len; i++) {
        if(i>0&&10<=sn[i-1]*10+sn[i]&&sn[i-1]*10+sn[i]<=26)D[i]+=D[i-2];
        if(sn[i]!=0)D[i]+=D[i-1];
        D[i]%=1000000;
    }

    printf("%d", D[len]);

    return 0;
}
