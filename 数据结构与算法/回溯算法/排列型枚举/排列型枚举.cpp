#include <stdio.h>

#define MAX_N 10
int arr[MAX_N + 5];
int rslArr[MAX_N + 5];

void print_one(int n)
{
	printf("\n");
	for (int i = 1; i <= n; ++i) {
		printf("%3d", rslArr[i]);
	}
}
void dfs(int k, int n)
{
	if (k > n) {
		print_one(n);
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) continue;
		rslArr[k] = i;
		arr[i] = 0;
		dfs(k + 1, n);
		arr[i] = 1;
	}
}
int main()
{
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i <= n; ++i) arr[i] = 1;
	dfs(1, n);

	return 0;
}