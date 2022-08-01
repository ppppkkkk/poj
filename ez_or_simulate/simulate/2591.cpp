#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;
long a[10000001];
int main() {
	long i2=1, i3=1;
	a[1] = 1;
	for (long i = 2; i < 10000001; i++) {
		a[i] = min(2 * a[i2] + 1, 3 * a[i3] + 1);
		if (a[i] == 2 * a[i2] + 1)
			i2++;
		if (a[i] == 3 * a[i3] + 1) 
			i3++;
	}
	long t;
	while (cin>>t)
		printf("%ld\n", a[t]);
	return 0;
}

