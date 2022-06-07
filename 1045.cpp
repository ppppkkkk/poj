#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
 
int main()
{
	double Vs, R, C;
	int n;
	scanf("%lf%lf%lf%d", &Vs, &R, &C, &n);
	// printf("Vs: %lf, R: %lf, C: %lf, n: %d\n", Vs, R, C, n);
 
	double w;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lf", &w);
		printf("%.3lf\n", C * R * w * Vs / sqrt(1 + C * R * w * C * R * w));
	}
	
	return 0;  
}
