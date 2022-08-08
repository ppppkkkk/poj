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
给定 n 堆石子，每回合有两个操作：
①选择一堆不为 0 的石堆取走至少一块石子；
②取走后从这堆石子中剩下的选取任意移到其它任意不为0的石堆(这步操作可选可不选)；
若无法进行步骤①则算败，问先手是否必胜；
*/

vector<int>s;

int main()
{
	int n;
	while (cin>>n,n) {
		s.clear();
		for (int i = 0;i < n;i++) 
		{
			int x;
			cin >> x;
			s.push_back(x);
		}
		if (n & 1)//奇数个 
		{
			puts("1");
			continue;
		}
		sort(s.begin(), s.end());
		int flag = 0;
		for (int i = 0;i < n;i += 2) //偶数
		{
			if (s[i] != s[i + 1]) 
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			puts("1");
		else 
			puts("0");
	}
}
