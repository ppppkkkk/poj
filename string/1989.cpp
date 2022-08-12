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
一个序列的最短非子序列长
*/


bool num[10001];
int main()
{
	int n, k, len = 0, size = 0, index;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &index);
		if (num[index] == false)
		{
			num[index] = true;
			size++;
		}
		if (size == k)
		{
			memset(num, 0, sizeof(num));
			len++;
			size = 0;
		}
	}
	printf("%d\n", len + 1);
	return 0;

}
