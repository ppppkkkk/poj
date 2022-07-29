#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
一个房间由m*n个方块组成  每个机器人占据一个方块  这些机器人能够移动 
这些机器人的移动动作全部完成后 会不会发生冲撞事件
*/

int x[105];
int y[105];
int c[105];
bool crash;
bool wall(int robotNum, int a, int b)
{
	if (x[robotNum] <= 0 || x[robotNum] > a || y[robotNum] <= 0 || y[robotNum] > b)
		return true;
	return false;
}
int detectCrash(int robotNum, int a, int b, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i != robotNum)
		{
			if (x[i] == x[robotNum] && y[i] == y[robotNum])
				return i;
		}
	}
	return -1;
}
void ford(int robotNum, int a, int b, int n)
{
	switch (c[robotNum])
	{
	case 0:
		x[robotNum]--;
		break;
	case 1:
		y[robotNum]--;
		break;
	case 2:
		x[robotNum]++;
		break;
	case 3:
		y[robotNum]++;
		break;
	}
	if (wall(robotNum, a, b))
	{
		cout << "Robot " << robotNum + 1 << " crashes into the wall" << endl;
		crash = true;
	}
	else
	{
		int k = detectCrash(robotNum, a, b, n);//k==-1 有crash
		if (k != -1)
		{
			cout << "Robot " << robotNum + 1 << " crashes into robot " << k + 1 << endl;
			crash = true;
		}

	}
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(c, 0, sizeof(c));
		int a, b;
		cin >> a >> b; //宽 高 
		int n, m;
		cin >> n >> m;	//机器人数 指令数 
		crash = false;
		for (int i = 0; i < n; i++)
		{
			char cc;
			cin >> x[i] >> y[i] >> cc;
			if (cc == 'W')
				c[i] = 0;
			else if (cc == 'S')
				c[i] = 1;
			else if (cc == 'E')
				c[i] = 2;
			else if (cc == 'N')
				c[i] = 3;
		}
		for (int i = 0; i < m; i++)
		{
			int robot, repeat;
			char action;
			cin >> robot >> action >> repeat;
			for (int j = 0; j < repeat; j++)
			{
				switch (action)
				{
				case 'L':
					c[robot - 1]++;
					if (c[robot - 1] == 4)
						c[robot - 1] = 0;
					break;
				case 'R':
					c[robot - 1]--;
					if (c[robot - 1] == -1)
						c[robot - 1] = 3;
					break;
				case 'F':
					if (!crash) //如果发生过crash, 就没有必要再根据后面的指令了操作了 
					{
						ford(robot - 1, a, b, n);
					}
					break;
				}
			}
		}
		if (!crash)
		{
			cout << "OK" << endl;
		}
	}
	return 0;
}
