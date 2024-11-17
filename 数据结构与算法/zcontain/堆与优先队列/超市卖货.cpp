#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;
typedef struct Data {
	int p, d;
	Data(int p,int d):p(p),d(d){}
	bool operator<(const Data& data)
	{
		if (d == data.d)
			return p > data.p;
		return d<data.d;
	}
}Data;

int main()
{
	int n;
	cin >> n;
	vector<Data> arr;
	for (int i = 0; i < n; ++i)
	{
		int p, d;
		cin >> p >> d;
		arr.push_back(Data(p, d));
	}
	sort(arr.begin(), arr.end());
	set<PII> pSet;
	int tot = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (pSet.size() < arr[i].d) pSet.insert(PII(arr[i].p, tot++));
		else
		{
			if (pSet.begin()->first < arr[i].p)
			{
				pSet.erase(pSet.begin());
				pSet.insert(PII(arr[i].p, tot++));
			}
		}
	}
	int all = 0;
	for (PII data : pSet)
	{
		all += data.first;
	}
	cout << "price:" << all;
}