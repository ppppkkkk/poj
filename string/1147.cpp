#include<iostream>
#include<cstring>
#include<algorithm>
/*
* 
* poj 1147
* 每一列所含的数是相同的，而且又是排好序的
* 
* 
给定一个N位的二进制串

		b1  b2  ... bN-1  bN

将该串做旋转，即将b1移到bN后面，得到一个新的二进制串：

		b2  b3  ... bN-1  bN  b1

对新的二进制串再做旋转，得二进制串

		b3  b4  ... bN-1  bN b1  b2

重复旋转操作操作，可得N个二进制串，对这N个串排序，可得一个N*N的矩阵
例如：
1 0 0 0 1->0 0 0 1 1->0 0 1 1 0->0 1 1 0 0->1 1 0 0 0
对它们做排序，得矩阵

		0   0   0   1   1
		0   0   1   1   0
		0   1   1   0   0
		1   0   0   0   1
		1   1   0   0   0

问：给定这种矩阵的最后一列，
求出矩阵的第一行。
对于上面的例子，给出 1 0 0 1 0，要你的程序输出 0 0 0 1 1。


*/
using namespace std;
int n;
int a[3005];
int f[3005];
int main()
{
	cin >> n;
	int zero = 0;
	for (int i = 1;i <= n;++i)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;++i)//构造下一列相对于上一列的置换f 
	{
		if (a[i] == 0)
		{
			f[++zero] = i;
		}
	}
	for (int i = 1;i <= n;++i)
	{
		if (a[i] == 1)
		{
			f[++zero] = i;
		}
	}
	int t = f[1];
	for (int i = 1;i <= n;++i)
	{
		cout << a[t] << " ";
		t = f[t];
	}
	cout << endl;
	return 0;
}
