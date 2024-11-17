#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ( (a) > (b) ? (b) : (a) )
//函数 即x->y的映射规则
double fun(double x)
{
	if (x > 0)     x -=  min(x, 3000) * 0.03;
	if (x > 3000)  x -= (min(x, 12000) - 3000) * 0.1;
	if (x > 12000) x -= (min(x, 25000) - 12000) * 0.2;
	if (x > 25000) x -= (min(x, 35000) - 25000) * 0.25;
	if (x > 35000) x -= (min(x, 55000) - 35000) * 0.3;
	if (x > 55000) x -= (min(x, 80000) - 55000) * 0.35;
	if (x > 80000) x -= (x - 80000) * 0.45;
	return x;
}

double binary_algorithm(double x)
{
	double head = 0, tail = 1000000, mid = (head + tail) / 2.0;
	while (tail - head > 1e-4)
	{
		if (fun(mid) > x) tail = mid;
		else head = mid;
		mid = (head + tail) / 2;
	}
	return head;
}

int main()
{
	double x;
	while (~scanf_s("%lf", &x))
		printf("f(%lf)=%.2lf", x, binary_algorithm(x));
	return 0;
}