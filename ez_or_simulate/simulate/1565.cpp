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
定义了另外一种数制的表示形式，并给了你这种数制表示形式与十进制的转换关系，现在给你一个这样的数制，让你把它换成2进制输出。
*/



int main()
{
	int k, base[31], sum;
	char skew[32];
	base[0] = 1;
	for (int i = 1;i < 31;i++)
		base[i] = 2 * base[i - 1] + 1;
	while (cin>>skew,skew[0]!='0')
	{
		sum = 0;
		k = strlen(skew);
		for (int i = 0;i < strlen(skew);i++)
		{
			k--;
			sum += (skew[i] - '0') * base[k];
		}
		cout << sum << endl;
	}
	return 0;
}
