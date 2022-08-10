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
输入单位为3的“-”的个数，接下来对这条线进行切割，每次切掉中间的三分之一，用空格替换，直到“-”的每一段长度为1，打印输出。
*/



char ans[1000001];

void dfs(int s, int e)
{
	int len;
	if (e - s == 1)
	{
		ans[s] = '-';
		return;
	}
	len = (e - s) / 3;
	dfs(s, s + len);  //对前三分之一进行递归 
	dfs(s + 2 * len, e); //对后三分之一进行递归
	//每次丢弃中间的三分之一
}

int main()
{
	int n, len;
	while (cin>>n)
	{
		len = pow(3 * 1.0, n);
		memset(ans, ' ', sizeof(ans));//对整个数组赋值为空格 
		dfs(0, len);
		for (int i = 0;i < len;i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
