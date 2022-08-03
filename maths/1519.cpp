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

const int INF = 0x3f3f3f3f;
/*
求一个数的“树根”。先求一个数每位数字之和，如果和不为一个个位数，
则将该数再求位数和，直到位数和为个位数，这个个位数就是该数的“树根”。

树根=位数和（mod 9）
*/

int main()
{
    int sum = 0;
    string str;
    while (cin>>str,str[0]!='0')
    {
        sum = 0;
        for (int i = 0;i < str.size();i++)
        {
            sum += str[i] - '0';
        }
        sum = sum % 9;
        if (!sum)
            sum = 9;
        printf("%d\n", sum);
    }
    return 0;
}
