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
求任意两个不同进制非负整数的转换
*/
int main()
{
	int t, Case = 1;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		printf("Problem set %d: %d / %d, base 7 digits %d through %d: ", Case++, a, b, c, d);
		int i;
		a %= b;
		for (i = 0; i <= d; ++i) {
			a *= 7;
			if (i >= c) {
				printf("%d", a / b);
			}
			a %= b;
		}
		printf("\n");
	}
	return 0;
}
