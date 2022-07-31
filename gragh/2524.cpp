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
有n个学生，对他们进行询问，得到m组结果，每组结果表示这两个人信同一个宗教
求最大的宗教数目
并查集 将m组数据挨个读入，进行合并，先寻找每个人的祖先，如果祖先不同，则进行合并。最后统计祖先是本身的个数
*/



int parent[50005];

int find(int x)
{
	if (parent[x] != x)
	{
		int root = find(parent[x]);
		return parent[x] = root;
	}
	else
		return x;
}
int main()
{
	int Case = 1;
	int n, m;
	while (cin>>n>>m , n,m)
	{
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
		int cnt = 0;
		for (int i = 0; i < m; i++)
		{
			int s1, s2;
			cin >> s1 >> s2;
			if (find(s1) != find(s2))
			{
				cnt++;
				parent[find(s1)] = find(s2);
			}

		}
		printf("Case %d: %d\n", Case++, n - cnt);
	}
	return 0;
}
