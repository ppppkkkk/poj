#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
输入长度顺序排列的名称列表
输出看起来更对称，顶部和底部的字符串越短，中间的字符串越长。
每对名字都属于列表的两端，而这对名字中的第一个总是在列表的顶部。

*/



void print(int n)//递归输出名字 
{
	string s;
	cin >> s;
	cout << s << endl;//第一组从头输出
	if (--n)
	{
		cin >> s;
		if (--n)
			print(n);
		cout << s << endl;//第二组倒序输出
	}
}
int main()
{
	int k = 1, n;
	while (scanf("%d", &n) , n)
	{
		printf("SET %d\n", k++);//计数
		print(n);
	}
	return 0;
}


