//并查集优化
//路径压缩

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 10
char color[MAX_N];

int find(int i)
{
	int x = i;
	while (x != color[x]) x = color[x];
	color[i] = x;
	return x;
}

void merge(int m, int n)
{
	int mm = find(m), nn = find(n);
	if (mm != nn) color[nn] = mm;
	return;
}

void output()
{
	printf("\n");
	int len = 0;
	for (int i = 0; i < MAX_N; ++i) len += printf("%3d", i);
	printf("\n");
	while (len-- > 0) printf("-");
	printf("\n");
	for (int i = 0; i < MAX_N; ++i) printf("%3d", color[i]);
	printf("\n");
}

int main()
{
	for (int i = 0; i < MAX_N; ++i) {
		color[i] = i;
	}
	output();
	int a, b;
	while (~scanf("%d%d", &a, &b))
	{
		printf("merge %d and %d...\n", a, b);
		merge(a, b);
		output();
	}

	return 0;
}