#include<stdio.h>
#include<unordered_map>
using namespace std;
//1.搜索数与排列型枚举一致
//2.优化1：状态压缩 （用二进制数代替数组）
//3.优化2：快速枚举 最小的可用数 = -t&t
//4.优化4：斜边表示 正斜边 = i + j - 1; 反斜边 = i - j + N;

#define MASK(n) ((1<<(n+1))-2)  //状态压缩
unordered_map<int, int> map;
int arr[20];
void printf_one(int n)
{
	for (int i = 1; i <= n; ++i)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");
}
int dfs(int i, int t1, int t2, int t3, int n)
{
	if (i > n)
	{
		printf_one(n);
		return 1;
	}
	int ans = 0;
	for (int t = t1; t; t -= (-t & t)) {
		int j = map[-t & t];
		if (((1 << (i + j - 1)) & t2) && ((1 << (i - j + n)) & t3))
		{
			arr[i] = j;
			ans += dfs(i + 1, t1 ^ (1 << j), t2 ^ (1 << (i + j - 1)), t3 ^ (1 << (i - j + n)), n);
		}
	}
	return ans;
}

int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < 2 * n; ++i) map[1 << i] = i;
	int ans = dfs(1, MASK(n), MASK(2 * n - 1), MASK(2 * n - 1), n);
	printf("%d", ans);
	return 0;
}