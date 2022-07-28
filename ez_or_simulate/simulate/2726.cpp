#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
候选酒店 M 满足两个要求：
任何比 M 更靠近海边的酒店都会比 M 贵。
任何比 M 便宜的旅馆都会比 M 离海边更远。

*/
struct hotel {
	int dist;
	int cost;
}h[10005];
bool cmp(const hotel& a, const hotel& b) {
	if (a.dist == b.dist)
		return a.cost < b.cost;
	else
		return a.dist < b.dist;
}
int main() {
	int n;
	while (cin >> n,n)
	{
		for (int i = 0;i < n;i++)
			cin >> h[i].dist >> h[i].cost;
		sort(h, h + n, cmp);
		int min = 100000;
		int ans = 0;
		for (int i = 0;i < n;i++) {
			if (h[i].cost < min) {
				ans++;
				min = h[i].cost;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

