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
输入一个数，如果这个数是素数就输出0，如果不是素数就输出离它最近的两个素数的差值
*/

int Prime[1300000], PrimeNum[100010];

int IsPrime()
{
    for (int i = 2; i <= 1300000; i++)
        Prime[i] = 1;
    for (int i = 2; i <= 1300000; i++)
    {
        for (int j = i + i; j <= 1300000; j += i)
            Prime[j] = 0;
    }
    int num = 0;
    for (int i = 2; i <= 1300000; i++)
    {
        if (Prime[i])
            PrimeNum[num++] = i;
    }
    return num;
}


int main()
{
    int n;
    int num = IsPrime();
    while (~scanf("%d", &n) , n)
    {
        if (Prime[n])
        {
            printf("0\n");
            continue;
        }
        else
        {
            for (int i = 0; i < num; i++)
            {
                if (PrimeNum[i] < n && PrimeNum[i + 1] > n)
                    printf("%d\n", PrimeNum[i + 1] - PrimeNum[i]);
            }
        }
    }

    return 0;

}
