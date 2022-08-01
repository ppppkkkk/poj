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
找出1到n里面有多少对互质的数
欧拉函数
*/


int a[1000001], n = 1000000, b;
long long ans[1000001] = { 0 };
void init()
{
	for (int i = 1;i <= n;i++)a[i] = i;
	for (int i = 2;i <= n;i++)
		if (a[i] == i)
			for (int j = i;j <= n;j += i)
				a[j] = a[j] / i * (i - 1);
}

int main()
{
	init();
	for (int i = 2;i <= 1000000;i++)
		ans[i] = ans[i - 1] + a[i];
	while (cin >> b , b)
		cout << ans[b] << endl;
	return 0;
}

