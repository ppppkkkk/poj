#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
假设每L溶解了x摩尔的该酸，就有
Ka = mx*nx / ori-x ，变换以后就是 Ka*(ori-x) = mn*x*x ，
mnx^2 + Ka*x - Ka*ori = 0，这样就变成了一个一元二次方程
x = [sqrt(Ka*Ka+4*m*n*Ka*c)-Ka] / 2mn，而 [H+] =x*m;


*/



int main()
{
	int m, n;
	double k, c, ph, x, delta;
	while (scanf("%lf%lf%d%d", &k, &c, &m, &n) && k + c + m + n)
	{
		delta = sqrt(k * k + 4 * n * c * k * m);
		x = (-k + delta) / (2 * n);
		ph = -log10(x);
		printf("%.3f\n", ph);
	}
	return 0;
}


