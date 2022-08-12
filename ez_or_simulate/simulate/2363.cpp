#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*

*/


int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, h, area, min = 0x7fffffff;
		scanf("%d", &n);
		for (int i = 1;i <= n;i++)//长
		{
			for (int j = 1;i * j <= n;j++)//宽
			{
				if (n % (i * j) == 0)
				{
					h = (n / i) / j;//高
					area = (i * j + i * h + j * h) * 2;//面积
					if (area < min)//取最小值
						min = area;
				}
				else
					continue;
			}
		}
		printf("%d\n", min);
	}
	return 0;
}
