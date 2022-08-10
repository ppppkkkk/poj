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
给定一个正整数N，求最小的、比N大的正整数M，使得M与N的二进制表示中有相同数目的1。
例如，假如给定的N为78，其二进制表示为1001110，包含4个1，那么最小的比N大的并且二进制表示中只包含4个1的数是83，其二进制是1010011，因此83就是答案。
greedy
*/



int a[30];

int solve(int n)
{
	int i = 0;
	while (n)
	{
		a[i++] = n & 1;
		n >>= 1;
	}

	for (int j = 0; j < i; j++)
	{
		if (a[j] == 0)  //如果当前为0，就继续循环。
		{
			continue;
		}

		//下一位为0，并且当前位一定为1，交换二者并退出循环，这里把1， 3这样的情况也直接处理了
		if (a[j + 1] == 0)
		{
			swap(a[j], a[j + 1]);
			break;
		}
		else//如果当前位为1，并且他的下一位也是1，那就把这个1移到最后。
		{
			for (int t = j; t > 0; t--)
			{
				swap(a[t], a[t - 1]);
			}
		}
	}

	//因为像3，本来为11，交换后变为了101，会进位一个，所以从i开始循环。
	for (int j = i; j >= 0; j--)
	{
		n = n * 2 + a[j];
	}

	return n;
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		memset(a, 0, sizeof(a));
		cout << solve(n) << endl;
	}

	return 0;
}
