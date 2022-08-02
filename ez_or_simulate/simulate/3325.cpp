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
去掉最高分 最低分 求平均分
*/
int main()
{
	int n;
	int a[101];
	while (cin>>n,n)
	{
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int sum = 0;
		for (int i = 1; i < n - 1; i++)
			sum += a[i];
		sum =sum/ (n - 2);
		cout << sum << endl;
	}
	return 0;
}
