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
输入K门课程，m中选课策略，接下来输入k个数字，表示课程编号，接下来输入m组数，
每组包括课程的数量c，必须选的可能的最小值r，接下来c个数是课程编号，问Freddie满不满足要求
*/





int main() {
	int a[101],b[101];
	int k, m, r, c;
	//k：已经选择的科目数；m：选择的科目类别；c：能够选择的科目数。r：要求最少选择的科目数量
	while (cin>>k,k)
	{
		int flag = 0;
		cin >> m;
		for (int i = 0;i < k;i++)
			cin >> a[i];
		while (m--)
		{
			int count = 0;
			cin >> c >> r;
			for (int i = 0;i < c;i++)
				cin >> b[i];
			for (int i = 0;i < k;i++)
			{
				for (int j = 0;j < c;j++)
				{
					if (a[i] == b[j])
						count++;
				}
			}
			if (count < r)
			{
				flag = 1;
			}
		}
		if (flag)
			cout << "no" << endl;
		else
			cout << "yes" << endl;
	}
	return 0;
}
