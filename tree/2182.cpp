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
给一个数n，然后n-1行，每行一个数q,第i个数qi代表第i+1头牛前面有qi头牛编号比它小，求所有牛的编号。

因为只有最后一头牛编号是确定的，所有从后往前，每次用二分找到数字，并用树状数组确定和存储
*/

int a[8001], c[8001], ans[8001], n;

int lower_bit(int q) {
	return q & -q;
}

int summ(int r) {
	int res = 0;
	while (r) {
		res += c[r];
		r -= lower_bit(r);
	}
	return res;
}

void add(int a, int v) {
	int q = a;
	while (q <= n) {
		c[q] += 1;
		q += lower_bit(q);
	}
}

int main() {
	cin >> n;
	a[1] = 0;
	for (int i = 2;i <= n;++i)
		cin >> a[i];
	memset(c, 0, sizeof(c));
	for (int i = n;i >= 1;--i) {
		int l = 1, r = n, mid;
		while (r > l) {
			mid = (r + l) >> 1;
			if (mid - summ(mid) > a[i]) r = mid;
			else l = mid + 1;
		}
		ans[i] = l;
		add(l, 1);
	}
	for (int i = 1;i <= n;++i)
		cout << ans[i] << endl;
	return 0;
}

