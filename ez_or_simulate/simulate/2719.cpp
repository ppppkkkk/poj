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
一个汽车公里表，计算的时候，遇见4就跳过去，比如跑了三公里又跑了一公里，就显示5，
给出显示数值，求真实数值
*/
const int maxn = 100005;
int s[15];
int main()
{
    int ans, n;
    while (cin >> n && n)
    {
        int  m = n;
		int num = 0;
		while (m) {
			s[num++] = m % 10;
			m /= 10;
		}
		ans = 1;
		for (int i = 0; i < num; i++) {
			if (s[i] > 4) s[i]--;
			m += ans * s[i];
			ans *= 9;
		}
		cout << n << ':' << ' ' << m << endl;
	}
	return 0;
}
