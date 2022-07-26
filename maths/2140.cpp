#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/*
给出n，求一共有多少个连续的数满足加和恰好得到n
S=（a1+an）*n/2
an=a1+(n-1)*d(d位公差)
a1=(2*s+n-n*n)/2/n
*/

int main()
{
    int n, m;
    cin >> n;
    int ans = 0;
    for (int i = 1;i <= sqrt(2 * n);i++)
    {
        m = (2 * n - i * (i - 1)) / 2 / i;
        if (2 * n == (2 * m * i + i * i - i) && m > 0 && (i % 2 == 0 || (2 * m + i - 1) % 2 == 0))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
