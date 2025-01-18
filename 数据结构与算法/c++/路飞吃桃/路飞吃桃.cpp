#include <stdio.h>

int arr[10];
int test(int n)
{
	if (n == 1) return 1;
	return (test(n - 1) + 1) * 2;
}
int test02(int i, int n)
{
	if (i  > n) return 0;
	return 1 + test02(i + arr[i], n);
}
void printf_one(int i)
{
	for (int k = 0; k <= i; ++k)
	{
		printf("%d  ", arr[k]);
	}
	printf("\n");
}
void test02(int i, int j, int n)
{
	if (j > n) return;
	for (int k = j; k <= n; ++k)
	{
		arr[i] = k;
		printf_one(i);
		test02(i + 1, k + 1, n);
	}
}
void test03(int i, int j, int m, int n)
{
	if (i >= n)
	{
		printf_one(n - 1);
		return;
	}
	for (int k = j; k <= m; ++k)
	{
		arr[i] = k;
		test03(i + 1, k + 1,m, n);
	}
}
int main()
{
	int m,n;
	scanf_s("%d%d", &m, &n);
	test03(0, 1, m, n);
	return 0;
}