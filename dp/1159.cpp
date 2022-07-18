#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

/*
字符串最少加入几个字符使得这个字符串是个回文串。
*/
char s[5002];//原字符串
char s1[5002];//逆序后的字符串
short dp[5002][5002];


int LCS(int m) {
	for (int i = 0;i <= m;i++)
	{
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for (int i = 1;i <= m;i++) {
		for (int j = 1;j <= m;j++) {
			if (s1[i - 1] == s[j - 1]) 
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	return dp[m][m];
}
int main() {
	int n, i, j, t;
	while (~scanf("%d", &n)) {
		memset(dp, 0, sizeof(dp));
		scanf("%s", s);
		for (j = 0, i = n - 1;i >= 0;i--) {
			s1[j++] = s[i];
		}
		s1[j] = '\0';
		t = LCS(n);
		printf("%d\n", n - t);
	}
	return 0;
}
