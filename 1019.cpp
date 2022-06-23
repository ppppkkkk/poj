#include <cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

long long len[40000];//第i个子串长度
long long s[40000];//到第i个子串的总长度

void init() {
	len[1] = s[1] = 1;
	for (int i = 2;i <= 32000;i++) 
	{
		len[i] = len[i - 1] + (int)log10(1.0*i) + 1;
		s[i] = s[i - 1] + len[i];
	}
}

int solve(int m) 
{
	int num = 1;
	while (s[num] < m)
	{
		num++;
	}
	int pos = m - s[num - 1];//在i串中的位置

	int i, length = 0;
	for (i = 1; length < pos; i++) 
		length += (int)log10(1.0*i) + 1;//第i组长度
	i--;//i就是子串表示的数
	int ret = i/ (int)pow(10.0, length - pos);
	ret %= 10;
	return ret;

}

int main() 
{
	init();
	int n;
	cin >> n;
	int m;
	while (n--) 
	{
		cin >> m;
		cout << solve(m) << endl;
	}

	return 0;
}
