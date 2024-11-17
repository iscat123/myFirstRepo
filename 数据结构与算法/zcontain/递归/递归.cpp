#include <iostream>
#include <vector>
using namespace std;

//��ѧ���ɷ���1.��֤f(1)��ȷ 2.����f(n)��ȷ��֤��f(n+1)��ȷ 3.ͨ������1��2���Եõ�f(1)������f(n)Ҳ�ͳ�����
// �ݹ������Ʋ��裺1.��Ƶݹ麯��������ȷ���� 2.��Ʊ߽����� 3.����ݹ��������ȷ�ģ�����Ʊ����ʵ�֡�

//쳲���������
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
		cout << "���:" << feibn(n) << endl;
	}
}

//·�ɳ���
//�ݹ������Ʋ���
//1.eatPeach(n)���ص��ǿ��Գ�n������Ӹ���
//2.��1��ʱ������ֻ��һ�� ��eatPeach(1)=1;
//3.����eatPeach(n-1)��n-1��Ե���������������ôn��Ե��������͵���(eatPeach(n-1)+1)*2;

int eatPeach(int day)
{
	if (day == 1)
		return 1;
	return (eatPeach(day - 1) + 1) * 2;
}

void test_eatPeach()
{
	//����
	int day = 0;
	cin >> day;
	cout << "����: " << eatPeach(day) << endl;
}

//���ɰ�
//�ݹ������Ʋ���
//1.tanhb(i)���ص�����iλ�ã���������Ҫ�Ĵ���
//2.��λ��i���ڵ��ڵ��ɰ����n��ʱ��(i��0��ʼ)��������������Ҫ�Ĵ���Ϊ0��
//3.����tanhb(i+a[i])����λ��i+a[i]������������Ҫ�Ĵ�������ô��λ��i���������Ĵ����͵���tanhb(i+a[i])+1;
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
	cout << "������" << tanhb(0, n, arr);
}

//�ݹ�ʵ��ָ����ö��
//1.zhism(i,min,max),��ȷ���壬�����ǰλ��i�Լ�֮�������ָ����ö��
//2.�߽�������min>max ʱ ֱ�ӷ���
//3.����
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

//�ݹ�ʵ�������ö��
//zhuhm(index,min,max,iMax) ���壬�����ǰλ��index��iMax�����������ö��
//i==n ��� || min>=max ֱ�ӷ���
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

//������ö��
//1.pailm(index,arr,iMax) ����ӵ�ǰindex��iMaxֱ�����е�������ö��
//2.index==iMax���
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

//������
int main()
{
	pailm_test();
	return 0;
}