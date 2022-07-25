#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
/*
给N个数和次方k，问这N个数的k次方之和最大是多少
*/



int main()
{
	int n;
	int a;
	int temp;
	cin >> n;
	
	double sum = 0;
	cin >> a;
	for (int i = 0;i < n;i++)
	{
		int s;
		cin >> s;
		temp = pow(double(s), (double)a);
		if (temp>0) { sum += temp; }
		else { sum = sum + 0; }
	}
	cout << sum << endl;

	return 0;
}
