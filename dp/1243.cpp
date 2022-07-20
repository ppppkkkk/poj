#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

/*
猜数字，总共有G次猜测机会，L次猜高的机会。问能够猜对的最大数字是什么。
如果猜错，那么G-1，如果是猜高了，那么需要额外L-1，当猜对或者G<0或者L<0的时候，猜测结束。
*/
using namespace std;
int dp[50][50];
void init()
{
    for (int i = 1;i <= 30;i++)
    {
        dp[i][0] = i;dp[i][i] = (1 << i) - 1;
        for (int j = 1;j < i;j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] + 1;
        }
    }
}
int main()
{
    int n, m, cas = 1;
    init();
    while (scanf("%d%d", &n, &m) > 0)
    {
        if (n + m == 0)break;
        if (n < m)m = n;
        printf("Case %d: %d\n", cas++, dp[n][m]);
    }
}
