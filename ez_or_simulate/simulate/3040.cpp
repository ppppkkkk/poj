#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
using namespace std;

/*
一个人有N种不同面额的硬币，
需要每周支付至少C元，可以多给，问这些硬币可以给多少周。
*/




pair<int, int> coin[20];//first是面额，second是数目
int main()
{
    int n, c, m = 0, v, b, res = 0, allowance;
    cin >> n >> c;
    for (int i = 0;i < n;i++)
    {
        cin >> v >> b;
        if (v > c)
        {
            res += b;//金额大于c(allowance)
        }
        else {
            coin[m].first = v;
            coin[m++].second = b;
        }
    }
    sort(coin, coin + m);
    allowance = c;
    while (true) {
        for (int i = m - 1;i >= 0;i--)
        {
            if (allowance > 0 && coin[i].second > 0)
            {
                int t = min(coin[i].second, allowance / coin[i].first);
                allowance -= t * coin[i].first;
                coin[i].second -= t;
            }
        }
        for (int i = 0;i < m;i++)
        {
            if (allowance > 0 && coin[i].second > 0)
            {
                int t = min(coin[i].second, (int)ceil((double)allowance / (double)coin[i].first));
                allowance -= t * coin[i].first;
                coin[i].second -= t;
            }
        }
        if (allowance > 0)
        {
            break;
        }
        res++;
        allowance = c;
    }
    cout << res << endl;
    return 0;
}



