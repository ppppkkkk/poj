#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
求小于n且与n互质的正整数个数
欧拉函数=小于n且与n互质的正整数个数。
f(n)=n*(1-1/p1)*(1-1/p2)....*(1-1/pn)，其中p1...pn为不同的质因数。
*/


int euler(int n)
{
    int tmp = n;
    for (int i = 2;i * i <= n;i++)
    {
        if (n % i == 0)
        {
            tmp = tmp - tmp / i;//tmp = tmp * (1 - 1/i) 直接算的话会变成0出问题 变个形
            while (n % i == 0)
                n /= i;
        }
    }
    if (n > 1)
        tmp = tmp / n * (n - 1);
    return tmp;
}

int main()
{
    int n;
    while (cin >> n , n)
    {
        cout << euler(n) << endl;
    }
    return 0;
}
