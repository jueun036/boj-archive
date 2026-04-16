// BOJ 2450 모양 정돈 | 정렬, 브루트포스 | 2019-11-16 20:21:38
#include <stdio.h>

int N;
int a[100100];
int b[100100];
int im[100100];
int check[10][10];
int ans = 99999999;

void sort(int s, int e)
{
	if (s == e) return;
	int m, c1, c2, i;
	m = (s+e)/2; c1 = s; c2 = m+1;
	sort(s, m); sort(m+1, e);

	for (i = s; i <= e; i++) {
		if ((c1 <= m && c2 <= e && b[c1] < b[c2]) || (c1 <= m && c2 > e)) {
			im[i] = b[c1++];
		}
		else im[i] = b[c2++];
	}
	for (i = s; i <= e; i++) {
		b[i] = im[i];
	}
}

int answer()
{
	int i, j, ans1 = 0, ans2 = 0;

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			if (i == j) check[i][j] = 0;
			else if (check[i][j] == 0) continue;
			else {
				if (check[j][i] > check[i][j]) {
					check[j][i] -= check[i][j];
					ans1 += check[i][j];
					check[i][j] = 0;
				}
				else {
					check[i][j] -= check[j][i];
					ans1 += check[j][i];
					check[j][i] = 0;
				}
			}
		}
	}

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			ans2 += check[i][j];
		}
	}

	return ans1+(ans2/3)*2;
}

void zero()
{
	int i, j;

	for (i = 1; i <= 3; i++) {
		for (j = 1; j <= 3; j++) {
			check[i][j] = 0;
		}
	}
}

void xxx()
{
	int i, x;

	for (i = 1; i <= N; i++) b[i] = a[i];
	sort(1, N);
	for (i = 1; i <= N; i++) check[b[i]][a[i]]++;
	x = answer();
	if (ans > x) ans = x;
}

int main()
{
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &a[i]);
	}

	xxx();

	zero();
	for (i = 1; i <= N; i++) {
		if (a[i] == 1) continue;
		else if (a[i] == 2) a[i] = 3;
		else a[i] = 2;
	}
	xxx();

	zero();
	for(i = 1; i <= N; i++) {
		if (a[i] == 1) a[i] = 2;
		else if (a[i] == 2) a[i] = 3;
		else a[i] = 1;
	}
	xxx();

	zero();
	for (i = 1; i <= N; i++) {
		if (a[i] == 1) a[i] = 3;
		else if (a[i] == 2) continue;
		else a[i] = 1;
	}
	xxx();

	zero();
	for (i = 1; i <= N; i++) {
		if (a[i] == 1) a[i] = 2;
		else if (a[i] == 2) a[i] = 3;
		else a[i] = 1;
	}
	xxx();

	zero();
	for (i = 1; i <= N; i++) {
		if (a[i] == 1) a[i] = 2;
		else if (a[i] == 2) a[i] = 1;
		else continue;
	}
	xxx();

	printf("%d", ans);

	return 0;
}
