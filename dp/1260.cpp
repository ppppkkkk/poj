#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;


/*

有c个种品质不同的珍珠，若要买某一品质的珍珠必须在你买的数量的基础上，多付10个这种珍珠的价钱，可以用高品质的珍珠代替低品质的。
求要买到所有目标珍珠至少要花多少钱。数据保证按珍珠的价钱由低到高输入

dp[i]:代表采购前i种珍珠所需要花费的最小价格，当要采购第i+1种时，有两种情况:
一种是只有第i+1种取第i+1个价格，那么dp[i+1]=dp[i]+(num[i+1]-num[i]+10)*p[i+1];
另一种是第j种珍珠到第i+1种珍珠都取第i+1个价格，那么dp[i+1]=dp[j]+(num[i+1]-num[j]+10)*p[i+1]);这两种情况取最小值即可。

*/



int num[105], p[105], t, dp[105];
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		int c;
		scanf("%d", &c);
		for (int i = 1;i <= c;i++)
		{
			scanf("%d%d", &num[i], &p[i]);
			num[i] = num[i - 1] + num[i];
		}
		memset(dp, 0, sizeof(dp));
		for (int i = 0;i < c;i++)
		{
			dp[i + 1] = dp[i] + (num[i + 1] - num[i] + 10) * p[i + 1];
			for (int j = 0;j < i;j++)
			{
				dp[i + 1] = min(dp[i + 1], dp[j] + (num[i + 1] - num[j] + 10) * p[i + 1]);
			}
		}
		printf("%d\n", dp[c]);
	}
	return 0;
}
