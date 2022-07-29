#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
给出 10 个数，输出这 10 个数乘积的因子个数 % 10 的结果 
 
若正整数n可分解为p1^a1*p1^a2*…*pk^ak
其中pi为两两不同的素数,ai为对应指数
n的约数个数为(1+a1)*(1+a2)*….*(1+ak)

*/

int main()
{
    int x, n = 10;
    int a[10002];
    memset(a, 0, sizeof(a));
    while (n--)
    {

        scanf("%d", &x);
        for (int i = 2;x != 1;i++)
        {
            while (x % i == 0 && x != 1)
            {
                a[i]++;
                x /= i;
            }
        }
    }
    for (int i = 2;i < 10000;i++)
    {
        if (a[i] != 0)
        {
            x = x * (1 + a[i]) % 10;
        }
    }
    printf("%d\n", x);
    return 0;
}
