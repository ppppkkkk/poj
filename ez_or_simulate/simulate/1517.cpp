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
输出由上述公式生成的e的近似值，用于从0到9的n值。输出的开头应类似上图所示

*/

double solve(int n)
{
    double val = 1;
    double mul = 1;
    for (int i = 1;i <= n; i++)
    {
        mul *= i;
    }
    val = 1 / mul;
    return val;
}


int main()
{
    double e=0;
    cout << "n e" << endl;
    cout << "- -----------" << endl;
    for (int i = 0; i <= 9; i++)
    {
        e += solve(i);
        cout << i << " " << setprecision(10) << e << endl;
    }
    return 0;
}
