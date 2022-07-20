#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

/*

给定一块正三角形棋盘，然后给定一些棋子和空位，棋子序号为a（1<=a<=9)，group的定义是相邻序号一样的棋子。

然后到C（1<=N<=9）棋手在空位放上自己序号C的棋子， 放完后， 不与空位相邻的group被消去， 每消去一个不是C的棋子得一分， 消去C的棋子扣一分， 问能得到最多的分数是多少。

分析：
令ans = 0；

搜索每一个棋子， 找出他的group。

如果这个group不与空位相邻， 而且棋子与棋手序号相等， 那么ans -= group数量， 如果棋子不与棋手序号相等 ans += group数量

可以不设置全局变量来找出搜索块的数量

*/
const int maxn= 15;
const int INF= 0x3f3f3f3f;

int n, c;
int bd[maxn][maxn];
bool vis[maxn][maxn];
int step[6][2]= {
	{-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, 0}, {1, 1}
};

int dfs(int x, int y)
{
	vis[x][y]= 1;
	if (!bd[x][y]){
		return 0;
	}
	int sm= 1;
	int flag= 0;

	for (int i= 0; i< 6; ++i){
		int nx= x+step[i][0], ny= y+step[i][1];
		if (!bd[nx][ny]){
			flag= 1;
		}
		if (bd[x][y]!= bd[nx][ny]){
			continue;
		}
		else if (!vis[nx][ny]){
			int tp= dfs(nx, ny);
			if (!tp){
				flag= 1;
			}
			sm+= tp;
		}
	}

	return flag ? 0 : sm;
}

int main(int argc, char const *argv[])
{
	memset(bd, -1, sizeof(bd));

	while (2== scanf("%d %d", &n, &c) && n){
		int ans= -INF;
		for (int i= 1; i<= n; ++i){
			for (int j= 1; j<= i; ++j){
				scanf("%d", bd[i]+j);
			}
		}
		memset(bd+n+1, -1, sizeof(bd[0]));

		for (int i= 1; i<= n; ++i){
			for (int j= 1; j<= i; ++j){
				if (!bd[i][j]){
					int tmp= 0;
					memset(vis, 0, sizeof(vis));
					bd[i][j]= c;

					for (int x= 1; x<= n; ++x){
						for (int y= 1; y<= x; ++y){
							if (vis[x][y]){
								continue;
							}
							if (c== bd[x][y]){
								tmp-= dfs(x, y);
							}
							else{
								tmp+= dfs(x, y);
							}
						}
					}
					bd[i][j]= 0;
					ans= max(ans, tmp);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
