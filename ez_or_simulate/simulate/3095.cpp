#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
小球从高处随机落在凹凸不平的地面上，
求小球掉到洞中或从端点离开的概率。
字符 / 和 \ 表示斜坡，小球落在斜坡上会向一个方向移动；
字符 | 表示墙；字符 _ 表示平面，小球落在平面上不移动；
字符 . 表示洞。
*/







char a[80];

int left(int index)//向左移动
{
	for (int i = index - 1;i >= 0;--i)
		if (a[i] == '.')
			return 1;
		else if (a[i] == '|' || a[i] == '/' || a[i] == '\\')
			return 0;
	return 1;
}

int right(int index)//向右移动
{
	for (int i = index + 1;i<strlen(a);i++)
		if (a[i] == '.')
			return 1;
		else if (a[i] == '|' || a[i] == '/' || a[i] == '\\')
			return 0;
	return 1;
}
int main()
{
	while (scanf("%s", a) == 1, a[0] != '#') {
		int sum = 0;
		for (int i = 0;i < strlen(a);++i)
			if (a[i] == '.')
				sum += 100;
			else if (a[i] == '_')
				sum += 0;
			else if (a[i] == '/') {
				if (left(i) == 1)
					sum += 100;
			}
			else if (a[i] == '\\') {
				if (right(i))
					sum += 100;
			}
			else if (a[i] == '|') {
				if (right(i))
					sum += 50;
				if (left(i))
					sum += 50;
			}
		printf("%d\n", sum / strlen(a));
	}
	return 0;
}

