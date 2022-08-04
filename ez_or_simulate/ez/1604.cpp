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
/*

*/
int main() {
	int n, sum;
	while (cin>>n) 
	{
		sum = 1;
		for (int i = 1; i <= n; i++) {
			sum *= i;
			while (sum % 10 == 0) {
				sum = sum / 10;
			}
			sum = sum % 100000;
		}
		printf("%5d -> %d\n", n, sum % 10);
	}
	return 0;
}
