#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
/*
给一个数n，求把它分解为2的幂的和的方法种数
如果n是奇数那么f(n)=f(n-1)   在f(n-1)的组合前面加上1
如果n是偶数那么f(n)=f(n-1)+f(n/2)，因为f(n)比f(n-1)多出的数字组合正好是f(n/2)的组合中每一位都乘以2得到的
*/


int main()
{
    int f[1000001], N;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3;i <= 1000000;i++)
    {
        if (i & 1)  //判断奇偶
            f[i] = f[i - 1];
        else
        {
            f[i] = f[i - 1] + f[i>>1];
            f[i]%=1000000000;
        }
    }
    scanf("%d", &N);
    printf("%d\n", f[N]);
}
