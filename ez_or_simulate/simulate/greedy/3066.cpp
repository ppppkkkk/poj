#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
贪心
已知 m, p, a, b。x1, x2, ..., xm 满足图中公式。求x1^p + x2^p + … + xm^p 。
*/

int main()
{
	double m, p, a, b;
	while (scanf("%lf%lf%lf%lf", &m, &p, &a, &b) == 4) {
		double min_x = -1 / sqrt(a);
		double max_x = sqrt(a);
		double sum = b * sqrt(a);
		double tmp = m * sqrt(a);
		double left = tmp - sum;
		int num = (int)(left / (-min_x + max_x));
		int min_num = num;
		int max_num = m - num - 1;
		double mid_x = sum - min_num * min_x - max_num * max_x;
		printf("%d\n", int(min_num * pow(min_x, p) + max_num * pow(max_x, p) + pow(mid_x, p) + 0.5));
	}
	return 0;
}

