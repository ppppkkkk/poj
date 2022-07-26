#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给定一个平方根小数部分的前几位，求最小的原始数值
*/

const double dig[] = { 1,1e-1,1e-2,1e-3,1e-4,1e-5,1e-6,1e-7,1e-8,1e-9 };


int main()
{
    int len, num;
    scanf("%d%d", &len, &num);
    double num1 = num * dig[len];
    for (int i = 1;;i++)
    {
        double tmp1 = (long long)((i + num1)*(i+num1)) + 1;
        double tmp2 = (i + num1 + dig[len])* (i + num1 + dig[len]);
        if (tmp2 > tmp1)
        {
            printf("%lld\n", (long long)tmp1);
            break;
        }
    }

    return 0;
}
