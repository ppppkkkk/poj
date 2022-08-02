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
给你n个数，让你找出一个子序列，子序列计算的规则是：奇数次运算则加上这个数，偶数次运算就减去这个数。

求这个子序列的最大值。
*/

int a[150001];

int main()
{
    int n;
    int flag;
    int ans;
    while (~scanf("%d", &n))
    {
        ans = 0;
        flag = 0;
        for (int i = 1;i <= n;i++)
            scanf("%d", &a[i]);
        for (int i = 1;i <= n;i++)
        {
            if (a[i] >= a[i - 1] && a[i] >= a[i + 1] && flag == 0)
            {
                ans += a[i];
                flag = 1;
            }
            if (a[i] <= a[i - 1] && a[i] <= a[i + 1] && flag == 1)
            {
                ans -= a[i];
                flag = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
