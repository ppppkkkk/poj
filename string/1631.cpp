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
给你n个桥，求在不相交的情况下最大有多少桥可以存在。
最小上升子序列
*/

using namespace std;

int a[40000], dp[40000];

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		dp[1] = a[1];
		int len = 1;
		for (int i = 2; i <= n; i++) {
			if (a[i] > dp[len]) {
				dp[++len] = a[i];
			}
			else {
				int l = 1, r = len, m;
				while (l < r) {
					m = (l + r) / 2;
					if (dp[m] >= a[i]) {
						r = m;
					}
					else {
						l = m + 1;
					}
				}
				dp[l] = a[i];
			}
		}
		cout << len << endl;
	}
}
