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
给出p,q,r,s，求c(p,q)/c(r,s)组合数公式
*/

struct point {
	double x, y;
}p[5];
int main() {
	while (scanf("%lf %lf", &p[0].x, &p[0].y) != EOF) {
		int a, flag = 1;
		double resX, resY;
		resX = p[0].x;
		resY = p[0].y;
		for (int i = 1;i <= 3;i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			resX += p[i].x;
			resY += p[i].y;
			for (int j = 0;flag && j < i;j++)//找出坐标相等的两个点，将标号记入a
				if (p[i].x == p[j].x && p[i].y == p[j].y) 
				{
					a = i;
					flag = 0;
				}
		}
		resX -= 3 * p[a].x;
		resY -= 3 * p[a].y;
		printf("%.3lf %.3lf\n", resX, resY);
	}
	return 0;
}

