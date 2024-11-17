#include<iostream>
#include<queue>
using namespace std;

int getMin(int a, int b, int c)
{
	int tmp = a > b ? b : a;
	tmp = tmp > c ? c : tmp;
	return tmp;
}
int main_test03()
{
	queue<int> s1, s2, s3;
	s1.push(-1);
	s1.push(0);
	s1.push(9);
	s2.push(-25);
	s2.push(-10);
	s2.push(10);
	s2.push(11);
	s3.push(2);
	s3.push(9);
	s3.push(17);
	s3.push(30);
	s3.push(41);
	int min = 999999;
	while (!s1.empty() && !s2.empty() && !s3.empty())
	{
		int a = s1.front(), b = s2.front(), c = s3.front();
		int len = abs(a - b) + abs(a - c) + abs(b - c);
		if (len < min)
			min = len;
		int lost = getMin(a, b, c);
		if (lost == a)
			s1.pop();
		else if (lost == b)
			s2.pop();
		else
			s3.pop();
	}
	cout << min;
	return 0;
}