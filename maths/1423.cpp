#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
/*
确定该数字的阶乘中的位数
Stirling公式: n! = ((2pin)(1/2))*((n/e)n); n > 3
*/



#define pi acos(-1.0)
#define e (exp(1.0))
int  Stirling(long n)  //斯特林公式
{
    return int(log10(sqrt(2.0 * pi * n)) + n * log10(n / e)) + 1;
}
int main()
{
    int n;
    cin >> n;
    while (n--) {
        long m;
        cin >> m;
        if (m == 1)
            cout << 1 << endl;
        else
            cout << Stirling(m) << endl;
    }
    return 0;
}
