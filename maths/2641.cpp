#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
在b*a的区域打台球，初始位置在中点，s秒之后，与水平边撞击n次，与垂直边撞击m次，并回到中点，求球的初速度与角度。

球的水平速度设为Vx，那么s秒后水平路程为Vx*s，与垂直边撞击m次又回到中点，由此得到水平路程为m*a，于是Vx*s=m*a，同理Vy*s=n*b，两式联立得答案。
*/

const double pi = acos(-1.0);
int main()
{
	double a, b, s, m, n, v, th;
	while (scanf("%lf%lf%lf%lf%lf", &a, &b, &s, &m, &n), (a || b || s || m || n))
	{
		th = atan2(n * b, m * a);
		v = sqrt(m * m * a * a + n * n * b * b) / s;
		printf("%.2lf %.2lf\n", th * 180.0 / pi, v);
	}
	return 0;
}
