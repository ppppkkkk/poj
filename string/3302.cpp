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
给定两个字符串，要求判断后一个字符串是否是前一个字符串或者前一个字符串的反串经过裁剪得到的子字符串。
*/


bool judge(string a, string b)
{
	int j = 0;
	for (int i = 0; i < a.length(); i++)
	{
		if (b[j] == a[i])
			j++;
	}
	if (j == b.length())
		return true;
	else
		return false;

}
int main()
{
	int t;
	cin >> t;
	string s1, s2;
	while (t--)
	{
		cin >> s1 >> s2;
		if (judge(s1, s2))
		{
			cout << "YES" << endl;
			continue;
		}
		reverse(s2.begin(), s2.end());
		if (judge(s1, s2))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
