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

int main()
{
	int a[20], b[20];
	int n,m,k;
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i)
	{
		cin >> a[i];
	}
	for (int i = 0; i < k; ++i)
	{
		cin >> b[i];
	}
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		sum += abs(a[i] - b[i]);
	}
	cout << sum / 2 << endl;
}
