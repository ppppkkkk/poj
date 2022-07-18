#include <iostream>
#include <cstdio>
using namespace std;

/*
第二类斯特林数
给出n,k,求S(n,k) mod 2。
C(z,w) = z! / [(w!) * (z-w)!]，要判断奇偶性只需要统计一下分子分母的所含的因子2的个数。
Sample Input

1
4 2
Sample Output

1

*/




int count(int n)
{
    return n == 0 ? 0 : n / 2 + count(n / 2);
}

int main()
{
    int d, n, m;
    cin >> d;
    while (d--)
    {
        cin >> n >> m;
        n -= m;
        m = (m - 1) / 2;
        if (count(n + m) == count(n) + count(m))
            cout << "1" << endl;
        else
            cout << "0" << endl;
    }
    return 0;
}
