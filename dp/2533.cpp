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
求最长上升子序列,序列不一定要连续,但是如果是求子串的情况就要求连续
*/




int dp[1111];
int a[1111];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0;i < n;i++)
			cin >> a[i];
		for (int i = 0;i < n;i++)
			dp[i] = 1;//每个以自己为结尾的序列最少有一个长度上升序列
		for (int i = 0; i < n; i++)//第一层循环，求以第i个元素为最后的最大上升序列
			for (int j = i + 1; j < n; j++)//第二层循环，在后面刷新序列
				if (a[i] < a[j])//举个例子理解下，如果数组为1 4 3 5 ，a[i] = 3,此时以i结尾的最大子序列为1 3，a[j] = 5，由于3 < 5，所以a[j] = a[i]+1，所以a[j] 的最大子序列为1 3 5
					dp[j] = max(dp[j], dp[i] + 1);
		int ans = 0;
		for (int i = 0;i < n;i++)
			ans = max(ans, dp[i]);//求以a[i]结尾的各各最大子序列中最大的那个
		cout << ans << endl;
	}
	return 0;
}


