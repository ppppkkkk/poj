#include<stdio.h>
/*
* 转的是表盘不是表针
先把刻度盘顺时针转两圈，然后再顺时针转到第一个数，
再把刻度盘逆时针转一圈，再逆时针转到第二个数，
最后再顺时针转到第三个数。这里的转到那个数是指将刻度盘上的数转到指针处
*/
int main()
{
	int a, b, c, d;
	int sum=0;
	while (scanf("%d%d%d%d", &a, &b, &c, &d),(a+b+c+d))
	{
		sum = 0;
		sum += 720;
		sum += ((a + 40 - b) % 40) * 9;
		sum += 360;
		sum += ((c + 40 - b) % 40) * 9;
		sum += ((c + 40 - d) % 40) * 9;

		printf("%d\n", sum);
	}
	return 0;
}
