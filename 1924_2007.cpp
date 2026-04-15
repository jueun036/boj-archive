// BOJ 1924 2007년 | 구현 | 2018-02-04 16:46:03
#include <stdio.h>

int main()
{
    int a, b;
    char day[8][5] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    scanf("%d %d", &a, &b);

    if (a == 1 || a == 10) printf("%s", day[b % 7]);
    else if (a == 2 || a == 3 || a == 11) printf("%s", day[(b+3)%7]);
    else if (a == 4 || a == 7) printf("%s", day[(b+6)%7]);
    else if (a == 5) printf("%s", day[(b+1)%7]);
    else if (a == 6) printf("%s", day[(b+4)%7]);
    else if (a == 8) printf("%s", day[(b+2)%7]);
    else if (a == 9 || a == 12) printf("%s", day[(b+5)%7]);

    return 0;
}
