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
求解一个偶数可以分解成多少个素数对，要求每对素数之和为这个偶数。

*/


bool isPrime(int n) 
{
	for (int i = 2;i <= sqrt(1.0 * n);i++) 
		if (n % i == 0) 
			return false;
		
	return true;
}

int main() 
{
	int n;
	while (cin >> n, n) 
	{
		int cnt = 0;
		for (int p1 = 2;p1 <= n / 2;p1++) {
			if (!isPrime(p1) || !isPrime(n - p1)) 
				continue;

			cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}
