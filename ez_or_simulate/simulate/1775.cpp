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
给出一个数 n ，判断能否表示为多个数阶乘的和
*/
int main()
{
    int Factorial[10];
    Factorial[0] = 1;
    for (int i = 1;i <= 9; i++)//打表
        Factorial[i] = Factorial[i - 1] * i;

    int n;
    while (cin >> n) 
    {
        if (n < 0)
            break;
        if (n == 0) {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 9;i >= 0; i--) 
        { 
            if (Factorial[i] <= n)
                n -= Factorial[i];  //这个条件原因是9个阶乘越来越大，
                                    //并且第i个比之前的和要大
        }
        if (n == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
