#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int R, M, Y;
	scanf("%d%d%d", &R, &M, &Y);
	printf("%d\n", (int)(M * pow(1 + R / 100.0, Y)));
	return 0;
