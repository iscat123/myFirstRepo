#include<iostream>
#include<vector>
#include<deque>
using namespace std;

//��������
//����˼·��ǰ׺�ͣ�S(ij) = Si - Sj;��ʾ�����±�j��i�����к�
//��ԭ����ת����ǰ׺��

void outputarr(vector<int>& arr)
{
	printf("\n");
	int len = 0;
	for (int i = 0, I = arr.size(); i < I; i++)
	{
		len += printf("%3d", i);
	}
	printf("\n");
	while (len--)printf("-");
	printf("\n");
	for (int i = 0, I = arr.size(); i < I; i++)
	{
		len += printf("%3d", arr[i]);
	}
	printf("\n");
}

int main()
{
	int m, n, x, sum = 0;
	cin >> m >> n;
	vector<int> arr, sumArr;
	for (int i = 0; i < m; i++) {
		cin >> x;
		arr.push_back(x);
		sum += x;
		sumArr.push_back(sum);
	}
	outputarr(arr);
	outputarr(sumArr);
	deque<int> q;
	int max = sumArr[0];
	for (int i = 0; i < m - 1; ++i) {
		while (!q.empty() && sumArr[q.back()] > sumArr[i]) {
			q.pop_back();
		}
		q.push_back(i);
		if (i - n == q.front()) q.pop_front();
		if (max < sumArr[i + 1] - sumArr[q.front()])
			max = sumArr[i + 1] - sumArr[q.front()];
	}
	return 0;
}