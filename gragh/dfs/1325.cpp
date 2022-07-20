#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 510;
int Left, Right;//left是匹配左边的顶点数，right是匹配右边的顶点数
int g[MAXN][MAXN];//邻接矩阵
int linker[MAXN];//存右点对象（linker[i]表示和女生i匹配的男生的编号） 
int vis[MAXN];//右点是否访问过



/*
题意：两台机器可以工作。各有n个和m个工作模式。皆标记为0、1、2、3、...... 、n（m）
给出k个任务，每个任务在两台机器上都可以完成，其分别在两台机器上完成需要对应的工作模式为（i，j）
表示在第一台机器上工作需要模式i，第二台机器上工作需要模式 j 。
机器初始为0工作状态。每一次改变工作状态需要重启。
求，完成所有工作最少重启几次。

在二分图中求最少的点，让每条边都至少和其中的一个点关联，这就是二分图的最小顶点覆盖，（最小定点覆盖就是用最少的点覆盖所有的边）
二分图的最小定点覆盖数=二分图的最大匹配数
*/


int dfs(int l)
{
	for (int r = 0;r < Right;r++)
	{
		if (g[l][r] && !vis[r])//左边到右边有边，并且右边该点未访问 
		{
			vis[r] = 1;
			if (linker[r] == -1 || dfs(linker[r]))
				//如果右边的点还未匹配 或者 与该点匹配的左边的点可以找到另一个右点与其匹配，那么返回1 
				//该女生没有对象  或者  该女生的男朋友可以找到另一个对象  该女生就和该男生匹配，匹配数加一 
			{
				linker[r] = l;
				return 1;
			}
		}
	}
	return 0;
}

//匈牙利算法
int hungary()
{
	int res = 0;
	memset(linker, -1, sizeof(linker));
	for (int l = 0;l < Left;l++)//n趟dfs 
	{
		memset(vis, 0, sizeof(vis));//防止单次dfs重复搜 
		if (dfs(l)) res++;
	}
	return res;
}

int main()
{
	int k;
	while (cin >> Left && Left)
	{
		cin >> Right >> k;
		memset(g, 0, sizeof(g));
		int id, lnum, rnum;
		while (k--)
		{
			cin >> id >> lnum >> rnum;
			if (lnum != 0 && rnum != 0)//等于0，不需要切换，可以直接完成 
			{
				g[lnum][rnum] = 1;
			}
		}
		cout << hungary() << endl;
	}
	return 0;
}
