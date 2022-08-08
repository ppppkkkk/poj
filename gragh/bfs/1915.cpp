#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
using namespace std;
/*
输入棋盘大小，输入国际象棋棋盘中的两个点，求马从一个点跳到另一个点的最少步数。
*/


int sx, sy, gx, gy, n, l;
int d[301][301], vis[301][301];
int dx[] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[] = { 2,-2,2,-2,1,-1,1,-1 };

void bfs() {
    queue<int> q;
    q.push(sx);//起始点入队
    q.push(sy);
    vis[sx][sy] = 1;
    while (!q.empty()) {
        int x = q.front(); 
        q.pop();
        int y = q.front(); 
        q.pop();
        if (x == gx && y == gy)//当到达终点时跳出函数
            break;
        for (int i = 0;i < 8;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!vis[nx][ny] && nx < l && nx >= 0 && ny >= 0 && ny < l) {//在边界内且未被标记
                q.push(nx);  
                q.push(ny);
                vis[nx][ny] = 1;
                d[nx][ny] = d[x][y] + 1;//步数加一
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &l);
        scanf("%d%d%d%d", &sx, &sy, &gx, &gy);//起点 终点
        memset(d, 0, sizeof(d)); 
        memset(vis, 0, sizeof(vis)); 
        bfs();
        printf("%d\n", d[gx][gy]);
    }
    return 0;
}

