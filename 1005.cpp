#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdio>

#define PI 3.1415926
using namespace std;
/*
poj 1005
有一块半圆土地，以每年50个单位消失，问几年后开始完全消失
*/

int main() 
{
	int n;
	cin >> n;
	double x, y;
	double r, R;
	int num = 1;
	int year;
	while(n--)
	{
		year = 1;
		cin >> x >> y;
		r = x * x + y * y;
		R = 100 / PI;
		while (R < r)
		{
			year++;
			R = (100 * year) / PI;
		}
		cout << "Property " << num << ":" << " This property will begin eroding in year " << year << "." << endl;
		num++;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}
