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
	long long n;
	while (cin>>n) {
		long long  now = 1;
		int flag = 0; 
		while (now < n) {
			if (flag) {
				flag = 0;
				now *= 2;

			}
			else {
				flag = 1;
				now *= 9;
			}
		}
		if (flag) 
			printf("Stan wins.\n");
		else 
			printf("Ollie wins.\n");
	}

	return 0;

}
