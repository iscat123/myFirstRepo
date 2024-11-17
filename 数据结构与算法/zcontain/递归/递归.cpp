#include <iostream>
#include <vector>
using namespace std;

//数学归纳法：1.验证f(1)正确 2.假设f(n)正确，证明f(n+1)正确 3.通过步骤1和2可以得到f(1)成立，f(n)也就成立。
// 递归程序设计步骤：1.设计递归函数，并明确语义 2.设计边界条件 3.假设递归程序是正确的，来设计本层的实现。

//斐波那契数列
int feibn(int n)
{
	if (n <= 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;
	return feibn(n - 2) + feibn(n - 1);
}

void feibn_test()
{
	while (true)
	{
		int n;
		cin >> n;
		cout << "输出:" << feibn(n) << endl;
	}
}

//路飞吃桃
//递归程序设计步骤
//1.eatPeach(n)返回的是可以吃n天的桃子个数
//2.吃1天时，桃子只有一个 即eatPeach(1)=1;
//3.假设eatPeach(n-1)是n-1天吃的桃子数成立，那么n天吃的桃子数就等于(eatPeach(n-1)+1)*2;

int eatPeach(int day)
{
	if (day == 1)
		return 1;
	return (eatPeach(day - 1) + 1) * 2;
}

void test_eatPeach()
{
	//测试
	int day = 0;
	cin >> day;
	cout << "个数: " << eatPeach(day) << endl;
}

//弹簧板
//递归程序设计步骤
//1.tanhb(i)返回的是在i位置，被弹出需要的次数
//2.当位置i大于等于弹簧板个数n的时候(i从0开始)，被弹出的所需要的次数为0；
//3.假设tanhb(i+a[i])是在位置i+a[i]处被弹出所需要的次数，那么在位置i处被弹出的次数就等于tanhb(i+a[i])+1;
int tanhb(int i, int n, const vector<int>& arr)
{
	if (i >= n)
		return 0;
	return tanhb(i + arr[i], n, arr) + 1;
}

void test_tanhb()
{
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; ++i)
	{
		int a;
		cin >> a;
		arr.push_back(a);
	}
	cout << "次数：" << tanhb(0, n, arr);
}

//递归实现指数型枚举
//1.zhism(i,min,max),明确语义，输出当前位置i以及之后的所有指数型枚举
//2.边界条件：min>max 时 直接返回
//3.假设
void print(const vector<int>& arr, int index)
{
	for (int i = 0; i <= index; ++i)
	{
		cout << arr[i];
		if (i != index)
			cout << " ";
	}

}
void zhism(int i, int min, int max, vector<int>& arr)
{
	if (min > max)
		return;
	for (int k = min; k <= max; ++k)
	{
		arr[i] = k;
		print(arr, i);
		cout << endl;
		zhism(i + 1, k + 1, max, arr);
	}
}

void zhism_test()
{
	int max;
	cin >> max;
	vector<int> arr(10);
	zhism(0, 1, max, arr);
}

//递归实现组合型枚举
//zhuhm(index,min,max,iMax) 语义，输出当前位置index到iMax的所有组合型枚举
//i==n 输出 || min>=max 直接返回
//
void zhuhm(int index, int min, int max, int iMax, vector<int>& arr)
{
	if (index == iMax)
	{
		print(arr, index - 1);
		cout << endl;
		return;
	}
	if (min > max)
		return;
	for (int value = min; value <= max; ++value)
	{
		arr[index] = value;
		zhuhm(index + 1, value + 1, max, iMax, arr);
	}
}

void zhuhm_test()
{
	int max, iMax;
	cin >> max;
	cin >> iMax;
	vector<int> arr(iMax);
	zhuhm(0, 1, max, iMax, arr);
}

//排列型枚举
//1.pailm(index,arr,iMax) 语义从当前index到iMax直接所有的排序型枚举
//2.index==iMax输出
//3.
void pailm(int index, const vector<int>& arr, int iMax, vector<int>& rsl)
{
	if (index == iMax)
	{
		print(rsl, index - 1);
		cout << endl;
		return;
	}
	int arrCount = arr.size();
	for (int k = 0; k < arrCount; ++k)
	{
		rsl[index] = arr[k];
		vector<int> nextArr;
		for (int j = 0; j < arrCount; ++j)
		{
			if (arr[k] != arr[j])
				nextArr.push_back(arr[j]);
		}
		pailm(index + 1, nextArr, iMax, rsl);
	}
}

void pailm_test()
{
	int iMax;
	cin >> iMax;
	vector<int> arr, rsl(iMax);
	for (int i = 1; i <= iMax; ++i)
	{
		arr.push_back(i);
	}
	pailm(0, arr, iMax, rsl);
}

//主函数
int main()
{
	pailm_test();
	return 0;
}