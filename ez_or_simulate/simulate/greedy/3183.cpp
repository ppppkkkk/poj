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
有n个树桩，分别有一个高度h[i]，要用Bomb把树桩都炸掉，
如果炸的位置的两边树桩高度小于Bomb炸的树桩高度，那么小于树桩高度的两侧都是可以被炸掉的。而且有传递性。求把树桩全部炸掉要消耗的最少的Bomb数所炸的位置。
greedy
*/

int h[50001];

int main() {
	int n;
	cin >> n;

	for (int i = 1;i <= n;i++) {
		cin >> h[i];
	}

	if (h[1] >= h[2]) {
		cout << 1 << endl;
	}

	for (int i = 2;i <= n;i++) {
		if (i == n && h[i] >= h[i - 1])
			cout << n << endl;
		else if (h[i] >= h[i - 1] && h[i] >= h[i + 1])
			cout << i << endl;
	}

	return 0;
}
