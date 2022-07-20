#include<stdio.h>
#include<string>
#include<iostream>


using namespace std;


/*

poj 1316
存在一种数字，它可以用另一个数和那个数本身各个位数之和表示，
比如51可以用39+3+9表示，则要求输出10000以内，所有不能用这种形式表示的数字。
区间筛选

*/
typedef unsigned long long ULL;

int book[10001];

int mysum(int n)
{
    int sum = 0;
    if (n < 10)
        return n;
    while (n)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

void fun(int n)
{
    if (n > 10000)
        return;
    int next = n + mysum(n);
    if (next < 10000 && book[next] == 0)
        book[next] = 1;
    fun(next);
}

int main()
{
    for (int i = 1;i < 10000;i++)
        fun(i);
    for (int i = 1;i < 10000;i++)
        if (book[i] == 0)
            printf("%d\n", i);
    return 0;
}

