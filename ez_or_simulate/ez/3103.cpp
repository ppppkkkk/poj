#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*

*/


int main()
{
	int x, y, z, n;
	while (cin>>x>>y>>z>>n)
	{
		for (int i = 0; i < n; i++)
			printf("0 0 %.8lf %d %d %.8lf\n", 1.0 * z * i / n, x, y, 1.0 * (i + 1) * z / n);
	}
	return 0;
}
