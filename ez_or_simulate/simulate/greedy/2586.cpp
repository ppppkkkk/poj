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
已知一个公司在某一年中，(每个月要么固定盈利s、要么固定亏损d)。
但是具体哪个月盈利、那个月亏损却不得而知。
不过可以肯定的是，这一年中，(任意的连续5个月盈亏和必定是亏损（< 0）)。
问这年是否存在盈利的可能，若可能盈利，最大的盈利额是多少
列方程：s*x-y*d<0   
		y>5*s/(d+s)
y最小等于5*s/(d+s)+1
greedy
*/

int main()
{
	int s, d;
	int a[13];
	while (cin>>s>>d)
	{
		int sum = 0;
		int M = 5 * s / (d + s);
		if (s >= 4 * d)
		{
			cout << "Deficit" << endl;
			continue;
		}
		int y = M + 1;
		int x = 5 - y;
		for (int i = 1; i <= 5; i++)
		{
			if (i <= x)
			{
				a[i] = s;
			}
			else
			{
				a[i] = -d;
			}
			sum += a[i];
		}
		for (int i = 6; i <= 12; i++)
		{
			if (a[i - 5] == s)
				a[i] = s;
			else
				a[i] = -d;
			sum += a[i];
		}
		if (sum >= 0)
			cout << sum << endl;
		else
			cout << "Deficit" << endl;
	}
	return 0;

}
