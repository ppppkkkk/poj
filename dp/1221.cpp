#include<iostream>
#include<stdio.h>
using namespace std;
long long a[1005][1005];

/*

给一个数n,求有多少种和为n的单峰先增对称序列，比如当n=5时结果为3：(5), (1 3 1), (1 1 1 1 1)
转移方程a[i][j]=a[i-2*j][j]+a[i][j+1];
（a[i][j]指的是将i拆分，拆分最小值为j的个数，则等于a[i-2*j][j]（i-2*j后最小值为j的个数加上i拆分值最小为j+1的个数和）

*/

int main()
{
    int m, n;
    int t, i, j, k, l;
    for (i = 0;i < 1000;i++)
        for (j = 0;j < 1000;j++)
            if (j <= i)
                a[i][j] = 1;
            else
                a[i][j] = 0;

    for (i = 2;i < 1000;i += 2)   //偶数的时候可以拆成对称的i/2和i/2。
        a[i][i / 2] = 2;


    for (i = 3;i < 1000;i++)
    {
        for (j = (i - 1) / 2;j >= 1;j--)
        {
            a[i][j] = a[i - 2 * j][j] + a[i][j + 1];
        }
    }
    while (cin >> n , n)
    {
        cout << n << " " << a[n][1] << endl;
    }
    return 0;
}
