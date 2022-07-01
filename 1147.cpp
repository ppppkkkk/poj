#include<iostream>
#include<cstring>
#include<algorithm>

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
