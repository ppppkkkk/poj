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
史努比有n个硬币，经过x次翻转之后可以让所有的硬币全部正面或者反面朝上，求x的最小值。

①如果有偶数枚硬币，则有奇数枚朝上（下）+奇数枚朝下（上）和偶数枚朝上（下）+偶数枚朝下（上）这俩种情况。
如果是前者，则史努比经过奇数次翻转就可以使全部硬币统一方向，如果是后者，则史努比经过偶数次翻转就可以使全部硬币统一方向。
②如果有奇数枚硬币，则有偶数枚朝上（下）+奇数枚朝下（上）这一种情况。那么史努比经过偶数次翻转，一定可以使得全部硬币满足目标状态。
所以来说，当n为偶数时为答案为No Solution!；当n为奇数时，答案为x = n - 1。
*/

int main()
{
    int n;
    while (cin >> n, n)
    {
        if (n & 1)
            cout << n - 1 << endl;//奇数
        else
            cout << "No Solution!" << endl;//偶数
    }

    return 0;
}
