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
给定一个六位数，选择中间四位数字，求它的平方，只保留后六位数字。
然后再选择新六位数字中间的四位数字，求这四位数字的平方，再只保留后六位数字。
这样循环下去，直到出现重复的六位数字为止。输出第一次出现循环的六位数字，循环长度和循环前总共执行的操作步数。
*/

int vis[1000010];

int main()
{
    int n;
    while (cin >> n)
    {
        memset(vis, -1, sizeof(vis));
        int i;
        vis[n] = 0;
        for (i = 1; ; ++i)
        {
            n = n / 10 % 10000;
            n *= n;
            n %= 1000000;
            if (vis[n] >= 0)
                break;
            vis[n] = i;
        }
        cout << n << ' ' << i - vis[n] << ' ' << i << endl;
    }

    return 0;
}
