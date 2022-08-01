#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include<iomanip>
using namespace std;

/*
有n个石子摆成一圈,两个人轮流拿硬币，Alice先拿，Alice拿的时候可以选择拿走一个或者拿走相邻的两个，谁拿完最后的石子胜利。
首先n=1,2的时候Alice可以一次性拿完，肯定是Alice赢。
n=3的时候Alice无论怎么取，Bob都可以直接拿走剩下的，所以是Bob赢
n=4的时候，Alice如果哪两个，Bob可以拿走剩下的两个，所以Bob可以赢；Alice如果拿走一个，那么就剩下了三个连续的石子 + 一个有空位，此时如果Bob取走三个石子中中间的那个的话，无论Alice取哪一个，Bob都可以取走剩下的那个

*/


int s[100001];
int n, c;

int main()
{
    int n;
    while (cin>>n,n)
    {
        if (n <= 2)
            printf("Alice\n");
        else
            printf("Bob\n");
    }
    return 0;
}
