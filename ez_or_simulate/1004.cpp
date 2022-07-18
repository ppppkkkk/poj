#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstdio>

using namespace std;
/*
poj 1004
*/

int main() 
{
	double num[12];
	double sum = 0;
	for(int i=0;i<12;i++)
	{
		cin >> num[i];
		sum += num[i];
	}
	sum = sum / 12.0;
	printf("$%.2f\n", sum);
	return 0;
}
