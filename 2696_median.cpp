// BOJ 2696 중앙값 구하기 | 자료구조, 우선순위 큐 | 2020-01-04 11:34:46
#include <stdio.h>

int h1[10100];
int h2[10100];
int a[10100];
int c1, c2;

void change(int &a, int &b)
{
	int o = a; a = b; b = o;
}
void pop1(int x)
{
	if (x*2 > c1) return;
	if (x*2+1 > c1) {
		if (h1[x] < h1[x*2]) return;
		else {
			change(h1[x], h1[x*2]);
			pop1(x*2);
		}
	}
	else {
		if (h1[x] > h1[x*2] || h1[x] > h1[x*2+1]) {
			if (h1[x*2] > h1[x*2+1]) {
				change(h1[x], h1[x*2+1]);
				pop1(x*2+1);
			}
			else {
				change(h1[x], h1[x*2]);
				pop1(x*2);
			}
		}
		else return;
	}
}

void pop2(int x)
{
	if (x*2 > c2) return;
	if (x*2+1 > c2) {
		if (h2[x] > h2[x*2]) return;
		else {
			change(h2[x], h2[x*2]);
			pop2(x*2);
		}
	}
	else {
		if (h2[x] < h2[x*2] || h2[x] < h2[x*2+1]) {
			if (h2[x*2] > h2[x*2+1]) {
				change(h2[x], h2[x*2]);
				pop2(x*2);
			}
			else {
				change(h2[x], h2[x*2+1]);
				pop2(x*2+1);
			}
		}
		else return;
	}
}

void push1(int x)
{
	if (x == 1) return;
	if (h1[x] < h1[x/2]) {
		change(h1[x], h1[x/2]);
		push1(x/2);
	}
	else return;
}

void push2(int x) {
	if (x == 1) return;
	if (h2[x] > h2[x/2]) {
		change(h2[x], h2[x/2]);
		push2(x/2);
	}
	else return;
}
int main()
{
	int T, M, i, j, mid;

	scanf("%d", &T);

	for (i = 1; i <= T; i++) {
		scanf("%d", &M);
		for (j = 1; j <= M; j++) {
			scanf("%d", &a[j]);
		}
		c1 = c2 = 0;
		if (M == 1) printf("%d\n%d\n", 1, a[1]);
		else {
			printf("%d\n%d ", M/2+1, a[1]);
			mid = a[1];
			for (j = 2; j <= M; j++) {
				if (mid < a[j]) {
					h1[++c1] = a[j];
					push1(c1);
				}
				else {
					h2[++c2] = a[j];
					push2(c2);
				}
				if (j % 2 == 1) {
					if (c1 > c2) {
						h2[++c2] = mid;
						push2(c2);
						printf("%d ", h1[1]);
						mid = h1[1];
						change(h1[1], h1[c1]);
						c1--;
						pop1(1);
					}
					else if (c1 == c2) {
						printf("%d ", mid);
					}
					else {
						h1[++c1] = mid;
						push1(c1);
						printf("%d ", h2[1]);
						mid = h2[1];
						change(h2[1], h2[c2]);
						c2--;
						pop2(1);
					}
				}
			}
			printf("\n");
		}
	}

	return 0;
}
