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

const int INF = 0x3f3f3f3f;
int n, m;
char ma[101][101];
int visited[101][101];
int dis[8][2] = { 1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1 };
void dfs(int x, int y) 
{
    int dx, dy;
    visited[x][y] = 1;
    for (int i = 0;i < 8;i++) {
        dx = x + dis[i][0];
        dy = y + dis[i][1];
        if (ma[dx][dy] == '@' && !visited[dx][dy] && dx >= 0 && dx <= n && dy >= 0 && dy <= m)
            dfs(dx, dy);
    }
    return;
}
int main() 
{
    int sum;
    while (cin>>n>>m, n, m) 
    {
        for (int i = 0;i < n;i++)
            scanf("%s", ma[i]);
        memset(visited, 0, sizeof(visited));
        sum = 0;
        for (int i = 0;i < n;i++)
            for (int j = 0;j < m;j++)
                if (visited[i][j] == 0 && ma[i][j] == '@') 
                {
                    dfs(i, j);
                    sum++;
                }
        printf("%d\n", sum);
    }
    return 0;
}
