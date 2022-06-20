#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>

/*
 
给出一种求PI近似值的方法，
随机给出n个无重复正整数，
其中互质的数对有m对，
那么比例为m/Cn,2。而这个比例接近常数6/PI^2。


Sample Input

5
2
3
4
5
6
2
13
39
0



Sample Output

3.162278
No estimate for this data set.
*/

using namespace std;

int num[500];

int gcd(int p, int q) {
    int r = p % q;
    if (r == 0) {
        return q;
    }
    else {
        return gcd(q, r);
    }
}


int main()
{
    int n;
    while (cin >> n && n)
    {
        int sum = 0;
        for (int i = 0;i < n;i++)
                cin >> num[i];
            for (int i = 0;i < n - 1;i++)
                for (int j = i + 1;j < n;j++)
                    if (gcd(num[i], num[j]) == 1)
                        sum++;//求出互质的对数
            if (!sum)
                printf("No estimate for this data set.\n");
            else
                printf("%.6f\n", sqrt(3. * n * (n - 1) / (double)sum));
    }
    return 0;
}
