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
给一个字符串，问你前缀和后缀相同的位置有哪些
KMP
next数组隐藏着一个规律，就是next[len]的值就是最大前缀后缀相同的个数
*/


char c[400001];
int Next[400001];
int ans[400001];

void solve(char* s, int len)
{
	int i = 0, j = -1;
	Next[0] = -1;
	while (i < len)
	{
		if (j == -1 || s[i] == s[j])
		{
			i++;
			j++;
			Next[i] = j;
		}
		else
		{
			j = Next[j];
		}
	}
}
int main()
{
	while (cin >> c)
	{
		memset(ans, 0, sizeof(ans));
		int i, j;
		ans[0] = strlen(c);
		i = 0;
		j = 1;
		solve(c, ans[0]);

		while (ans[i++])
		{
			ans[i] = Next[ans[i - 1]]; // 从长到短，递归查找前子串和后子串相等的子串
		}
		for (j = i - 2;j >= 0;j--)
		{
			cout << ans[j];
			if (j) 
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}
