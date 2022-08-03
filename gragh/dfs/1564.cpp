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
/*
给定 n 个数字和一个正整数t ,要求在这n个数字中找出若干个数，使它们的和等于t ，然后输出所有这样的组合，注意输出的时候，严格地按照降序输出
*/


int t, n;
int a[14];          // 存储数字列表，如 4 , 3 , 2 , 2 , 1 , 1
int result[14];     // 存储结果数字列表，如 3 1
int succeed_flag;   // 1-找到解

void dfs(int len, int pos, int sum)
{
    if (sum == t)  // 结束条件
    {
        for (int i = 0;i < len;i++)
            if (!i)
                printf("%d", result[i]);
            else
                printf("+%d", result[i]);
        printf("\n");
        succeed_flag = 1;
        return;
    }
    int pre_value = -1; // 记录已经搜索的值，防止重复性搜索
    for (int i = pos;i < n;i++)
    {
        // 关键点：剪枝　
        if ((sum + a[i] <= t) && (a[i] != pre_value)) // 剪枝，防止搜索到pre_value
        {
            pre_value = a[i];
            result[len] = a[i];
            // 开启下一级搜索
            dfs(len + 1, i + 1, sum + a[i]);
        }
    }
}

int main()
{
    while (cin>>t>>n,n)
    {
        succeed_flag = 0;
        for (int i = 0;i < n;i++)
            scanf("%d", &a[i]);
        printf("Sums of %d:\n", t);
        dfs(0, 0, 0);   // 开启ＤＦＳ搜索
        if (!succeed_flag)
            printf("NONE\n");
    }
    return 0;
}
