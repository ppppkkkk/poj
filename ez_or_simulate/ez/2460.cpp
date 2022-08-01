#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;

/*
给n个点，判断他们相对于第n/2+1个点的位置关系。
*/


int x[200001], y[200001];

int main()
{
	int n;
	while (cin >> n, n) {
		int sum1 = 0, sum2 = 0, t = n / 2 + 1;
		for (int i = 1;i <=n;++i)
			scanf("%d%d", &x[i], &y[i]);
		for (int i = 1;i <= n;++i)
			if ((x[i] > x[t] && y[i] > y[t]) || (x[i] < x[t] && y[i] < y[t]))
				++sum1;
			else if ((x[i] > x[t] && y[i] < y[t]) || (x[i]<x[t] && y[i]>y[t]))
				++sum2;
		printf("%d %d\n", sum1, sum2);
	}
	return 0;

}
