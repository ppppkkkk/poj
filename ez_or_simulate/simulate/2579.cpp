#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
/*
要以左上角的方块与它下方、右方以及右下方的值求平均值，将结果放入该方块即可
*/
char Map[10][10];
char START[20], END[5];

int main()
{
	int r, c;
	while (cin >> START, strcmp(START, "ENDOFINPUT") != 0)
	{
		cin >> r >> c;
		for (int i = 0;i < r;i++)
			cin >> Map[i];           
		for (int i = 0;i < r - 1;i++)
		{
			for (int j = 0;j < c - 1;j++)
			{
				cout << ((Map[i][j] + Map[i + 1][j] + Map[i][j + 1] + Map[i + 1][j + 1]) / 4 - '0');
			}
			cout << endl;
		}
		cin >> END;
	}
	return 0;
}

