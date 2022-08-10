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
给定一个长度为k的数列，数列中的每个数都不相同且递增，现在要从数列中选出6个数字，按字典序递增输出所有的选择。（6<k<13）
dfs
*/



int ans[7];
int n;
int a[50];
int k, q = 0;
void dfs(int dep, int t)
{
    if (dep == 7)
    {
        for (int i = 1;i <= 6;i++)
        {
            if (i == 6)
                printf("%d", ans[i]);
            else
                printf("%d ", ans[i]);
        }
        puts("");
        q = 1;
        return;
    }
    for (int i = t;i <= n;i++)
    {
        ans[dep] = a[i];
        dfs(dep + 1, i + 1);
    }
}
int main()
{
    while (cin>>n, n)
    {
        if (q) puts("");
        for (int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        dfs(1, 1);
    }
    return 0;
}
