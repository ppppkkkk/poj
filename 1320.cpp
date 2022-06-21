
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;



/*

求两个不相等的正整数N、M(N<M)，使得 1 + 2 + … + N = (N+1) + … + M。
输出前10组中满足要求的(N，M)

即（2*n+1）^2-8*a^2=1
令x=2*n+1,y=a,则转化为x^2-8*y^2=1的pell方程。

已知x1 = 3，y1 = 1，由迭代公式得：
xn = x(n-1)*x1 + d*y(n-1)*y1
yn = x(n-1)*y1 + y(n-1)*x1
那么
x(n+1) = 3*xn + 8*yn
y(n+1) = xn + 3*yn

No Input
Sample Output
6         8
35        49

*/
int main()
{
	int x1 = 3, y1 = 1, t = 10;
	while (t--) {//前10组
		int x, y;
		x = 3 * x1 + 8 * y1;
		y = 3 * y1 + x1;

		printf("%10d%10d\n", y, (x - 1) / 2);
		x1 = x;
		y1 = y;
	}
	return 0;

}
