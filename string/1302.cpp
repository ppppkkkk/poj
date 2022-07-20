#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*

有一段字符串，如果是字母开头的，此字母就变成后面变异数的总和
如果以数字开头，此数字变成N-1，然后从后面第N个开始变异
如果以0开头，就不变。

递归


*/


int n;
string s;
int dfs(int x)
{
	if (x == n || s[x] == '0')
	{
		return 0;
	}
	if (s[x] >= '1' && s[x] <= '9')
	{
		s[x]--;
		if ((x + s[x] - '0' + 1) < n)
		{
			int y = dfs(x + s[x] - '0' + 1);
			return y + 1;
		}
		else
		{
			return dfs(x + 1) + 1;
		}
	}
	else if (s[x] >= 'A' && s[x] <= 'Z')
	{
		int y = dfs(x + 1);
		s[x] = (y % 10) + '0';
		return y + 1;
	}
}
int main()
{
	string ts;
	while (cin >> ts)
	{
		if (ts == "ENDOFINPUT")
			break;
		cin >> n;
		cin >> s;
		cin >> ts;
		dfs(0);
		cout << s << endl;
	}
	return 0;
}
