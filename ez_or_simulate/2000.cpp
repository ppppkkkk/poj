#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

/*
n天总共得到多少金币，第一天得到一个，第二第三天得到分别得到两个，
第三第四第五天分别得到三个以此类推
*/

int main()
{
    int n, ans=0;
    while (cin >> n,n)
    {
        ans = 0;
        for (int i = 0, j = 1;i <= n;j++)
        {
            int  k = j;
            while (k-- && ++i <= n)
                ans += j;
        }
        cout << n << " " << ans << endl;
    }
    return 0;
}
