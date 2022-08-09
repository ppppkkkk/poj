#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
求图的最长路径，这里的最长路径是指每条边只能经过一次，但是点可以经过很多次的那种。
*/


int s[25][25];
int gmax, pmax, vis[25][25];
int n, m;
void dfs(int x) {
    int flag = 1;
    for (int i = 0;i < n;++i) {
        if (s[x][i] && !vis[x][i]) {
            ++pmax;
            flag = 0;
            vis[x][i] = 1;
            vis[i][x] = 1;
            dfs(i);
            vis[x][i] = 0;
            vis[i][x] = 0;
            --pmax;
        }
    }
    if (flag && gmax < pmax) gmax = pmax;
}
int main() {
    while (scanf("%d%d", &n, &m) == 2 && n) {
        memset(s, 0, sizeof(s));
        gmax = pmax = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0;i < m;++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            s[x][y] = 1;s[y][x] = 1;
        }
        for (int i = 0;i < n;++i) 
            dfs(i);
        printf("%d\n", gmax);
    }
    return 0;
}
