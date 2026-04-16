// BOJ 2166 다각형의 면적 | 기하학, 신발끈 공식 | 2019-12-21 12:01:44
#include <stdio.h>

long long int x[10100];
long long int y[10100];


long long f(long long x)
{
    if (x < 0) return -x;
    return x;
}

int main()
{
    int N, i;
    long long int shoes = 0, firstx, firsty, ans = 0;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        scanf("%lld %lld", &x[i], &y[i]);
    }

    for(i=1;i<=N-1;i++){
        ans += x[i]*y[i+1];
        ans -= y[i]*x[i+1];
    }
    ans+=x[N]*y[1]; ans-=y[N]*x[1];
    ans = f(ans);

    printf("%lld", ans/2);
    if (ans%2 != 0) printf(".5");
    else printf(".0");

    return 0;
}
