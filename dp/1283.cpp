#include<iostream>
using namespace std;

/*
有n台电脑要有k辆卡车去运，每台卡车不能为空，问有多少种运输方案.
注：假设有7台电脑，3辆卡车，1,1,5和1,5,1和5,1,1被视为同一种。

dp[i][j]表示i辆卡车运输j台电脑的方案数，可以这么理解，
第i辆卡车放1台电脑，dp[i-1][j-1],
每一辆卡车至少有两台电脑，dp[i][j-i],所以dp[i][j] = dp[i-1][j-1] + dp[i][j-i]
*/


long long dp[201][201];


void init() {

	for (int i = 1;i <= 200;i++)
		dp[i][i] = 1;
	for (int i = 1;i <= 200;i++)
		for (int j = i + 1;j <= 200;j++)
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - i];

}

int main() {
	init();
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		cout << dp[m][n] << endl;

	}

	return 0;
}
