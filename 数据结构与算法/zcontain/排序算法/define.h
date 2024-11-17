#ifndef _DEFINE_H
#define _DEFINE_H

#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

#define MAX_N 100
#define swap(a,b) {\
	int c=a;\
	a=b;\
	b=c;\
}


extern void output(const vector<int>& arr);
extern bool check(const vector<int>& arr);

#endif
