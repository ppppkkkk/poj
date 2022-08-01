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
给N个数字，从1到N，然后按照字面的顺序重新排列。例如：
2 3 4 5 1
[1] [2] [3] [4] [5]
–>
5 1 2 3 4
[1] [2] [3] [4] [5]
判断新旧顺序是否一样
*/


int a[100005];
int main()
{
	int n;
	while (cin>>n,n)
	{
		int flag = 1;
		for (int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		for (int i = 1;i <= n;i++)
		{
			if (a[a[i]] != i)
			{
				flag = 0;
				break;
			}
		}
		if (!flag)
			printf("not ambiguous\n");
		else
			printf("ambiguous\n");
	}
	return 0;
}

