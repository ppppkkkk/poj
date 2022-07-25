
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

#define MAX_POS 1500
using namespace std;



/*
只有素数因子 2， 3， 5 的数字才成为丑陋数字，现给出一个数字 n , 求在丑陋数字的序列里， 第n个丑陋数字是多少。
*/



int Min(int a, int b, int c)
{
    int min = a < b ? a : b;
    min = min < c ? min : c;
    return min;
}


int main()
{
    int ugly[MAX_POS + 1], i;
    int v2, v3, v5;
    int p2, p3, p5;
    int n;
    p2 = p3 = p5 = 1;
    ugly[1] = 1;
    for (i = 2;i <= MAX_POS;i++)
    {//求出丑陋列表
        v2 = ugly[p2] * 2;
        v3 = ugly[p3] * 3;
        v5 = ugly[p5] * 5;
        ugly[i] = Min(v2, v3, v5);
        if (ugly[i] == v2)  p2++;
        if (ugly[i] == v3)  p3++;
        if (ugly[i] == v5)  p5++;
    }
    while (cin>>n , n)
    {
        cout << ugly[n] << endl;
    }
    return 0;
}
