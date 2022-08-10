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
主人过生日，F个人来给他庆生，但是只有N个Pizza，现在要将N个Pizza分给F+1个人（包括主人自己），
问每个人能分到Pizza的最大体积是多少，要求每个人所分的Pizza只能是从一个Pizza上切下来的，不可以用好多小块拼凑成体积相同的Pizza。
*/

#define PI acos(-1.0)

int pie[10001];

int main()
{
	int Case = 0;
	scanf("%d", &Case);
	int pizzaNum = 0;
	int personNum = 0;

	while (Case--)
	{
		scanf("%d%d", &pizzaNum, &personNum);
		int maxvalue = 0;
		for (int i = 0; i < pizzaNum; ++i)
		{
			scanf("%d", &pie[i]);
			pie[i] *= pie[i];//圆形r方
			maxvalue = maxvalue < pie[i] ? pie[i] : maxvalue;
		}
		double low = 0;
		double high = maxvalue;
		double mid = 0;
		while (high-low>1e-5)//重要！
		{
			int sum = 0;
			mid = low + (high - low) / 2;
			for (int i = 0; i < pizzaNum; ++i)
			{
				if (pie[i] > mid)//因为每份pizza只能从一个pizza上切下来
				{
					sum += (int)(pie[i] / mid);//计算按照当前的pizza面积mid来划分所能分给的人数
				}
			}
			if (sum >= personNum + 1)
				low = mid;
			else
				high = mid;
		}
		printf("%.4lf\n", mid * PI);
	}
	return 0;
}
