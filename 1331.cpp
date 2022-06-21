#include <iostream>
#include <string>
using namespace std;

/*

三个数字p，q，r，
求最小的进制下p*q=r成立；

Sample Input
3
6 9 42
11 11 121
2 2 2

Sample Output
13
3
0

*/



int change(string a, int k)//k进制转换为十进制
{
	int ans = 0;
	for (int i = 0;i < a.size();i++) {
		ans = ans * k + a[i] - '0';
	}
	return ans;
}


bool isBig(string a, int k) {
	//k进制下p，q，r的每位上的数字都应小于k
	for (int i = 0;i < a.size();i++) {
		if (a[i] - '0' >= k)
			return false;
	}
	return true;
}


int main() {
	string p, q, r;
	int t, i;
	cin >> t;
	while (t--) {
		cin >> p >> q >> r;
		for (i = 2;i <= 16;i++) {
			if (isBig(p, i) == true && isBig(q, i) == true && isBig(r, i) == true) {
				int pp = change(p, i);
				int qq = change(q, i);
				int rr = change(r, i);
				long long ans = pp * qq;
				long long ans2 = rr;
				if (ans == ans2)
					break;
			}

		}
		if (i == 17)
			i = 0;
		cout << i << endl;
	}
	return 0;
}
