#include <iostream>
#include <cstdio>
#include <string>

#define M 200

using namespace std;

/*

按字符串的逆序数大小将字符串排序并输出
poj 1007

*/


struct DNA
{
	char str[M];
	int ans;
};

struct DNA d[M];
struct DNA t;

int main()
{
	int n, m;
	cin >> n >> m;
	//求逆序数
	for (int i = 0;i < m;i++)
	{
		cin >> d[i].str;
		d[i].ans = 0;
		for (int j = 0;j < n;j++)
		{
			for (int k = j;k < n;k++)
				if (d[i].str[j] > d[i].str[k])
					d[i].ans++;
		}
	}
	//按逆序数冒泡排序
	for (int i = 0;i < m;i++)
		for (int j = i;j < m;j++)
		{
			if (d[i].ans > d[j].ans)
			{
				t = d[i];
				d[i] = d[j];
				d[j] = t;
			}
		}

	for (int i = 0;i < m;i++)
	{
		cout << d[i].str << endl;
	}
	return 0;
}

