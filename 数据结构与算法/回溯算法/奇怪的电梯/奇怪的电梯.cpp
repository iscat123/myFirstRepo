#include<stdio.h>

////没有剪枝
//int rsl = 100;
//int arr[20];
//void dfs(int s, int e, int ans, int n)
//{
//	if (s == e) {
//		if (rsl > ans)
//			rsl = ans;
//		return;
//	}
//	if (s + arr[s] <= n) dfs(s + arr[s], e, ans + 1, n);
//	if (s - arr[s] >= 1) dfs(s - arr[s], e, ans + 1, n);
//}
//int main()
//{
//	int n, a, b;
//	scanf_s("%d%d%d", &n, &a, &b);
//	for (int i = 1; i <= n; i++) {
//		scanf_s("%d", arr+i);
//	}
//	dfs(a, b, 0, n);
//	printf("%d", rsl);
//}
 

//优化：历史答案剪枝
int arr[20];
int min[20];
void dfs(int f, int step, int n)
{
	if (min[f] <= step)
		return;
	min[f] = step;
	if (f + arr[f] <= n) dfs(f + arr[f], step + 1, n);
	if (f - arr[f] >= 1) dfs(f - arr[f], step + 1, n);
}
int main()
{
	int n, a, b;
	scanf_s("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		scanf_s("%d", arr+i);
		min[i] = 100;
	}
	dfs(a, 0, n);
	printf("%d", min[b]);
}