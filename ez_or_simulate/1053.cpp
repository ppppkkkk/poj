#include <iostream>
#include <string>
using namespace std;

string str[15];

/*
poj 1053

题目大意：有一种牌，共有81张。每张牌有四个属性，每种属性有三种可能取值：形状(D，O，S)，数字（1，2，3），颜色（R，G，P），纹理（O，F，S）。如果三张牌的的任意一种属性都满足：三张牌的该属性值均相同或各不相同，则成这三张牌可以构成一个set。给出12张牌的所有属性值，求该组牌中是所有set。
例如：S3GS D2GS O1GS 构成一组set，因为第1属性均不同，第2属性均不同，第3属性均相同，第4属性均相同。
输入：由若干组数据组成。每组十二行，每行表示一张牌的属性值。不同组数据之间用空格隔开。
输出：先输出所有的牌，然后依次输出找到的set，若找不到则输出“*** None Found ***”。不同样例之间用空格隔开。具体格式见sample。


*/

bool check_each_bit(int i, int j, int k, int p)
{
	if (str[i][p] == str[j][p] && str[j][p] == str[k][p])
	{
		return true;
	}
	if (str[i][p] != str[j][p] && str[i][p] != str[k][p] && str[j][p] != str[k][p])
	{
		return true;
	}
	return false;
}

bool check(int i, int j, int k)
{
	if (check_each_bit(i, j, k, 0) && check_each_bit(i, j, k, 1) && check_each_bit(i, j, k, 2) && check_each_bit(i, j, k, 3))
	{
		return true;
	}
	return false;
}


int main()
{
	while (cin >> str[0])
	{
		for (int i = 1; i < 12; i++)
		{
			cin >> str[i];
		}
		cout << "CARDS: ";
		for (int i = 0; i < 12; i++)
		{
			cout << " " << str[i];
		}
		cout << endl;
		int num = 0;
		cout << "SETS:   ";
		for (int i = 0; i < 12; i++)
		{
			for (int j = i + 1; j < 12; j++)
			{
				for (int k = j + 1; k < 12; k++)
				{
					if (check(i, j, k))
					{
						if (num >= 1)
						{
							cout << "        ";
						}
						cout << ++num << ".  " << str[i] << " " << str[j] << " " << str[k] << endl;
					}
				}
			}
		}
		if (num == 0) {
			cout << "*** None Found ***" << endl;
		}
		cout << endl;
	}
}
