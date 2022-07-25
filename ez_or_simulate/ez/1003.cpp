#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;

/*
poj 1003
*/

int main() 
{
	double c;//目标值
	int n;
	while (cin >> c, c)
	{
		n = 2;//从2开始
		double sum = 0;
		while (sum < c)
		{
			sum += 1.0 / n;
			n++;
		}
		cout << n - 2 << " card(s)" << endl;
	}
	return 0;
}
