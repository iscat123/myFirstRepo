#include <stdio.h>

//编程技巧：方向数组
#define MAX_N 1600
int arr[MAX_N + 5] = { 1600 };
int offserArr[8][2] = { {1,2}, {1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1} }; //方向数组
void dfs(int k,int x, int y, int n, int m)
{
	if (arr[(x - 1) * m + y] != -1 && k >= arr[(x - 1) * m + y]) return;
	arr[(x - 1) * m + y] = k;
	for (int i = 0; i < 8; ++i)
	{
		int dx = x + offserArr[i][0];
		int dy = y + offserArr[i][1];
		if (dx > m || dx < 1 || dy > n || dy < 1) continue;
		dfs(k + 1, dx, dy, n, m);
	}
}
int main()
{
	for (int i = 0; i < MAX_N + 5; i++) arr[i] = -1;
	int n, m, x, y;
	scanf_s("%d%d%d%d", &n, &m, &x, &y);
	dfs(0, x, y, n, m);
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			printf("%2d ", arr[(i - 1) * m + j]);
		}
		printf("\n");
	}
	return 0;
}