#include <iostream>
using namespace std;


struct Rect
{
	int xmin, xmax;
	int ymin, ymax;
};
Rect a[5001];

/*
 判断矩形是否重叠

 Sample Input

3
100 101 100 101
0 3 0 101
20 40 10 400
4
10 20 10 20
10 20 10 20
10 20 10 20
10 20 10 20
Sample Output

0
4

*/


int main()
{
	int n;
	int i, j;
	int sum;
	while (cin >> n)
	{
		sum = 0;
		for (i = 1; i <= n; i++)
		{
			cin >> a[i].xmin >> a[i].xmax >> a[i].ymin >> a[i].ymax;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= n; j++)
			{
				if (i != j && a[i].xmin >= a[j].xmin && a[i].xmax <= a[j].xmax
					&& a[i].ymin >= a[j].ymin && a[i].ymax <= a[j].ymax)
				{
					sum++;
					break;//避免重复计数 
				}
			}
		}
		cout << sum << endl;

	}
	return 0;
}
