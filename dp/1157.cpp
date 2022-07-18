#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;

/*

poj 1157
f朵花，v个花瓶，按花的顺序插花

Sample Input

3 5
7 23 -5 -24 16
5 21 -4 10 23
-21 5 -4 -20 20
Sample Output

53

*/

const int INF = 1000;
const int maxn = 110;
int a[maxn][maxn];//花和花瓶
int dp[maxn][maxn];

int main()
{
    int n, m;
    cin >> n >> m;
        for (int i = 1;i <= n;i++)
        {
            for (int j = 1;j <= m;j++)
            {
                cin >> a[i][j];
                dp[i][j] = -INF;
            }
        }
        for (int i = 0;i <= m;i++)//边界赋0
        {
            dp[0][i] = 0;
        }
        dp[1][1] = a[1][1];
        for (int i = 1;i <= n;i++)
        {
            for (int j = i;j <= m;j++)//按花的顺序
            {
                for (int k = 1;k < j;k++)
                {
                    dp[i][j] = max(dp[i][j], (dp[i - 1][k] + a[i][j]));//dp转移方程
                }
            }
        }
        int ans = -INF;
        for (int i = 1;i <= m;i++)
        {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    
    return 0;
}

