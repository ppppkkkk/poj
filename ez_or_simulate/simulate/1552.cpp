#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;

const int INF = 0x3f3f3f3f;


int main()
{

	int num;
	vector<int> v;
	int cnt = 0;
	while (cin >> num, num != -1) {
		if (num)
			v.push_back(num);

		else 
		{
			for (vector<int>::iterator iter1 = v.begin();iter1 != v.end();++iter1) 
			{
				for (vector<int>::iterator iter2 = v.begin();iter2 != v.end();++iter2) 
					if (*iter1 * 1.0 / 2 == *iter2) 
						cnt++;

			}
			cout << cnt << endl;

			v.clear();
			cnt = 0;
		}
	}

	return 0;
}
