#include <cstdio> 
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
/*
poj 1315
在一个有着可以阻碍攻击的墙的棋盘上摆放车，使其相互之间不能攻击，输出能够摆放车的最大数量。
dfs 障碍八皇后
*/



char Map[6][6];
int visited[6][6];
int maxn, r, k;
bool place(int x, int y)
{
	for (int i = x + 1;i < k && Map[i][y] != 'X';i++)//往右找
		if (visited[i][y]) return false;
	for (int i = x - 1;i >= 0 && Map[i][y] != 'X';i--)//往左找
		if (visited[i][y]) return false;
	for (int i = y - 1;i >= 0 && Map[x][i] != 'X';i--)//往上找
		if (visited[x][i]) return false;
	for (int i = y + 1;i < k && Map[x][i] != 'X';i++)//往下找
		if (visited[x][i]) return false;
	return true;
}
void placed(int r)
{
	if (r > maxn) maxn = r;
	for (int i = 0;i < k;i++)
		for (int j = 0;j < k;j++)
			if (!visited[i][j] && Map[i][j] == '.' && place(i, j))
			{
				visited[i][j] = 1;
				placed(r + 1);
				visited[i][j] = 0;
			}
}
int main()
{
	while (cin >> k && k)
	{
		maxn = 0;
		memset(visited, 0, sizeof(visited));
		memset(Map, 0, sizeof(Map));
		for (int i = 0;i < k;i++)
			for (int j = 0;j < k;j++)
				cin >> Map[i][j];
		placed(0);
		cout << maxn << endl;
	}
	return 0;
}
