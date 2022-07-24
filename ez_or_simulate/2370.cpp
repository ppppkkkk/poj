#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
/*
有K组选民,每组有超过一半人投票有效,最终综合K组投票情况得出投票结果。 问最少需要多少人投赞成可使提案通过
过半的组员合格则这个组合格，过半的组合格则这个队伍合格
输出这个队伍合格所需要的最少的合格人数
*/

int f[110];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &f[i]);
    sort(f, f + n);//组从小到大
    int ans = 0;
    for (int i = 0; i < n / 2 + 1; i++)
        ans += f[i] / 2 + 1;//每组一半人
    printf("%d\n", ans);
    return 0;
}
