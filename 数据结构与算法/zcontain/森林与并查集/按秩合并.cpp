//有权Quick_Union
//并查集优化
//按秩合并

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N 10
char color[MAX_N];
char weight[MAX_N];

int find(int i)
{
	while (i != color[i]) i = color[i];
	return i;
}

int getWeight(int i)
{
	return weight[i];
}

void merge(int m, int n)
{
	int mm = find(m), nn = find(n);
	int mWidget = getWeight(mm), nWidget = getWeight(nn);
	if (mm != nn) {
		if (mWidget >= nWidget) {
			color[nn] = mm;
			weight[mm] = mWidget >= (nWidget + 1) ? mWidget : (mWidget + 1);
		}
		else {
			color[mm] = nn;
			weight[nn] = nWidget >= (mWidget + 1) ? nWidget : (nWidget + 1);
		}
	}
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
		weight[i] = 1;
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