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
	int n;
	while (scanf("%d", &n) , n)
	{
		int unhappiest = 0, maxstudyhours = 0;
		for (int i = 0; i < n; ++i)
		{
			int school, supplementary;
			scanf("%d%d", &school, &supplementary);
			int studyhours = school + supplementary;
			if (studyhours > 8)
			{
				if (studyhours > maxstudyhours)
				{
					maxstudyhours = studyhours;
					unhappiest = i + 1;
				}
			}
		}

		printf("%d\n", unhappiest);
	}
	return 0;
}

