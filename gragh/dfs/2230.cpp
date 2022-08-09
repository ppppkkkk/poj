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
一个无向图，要求找一条路径，走过每一条边恰好两次，且每次走的方向不同。
很容易就能想到把这图转化为有向图求欧拉回路。题目保证一定能找到从1点出发回到1点的答案
*/


struct node
{
    int to, vis;
};

vector<node> v[50001];

void dfs(int x)
{
    for (int i = 0;i < v[x].size();i++)
    {
        if (!v[x][i].vis)
        {
            v[x][i].vis = 1;
            dfs(v[x][i].to);
        }
    }
    cout << x << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
    {
        int x, y;
        cin >> x >> y;
        node a, b;
        a.to = y;
        a.vis = 0;
        b.to = x;
        b.vis = 0;
        v[x].push_back(a);
        v[y].push_back(b);
    }
    dfs(1);
}
