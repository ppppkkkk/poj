#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给出两个数，前一个数是X想的数，后一个数是Y猜的数，输出格式是A*B，
A前面表示位置正确，值也正确的数量，B前的*表示值正确但是位置的数量
*/




int main()
{
	int n;

	int X, Y;
	cin >> n;
	while (n--)
	{
		X = 0;
		Y = 0;
		string x, y;
		cin >> x >> y;
		for (int i = 0;i < 4;i++)
		{
			if (x[i] == y[i])
				X++;
			else
			{
				for (int j = i + 1;j < 4;j++)
				{
					if (x[i] == y[j])
						Y++;
					if (y[i] == x[j])
						Y++;
				}
			}
		}
		cout << X << 'A' << Y << 'B' << endl;
	}
	return 0;

}
