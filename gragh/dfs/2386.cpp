#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
char gragh[105][105];
int dir[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1} };

/*
poj 2386
有一个大小为N*M的园子，雨后起了水。八连通的积水都被认为是连接在一起的。
请求出园子里总共有多少水洼？（八连通指的是下图中相对W的*部分）
dfs/bfs
*/
void dfs(int x, int y)
{
	gragh[x][y] = '.';//将所在位置替换为.
	for (int i = 0;i < 8;i++)//移动八个方向
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && gragh[dx][dy] == 'W')
		{
			dfs(dx,dy);
		}
	}

}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0;i < n; i++)
        scanf("%s", gragh[i]);
    int ans = 0;
    for (int i = 0;i < n; i++)
        for (int j = 0;j < m; j++)
            if (gragh[i][j] == 'W') {
                dfs(i, j);
                ans++;
            }
    printf("%d\n", ans);
    return 0;
}
