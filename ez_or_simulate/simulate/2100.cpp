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
给出一个数，求一系列连续的数字使得它们的平方和等于这个数
尺取法
*/



int main()
{
	long long n;
	vector<pair<long, long>> ans;
	while (cin >> n) 
	{
		long long  L = 1, R = 1, sum = 0;
		while (L * L <= n) 
		{
			if (sum < n)
			{
				sum += R * R;
				R++;
			}
			else if (sum > n)
			{
				sum -= L * L;
				L++;
			}
			else 
			{
				ans.push_back(make_pair(L, R));
				sum += R * R;
				R++;
			}
			if (L == R) 
			{
				sum += R * R;
				R++;
			}
		}

		cout << ans.size() << endl;
		for (long long  i = 0; i < ans.size(); i++) 
		{
			cout << ans[i].second - ans[i].first << " ";
			for (long long  j = ans[i].first; j < ans[i].second; j++)
				cout << j << (j + 1 == ans[i].second ? '\n' : ' ');
		}
		ans.clear();
	}
	return 0;
}
