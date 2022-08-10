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
求1--n个数排列，逆序对为k时排列可能情况
dp[i][j]保存个数为i ，逆序对为j时的结果，则对于i+1，若 i+1放在末尾，逆序对数都不变，
则dp[i+1][j]=dp[i][j];若 i+1插在倒数第二个，逆序对数都+1，则dp[i+1][j]=dp[i][j-1]
可知 dp[i+1][j]是所有这些的和
*/



int main()
{
    long long dp[20][200] = { 0 };
    dp[1][0] = 1;
    for (int i = 1; i < 18; i++)
        for (int j = 0; dp[i][j]; j++)
            for (int k = 0; k <= i; k++)
                dp[i + 1][j + k] += dp[i][j];
    int x, y;
    while (cin >> x >> y, x)
        cout << dp[x][y] << endl;
}
