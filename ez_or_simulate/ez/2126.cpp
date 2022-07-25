#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;



int main()
{
	int t;
	int a, b, c;
	cin >> t;
	if (t <= 1) { cout << "YES" << endl; }
	else if (t > 2) { cout << "NO" << endl; }
	else
	{
		cin >> a >> b >> c;
		if (b * b - 4 * a * c >= 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
}
