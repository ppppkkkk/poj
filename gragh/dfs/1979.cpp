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
在一个长方形的区域，有黑色和红色两种方块，一个人站在一块黑色的方块上，他可以向四个方向移动，
但是每次移动只能移动到另一个黑色的方块上，问共有多少黑色的方块。
'.' - a black tile
'#' - a red tile
'@' - a man on a black tile
*/

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int vis[21][21];
int ans;
char ch[21][21];
int n, m;
void dfs(int x, int y)
{
	ans++;
	vis[x][y] = 1;
	for (int i = 0;i < 4;i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && vis[nx][ny] != 1 && ch[nx][ny] == '.')
			dfs(nx, ny);
	}
}
int main()
{
	while (cin >> m >> n, n , m )
	{
		ans = 0;
		memset(vis, 0, sizeof(vis));
		for (int i = 0;i < n;i++)
			cin >> ch[i];
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				if (ch[i][j] == '@' && !vis[i][j])
				{
					dfs(i, j);
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
