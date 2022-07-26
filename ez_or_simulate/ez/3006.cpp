#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
设一个等差数列，首元素为a，公差为b
现在要求输入a,b,n ，要求找出属于该等差数列中的第n个素数并输出
*/




int prime(int num)
{
    if (num == 1)
        return 0;
    for (int i = 2; i * i <= num; ++i)
        if (num % i == 0)
            return 0;
    return 1;

}

int main()
{
    int a, d, n;
    while (cin >> a >> d >> n)
    {
        if (a == 0 && d == 0 && n == 0)
            break;
        int cnt = 0;
        int prime_num = 0;
        while (cnt < n)
        {
            if (prime(a))
            {
                ++cnt;
                prime_num = a;
            }
            a += d;
        }
        cout << prime_num << endl;
    }
    return 0;
}
