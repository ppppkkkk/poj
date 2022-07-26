#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

/*
给你一个5*5的矩阵，求从任意一个位置出发，可以组成多少个不同的6位数
dfs
*/






int map[6][6];
int dir[4][2] = { {0,1},{0,-1},
					{1,0},{-1,0} };

set <int> ans;//自动去重
//x横y纵
//step当前第几个数字或步数
//len数字长度
void dfs(int x, int y, int step, int len)
{
	int dx, dy;
	if (x < 1 || y < 1 || x>5 || y>5)
		return;
	if (step == 6)
	{
		ans.insert(len);
		return;
	}
	for(int i = 0;i < 4;i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		step++;
		dfs(dx, dy, step, len * 10 + map[dx][dy]);
		step--;
	}
}
int main()
{
	for (int i = 1;i <= 5;i++)
		for (int j = 1;j <= 5;j++)
			scanf("%d", &map[i][j]);
	for (int i = 1;i <= 5;i++)
		for (int j = 1;j <= 5;j++)
			dfs(i, j, 1, map[i][j]);
	printf("%d\n", ans.size());
	return 0;
}
