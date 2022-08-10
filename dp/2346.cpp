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
n位数，满足前n/2个数字之和同后n/2个数字之和相同的数一共有多少个
dp[i][j]表示前i个数的和为j时，有多少个；
递推关系：dp[i][j] += dp[i-1][k], k表示前i-1个数的和，由于每一位只能是0-9，所以有限制条件：9 >= j - k >=0
*/





int main()
{
	int n, dp[10][100];
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 0; j <= i * 9; j++) {
			if (i == 1) {
				dp[i][j] = 1;
				continue;
			}
			for (int k = j; k >= 0 && k >= j - 9; k--) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= (n / 2) * 9; i++)
		ans += dp[n / 2][i] * dp[n / 2][i];
	if (n % 2) 
		ans *= 10;
	printf("%d\n", ans);

	return 0;
}
