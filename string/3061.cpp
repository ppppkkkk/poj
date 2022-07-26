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
给长度为N的数组和一个整数S，
求总和不小于S的连续子序列的最小长度
尺取算法：
初始化左右端点，即先找到一个满足条件的序列。
在满足条件的基础上不断扩大左端点。
如果第二步无法满足条件则终止，否则更新结果。
扩大右端点，并且回到第二步。
*/



int a[100001];
int main()
{	
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int N, S;
		scanf("%d%d", &N, &S);
		for (int i = 0;i < N;i++)
			scanf("%d", &a[i]);
		int l = 0, r = 0;//左右边界
		int ans = N + 1, sum = 0;
		while (1)
		{
			while (r < N && sum < S)
				sum += a[r++];
			if (sum < S)break;
			ans = min(ans, r - l);
			sum -= a[l++];
		}
		if (ans == N + 1)
			printf("0\n");
		else 
			printf("%d\n", ans);
	}
	return 0;
}
