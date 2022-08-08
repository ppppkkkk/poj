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
给定两个字符串s和t，你需要判断s是否是t的“子列”。也就是说，如果你去掉t中的某些字符，剩下字符将连接而成为s
*/

int main()
{
	string a, b;
	int i, j;
	while (cin >> a >> b)
	{
		for (i = 0, j = 0; i < a.size() && j < b.size(); ++j)
		{
			if (a[i] == b[j])
				i++;
		}
		if (i == a.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}
