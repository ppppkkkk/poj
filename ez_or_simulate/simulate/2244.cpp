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
给议会议员照相，议会人太多，照片不够大，只照的进一部分人，给出一个排列，问这是第几种排列。
议会共有n个人（编号1~n），照片装得下k个人，（n、k键盘输入）。排列按编号的字典序
*/



int main()
{//n：总共有多少人k：一张照片里有多少人a[20]：存给出照片状态 
	int t, n, k, a[20], ans, sum;//ans：最终结果sum：中间结果 
	scanf("%d", &t);//t：testcase、i，i2，j：计数器 
	for (int j = 1;j <= t;j++)
	{
		ans = 0;
		scanf("%d%d", &n, &k);
		for (int i = 0;i < k;i++)
			scanf("%d", &a[i]);
		for (int i = 0;i < k;i++)
		{
			sum = a[i] - 1;
			for (int i2 = n - i - 1;i2 >= n - k + 1;i2--)//
				sum *= i2;
			ans += sum;
			for (int i2 = i + 1;i2 < k;i2++)
			{
				if (a[i2] > a[i])a[i2]--;
			}
		}
		printf("Variace cislo %d ma poradove cislo %d.\n", j, ans + 1);
	}
	return 0;
}
