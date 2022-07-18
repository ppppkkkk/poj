#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

//从下到上最大路径DP

/*
input
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

output
30

*/


int main()
{
	int n,i,j;
	int a[101][101];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
		{
			cin>>a[i][j];//初始化
		}
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			a[i][j] = max(a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]);//往上加
		}
	}
	cout<<a[1][1]<<endl;
	return 0;
}
