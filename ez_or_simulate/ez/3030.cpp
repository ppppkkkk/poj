#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
对于杨辉三角形的第n行，首先但看每一位，将其补成长度为k的数（左补0），然后将这一行连起来作为一个大数，求这个大数mod m。
题解：数学公式推导题
　　　1、补0实际上就是使得这个数左边的那个数乘以10的次方，那么最后答案就是Σ(C(n,m)*10^( (n-m)*k ) )%m
　　　2、10^(n-m)k=(10^k)^(n-m),又有个C(n,m)，正好组成二项式(1+10^k)^n的展开式
　　　3、于是两个快速幂取模就可以解决了。
*/








int main()
{

	int n;
	cin >> n;

	for (int i = 0;i < n;i++) {
		int r, e, c;
		cin >> r >> e >> c;

		if (r > (e - c)) {
			cout << "do not advertise" << endl;
		}
		else if (r == e - c) {
			cout << "does not matter" << endl;
		}
		else {
			cout << "advertise" << endl;
		}
	}

	return 0;


}
