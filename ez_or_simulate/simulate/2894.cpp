#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>
#include <map>
using namespace std;

/*
一个键盘含'A'-'Z'26个键，每个键上都有一个状态转化功能，
默认为off，根据on状态的键的数量输出字符。
*/
int a[1001];

int main()
{
    int n;
    char c;
    int x,y;
    cin >> n;
    while (n--)
    {
        memset(a, 0, sizeof(a));
        int num;
        cin >> num;
        int max = -1;
        for (int i = 0; i < num; ++i)
        {
            cin >> c;
            cin >> x >> y;
            if (x > max)
                max = x;
            if (y > max)
                max = y;
            for (int j = x; j < y; ++j)
            {
                ++a[j];
            }
        }
        for (int i = 0; i < max; ++i)
        {
            if (a[i] == 0)
                continue;
            else
                cout << char(a[i] - 1 + 65);
        }
        cout << endl;
    }
}
